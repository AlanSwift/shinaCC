//
// Created by Administrator on 2018/6/4/004.
//

#include "translator.h"
#include "Emitter.h"
#include <utility>


int level = 0;

void Program_::appendInst(IrInst e)
{
    assert(currentBlock);
    currentBlock->insts.push_back(e);
}

BasicBlock Program_::createBasicBlock()
{
    BasicBlock bb = new BasicBlock_();
    memset(bb, 0, sizeof(BasicBlock_));
    return bb;
}

void Program_::startBasicBlock(BasicBlock bb)
{
    assert(currentBlock);
    bblocks.push_back(currentBlock);
    currentBlock = bb;
}

Program Translator_::translate(TranslationUnitDecl start)
{
    program = new Program_();
    labelNumber = 0;
    for(auto &decl: start->declarations){
        if(decl->id == NODE_DECL_VAR){
            VarDecl decl1 = (VarDecl)decl;
            Symbol symbol = table->lookUp(decl1->name);
            program->globals.push_back(symbol);
        }
        else if(decl->id == NODE_DECL_FUNCTION){
            FunctionDecl decl1 = (FunctionDecl)decl;
            if(!decl1->stmt)
                continue;
            tmpNumber = 0;
            program->currentFunc = decl1->functionSymbol;
			printf("begin to translate %s\n", program->currentFunc->name.c_str());
			fflush(stdout);
            program->currentFunc->entryBB = program->createBasicBlock();
            program->currentFunc->exitBB = program->createBasicBlock();

			program->currentFunc->start = program->bblocks.size();
            program->currentBlock = program->currentFunc->entryBB;

			program->functionList.push_back(decl1->functionSymbol);
            translateStatement(decl1->stmt);
            program->startBasicBlock(program->currentFunc->exitBB);

			program->currentFunc->end = program->bblocks.size();
			program->bblocks.push_back(program->currentFunc->exitBB);
        }
    }
	for (auto &bb : program->bblocks) {
		//if(bb->reference > 0){
		bb->symbol = createLabel();
		printf("allocate label: %s for %p\n", bb->symbol->name.c_str(), bb);
		//}
	}
    controlFlowOptimise();
	//showProgram(start);
	FILE *fp = fopen("asm.s", "w");
	Emitter emitter = new Emitter_(fp);
	emitter->emitCode(program);
	fclose(fp);
    return program;
}

Symbol Translator_::translateFunctionCall(CallExpr expr)
{
    Symbol faddr,recv;


    faddr = this->translateExpression(expr->func);//may be function pointer

    vector<pair<Symbol,Type> > *args = new vector<pair<Symbol, Type> >();

    for(auto &e:expr->args)
    {
        pair<Symbol,Type> arg;
        arg.first = this->translateExpression(e);
        arg.second=e->type;
        args->push_back(arg);
    }


    recv = NULL;
	Type t = expr->func->type;
	if (expr->func->type->id == CONST_TYPE_POINTER) {
		t = ((PointerType)t)->pointTo;
	}
	//t->show();
	assert(t->id == CONST_TYPE_FUNC);
	
    if(t->id == CONST_TYPE_FUNC && dynamic_cast<FunctionType>(t)->returnType != BuiltinType_::voidType) {
        recv = this->createTemp(dynamic_cast<FunctionType>(t)->returnType);
    }
    this->generateFunctionCall(expr->type, recv, faddr, args);
    return recv;

}

Symbol Translator_::translateBinaryExpr(BinaryOpExpr expr)
{
	//printf("-2: =========================???????????????????????????????\n");
    if(expr->operator_ == OP_BINARY_COMMA)
        return translateCommaExpr(expr);
    if(expr->operator_ == OP_BINARY_LOGICAL_AND
       || expr->operator_ == OP_BINARY_LOGICAL_OR || isRelationalOp(expr->operator_))
        return translateBranchExpr(expr);
	//printf("-1: =========================???????????????????????????????\n");
    Symbol src1, src2;
    src1 = translateExpression(expr->left);
    src2 = translateExpression(expr->right);
    if(expr->operator_ == OP_BINARY_OR)
        return simplify(expr->type, BOR, src1, src2);
    if(expr->operator_ == OP_BINARY_XOR)
        return simplify(expr->type, BXOR, src1, src2);
    if(expr->operator_ == OP_BINARY_AND)
        return simplify(expr->type, BAND, src1, src2);
    if(expr->operator_ == OP_BINARY_SHIFTLEFT)
        return simplify(expr->type, LSH, src1, src2);
    if(expr->operator_ == OP_BINARY_SHIFTRIGHT)
        return simplify(expr->type, RSH, src1, src2);
    if(expr->operator_ == OP_BINARY_ADD)
        return simplify(expr->type, ADD, src1, src2);
    if(expr->operator_ == OP_BINARY_MINUS)
        return simplify(expr->type, SUB, src1, src2);
    if(expr->operator_ == OP_BINARY_MULTIPLY)
        return simplify(expr->type, MUL, src1, src2);
    if(expr->operator_ == OP_BINARY_DIV)
        return simplify(expr->type, DIV, src1, src2);
    if(expr->operator_ == OP_BINARY_MOD)
        return simplify(expr->type, MOD, src1, src2);
	assert(0);
}

Symbol Translator_::translateBranchExpr(Expr expr)
{
    BasicBlock nextBB, trueBB, falseBB;
    Symbol t;
    t = createTemp(expr->type);
    nextBB = program->createBasicBlock();
    trueBB = program->createBasicBlock();
    falseBB = program->createBasicBlock();

    translateBranch(expr, trueBB, falseBB);

    program->startBasicBlock(falseBB);
    generateMove(expr->type, t, IntConstant(0));
    generateJump(nextBB);

    program->startBasicBlock(trueBB);
    generateMove(expr->type, t, IntConstant(1));

    program->startBasicBlock(nextBB);

    return t;
}

Symbol Translator_::translateUnaryExpr(UnaryOpExpr expr)
{
    if(expr->operator_ == OP_UNARY_DOUBLEADD || expr->operator_ == OP_UNARY_DOUBLEMINUS)
        return translateIncrement(expr);
    if(expr->operator_ == OP_UNARY_LOGICAL_NOT)
        return translateBranchExpr(expr);
    Symbol src = translateExpression(expr->expr);
    switch (expr->operator_){
        case OP_UNARY_CAST:
            assert(0);
            return NULL;
        case OP_UNARY_POSITIVE:
            return src;
        case OP_UNARY_NEGATIVE:
			if (src->kind == SK_Constant) {
				if (isIntegType(src->type))
					src->valueUnion.i[0] = -src->valueUnion.i[0];
				else
					src->valueUnion.d = -src->valueUnion.d;
				return src;
			}
            return simplify(expr->type, NEG, src, NULL);
        case OP_UNARY_STAR:
            return deReference(expr->type, src);
        case OP_UNARY_AND:
            return addressOf(src);
		case OP_UNARY_NOT:
			return simplify(expr->type, BCOM, src, NULL);
        default:
            assert(0);
            return NULL;
    }
}

Symbol Translator_::translateIncrement(UnaryOpExpr expr)
{
	//if()
}

Symbol Translator_::translateConditionalExpr(ConditionalExpr expr)
{
	Symbol t, t1, t2;
	BasicBlock trueBlock, falseBlock, nextBlock;

	assert(expr->type != BuiltinType_::voidType);
	t = createTemp(expr->type);

	falseBlock = program->createBasicBlock();
	trueBlock = program->createBasicBlock();
	nextBlock = program->createBasicBlock();

	translateBranch(expr->condition, trueBlock, falseBlock);

	program->startBasicBlock(falseBlock);
	t1 = translateExpression(expr->false_);
	assert(t1 != NULL);
	generateMove(expr->type, t, t1);
	generateJump(nextBlock);

	program->startBasicBlock(trueBlock);
	t2 = translateExpression(expr->true_);
	assert(t2 != NULL);
	generateMove(expr->type, t, t2);

	program->startBasicBlock(nextBlock);
	return t;
}

Symbol Translator_::translateAssignmentExpr(AssignExpr expr)
{
	//printf("0: =========================???????????????????????????????\n");
    Symbol dst, src;
	VariableSymbol tmp;
	dst = translateExpression(expr->var);
	src = translateExpression(expr->expr);
	if (expr->operator_ != OP_ASSIGN_EQ) {
		int opcode;
		switch (expr->operator_) {
		case OP_ASSIGN_EQ_ADD:
			opcode = ADD;
			break;
		case OP_ASSIGN_EQ_MINUS:
			opcode = SUB;
			break;
		case OP_ASSIGN_EQ_MULTIPLY:
			opcode = MUL;
			break;
		case OP_ASSIGN_EQ_DIV:
			opcode = DIV;
			break;
		case OP_ASSIGN_EQ_MOD:
			opcode = MOD;
			break;
		case OP_ASSIGN_EQ_AND:
			opcode = BAND;
			break;
		case OP_ASSIGN_EQ_XOR:
			opcode = BXOR;
			break;
		case OP_ASSIGN_EQ_OR:
			opcode = BOR;
			break;
		case OP_ASSIGN_EQ_SHIFTLEFT:
			opcode = LSH;
			break;
		case OP_ASSIGN_EQ_SHIFTRIGHT:
			opcode = RSH;
			break;
		default:
			assert(0);
			break;
		}
		Symbol tmp;
		tmp = simplify(expr->type, opcode, dst, src);
		src = tmp;
	}
	//printf("2: =========================???????????????????????????????\n");
	//printf("src = %08x, dst = %08x\n", src, dst);
	if (dst->kind == SK_Temp && (tmp = dynamic_cast<VariableSymbol>(dst)) && tmp->def->op == DEREF) {
		Symbol addr = tmp->def->src1;
		generateIndirectMove(expr->type, addr, src);
		dst = deReference(expr->type, addr);
	}
	else {
		//printf("3: =========================???????????????????????????????\n");
        generateMove(expr->type, dst, src);
    }
		
	return dst;
}

Symbol Translator_::translateCommaExpr(BinaryOpExpr expr)
{
	translateExpression(expr->left);
	return translateExpression(expr->right);
}

Symbol Translator_::translateCastExpr(Expr expr)
{
    if(expr->id == NODE_EXP_IMPLICITCAST){
        ImplicitCastExpr expr1 = (ImplicitCastExpr)expr;
        Symbol src = translateExpression(expr1->expr);
        return translateCast(expr1->type, expr1->expr->type, src);
    }
    else{
        assert(expr->id == NODE_EXP_CSTYLECAST);
        return NULL;
    }
}

Symbol Translator_::translatePrimaryExpr(Expr expr) //id, str, int, float, parentheses
{
    if(expr->isConstant() && expr->id != NODE_EXP_STRLITERAL){
        if(expr->isIntConstant())
            return IntConstant(expr->valueUnion.i[0]);
        return DoubleConst(expr->valueUnion.d);
    }
	if (expr->id == NODE_EXP_STRLITERAL || expr->type->id == CONST_TYPE_ARRAY) {
		if (expr->id == NODE_EXP_STRLITERAL) {
			program->globals.push_back((Symbol)(expr->valueUnion.p));
		}
		return addressOf((Symbol)(expr->valueUnion.p));
	}
    assert(expr->id != NODE_EXP_STRLITERAL);//TODO:
    if(expr->type->id == CONST_TYPE_FUNC){
		return (Symbol)(expr->valueUnion.p);
    }
	assert(expr->valueUnion.p);
    return (Symbol)expr->valueUnion.p;
}

Symbol Translator_::translateArrayIndex(ArraySubscriptExpr expr)
{
	Symbol addr, dst, voff = NULL;
	int coff = 0;

	ArraySubscriptExpr p = expr;

	voff = translateExpression(p->offset);
	addr = translateExpression(p->array);
	if (expr->type->id == CONST_TYPE_ARRAY)
		return simplify(addr->type, ADD, addr, voff);
	return deReference(expr->type, simplify(addr->type, ADD, addr, voff));
}

void Translator_::translateExprStmt(ExprStmt stmt)
{
    assert(stmt->expr);
    translateExpression(stmt->expr);
}

void Translator_::translateLabelStmt(LabelStmt stmt)
{
    //TODO: create basic block for label
    if(stmt->label){
        if(stmt->label->respBB)
            stmt->label->respBB = program->createBasicBlock();
        program->startBasicBlock(stmt->label->respBB);
    }
    translateStatement(stmt->stmt);
}

void Translator_::translateCaseStmt(CaseStmt stmt)
{
    //TODO:
    translateStatement(stmt->stmt);
}

void Translator_::translateDefaultStmt(DefaultStmt stmt)
{
    //TODO:
}

void Translator_::translateIfStmt(IfStmt stmt)
{
    BasicBlock nextBB, trueBB, falseBB;
    nextBB = program->createBasicBlock();
    trueBB = program->createBasicBlock();
    if(stmt->else_ == NULL){
        translateBranch(notExpr(stmt->condition), nextBB, trueBB);
        program->startBasicBlock(trueBB);
        translateStatement(stmt->if_);
    }
    else{
        falseBB = program->createBasicBlock();
        translateBranch(notExpr(stmt->condition), falseBB, trueBB);

        program->startBasicBlock(trueBB);
        translateStatement(stmt->if_);
        generateJump(nextBB);

        program->startBasicBlock(falseBB);
        translateStatement(stmt->else_);
    }
    program->startBasicBlock(nextBB);
}

void Translator_::translateWhileStmt(WhileStmt stmt)
{
    stmt->loopBB = program->createBasicBlock();
    stmt->contBB = program->createBasicBlock();
    stmt->nextBB = program->createBasicBlock();

    generateJump(stmt->contBB);

    program->startBasicBlock(stmt->loopBB);
    translateStatement(stmt->stmt);

    program->startBasicBlock(stmt->contBB);
    translateBranch(stmt->expr, stmt->loopBB, stmt->nextBB);

    program->startBasicBlock(stmt->nextBB);
}

void Translator_::translateDoStmt(DoStmt stmt)
{
    stmt->loopBB = program->createBasicBlock();
    stmt->contBB = program->createBasicBlock();
    stmt->nextBB = program->createBasicBlock();

    program->startBasicBlock(stmt->loopBB);
    translateStatement(stmt->stmt);

    program->startBasicBlock(stmt->contBB);
    translateBranch(stmt->expr, stmt->loopBB, stmt->nextBB);

    program->startBasicBlock(stmt->nextBB);
}

void Translator_::translateForStmt(ForStmt stmt)
{
    stmt->loopBB=program->createBasicBlock();
    stmt->contBB=program->createBasicBlock();
    stmt->testBB=program->createBasicBlock();
    stmt->nextBB=program->createBasicBlock();

    if(stmt->init)
    {
        this->translateExpression(stmt->init);
    }
    this->generateJump(stmt->testBB);


    program->startBasicBlock(stmt->loopBB);
    this->translateStatement(stmt->stmt);

    program->startBasicBlock(stmt->contBB);
    if(stmt->next)
    {
        this->translateExpression(stmt->next);
    }

    program->startBasicBlock(stmt->testBB);
    if(stmt->condition)
    {
        this->translateBranch(stmt->condition,stmt->loopBB,stmt->nextBB);
    }
    else{
        this->generateJump(stmt->loopBB);
    }
    program->startBasicBlock(stmt->nextBB);


}

void Translator_::translateGotoStmt(GoToStmt stmt)
{
	/*GOTO*/
	//TODO:
    if(stmt->label->respBB==NULL)
    {
        stmt->label->respBB=program->createBasicBlock();
    }
    this->generateJump(stmt->label->respBB);
    program->startBasicBlock(program->createBasicBlock());

}

void Translator_::translateBreakStmt(BreakStmt stmt)
{
    switch(stmt->target->id)
    {
        case NODE_STM_SWITCH:
        {
            this->generateJump(((SwitchStmt)(stmt->target))->nextBB);
            break;
        }
        case NODE_STM_FOR:
        {
            this->generateJump(((ForStmt)(stmt->target))->nextBB);
            break;
        }
        case NODE_STM_WHILE:
        {
            this->generateJump(((WhileStmt)(stmt->target))->nextBB);
            break;
        }
        case NODE_STM_DO:
        {
            this->generateJump(((DoStmt)(stmt->target))->nextBB);
            break;
        }
    }
    program->startBasicBlock(program->createBasicBlock());
    
}

void Translator_::translateContinueStmt(ContinueStmt stmt)
{
    switch(stmt->target->id)
    {
        case NODE_STM_FOR:
        {
            this->generateJump(dynamic_cast<ForStmt>(stmt->target)->contBB);
            break;
        }
        case NODE_STM_WHILE:
        {
            this->generateJump(dynamic_cast<WhileStmt>(stmt->target)->contBB);
            break;
        }
        case NODE_STM_DO:
        {
            this->generateJump(dynamic_cast<DoStmt>(stmt->target)->contBB);
            break;
        }
    }
    program->startBasicBlock(program->createBasicBlock());

}

void Translator_::translateReturnStmt(ReturnStmt stmt)
{
    if(stmt->result)
    {
        this->generateReturn(stmt->result->type,
            this->translateExpression(stmt->result)
        );
    }
    this->generateJump(program->currentFunc->exitBB);
    //program->startBasicBlock(program->createBasicBlock());

}

void Translator_::translateCompoundStmt(CompoundStmt stmt)
{
    level++;
	if (level == 1) {
		for (auto &v : stmt->locals)
			program->currentFunc->locals.push_back(v);
		//printf("??????????????????????????????????????????????????????????????\n");
	}
    for(auto &s: stmt->stmtList){
        if(s->id == NODE_STM_DECL){
            VarDecl decl = (VarDecl)s;
            //TODO: initialize
        }
        else{
            translateStatement(s);
        }
    }
    level--;
}

void Translator_::translateSwitchStmt(SwitchStmt stmt)
{

}

void Translator_::translateBranch(Expr expr, BasicBlock trueBlock, BasicBlock falseBlock)
{
    BasicBlock testBlock;// now -> trueBlock -> falseBlock
    Symbol src1, src2;
    int map[6] ={
         JGE, JL, JG, JLE, JE, JNE
    };
    if(expr->id == NODE_EXP_BINARY){
		//printf("********************************here is a binary!!!\n");
        BinaryOpExpr expr1 = (BinaryOpExpr)expr;
        switch (expr1->operator_){
            case OP_BINARY_LOGICAL_AND:
                testBlock = program->createBasicBlock();
                translateBranch(notExpr(expr1->left), falseBlock, testBlock);
                program->startBasicBlock(testBlock);
                translateBranch(expr1->right, trueBlock, falseBlock);
                break;
            case OP_BINARY_LOGICAL_OR:
                testBlock = program->createBasicBlock();
                translateBranch(expr1->left, trueBlock, testBlock);
                program->startBasicBlock(testBlock);
                translateBranch(expr1->right, trueBlock, falseBlock);
                break;
            case OP_BINARY_BE: // >=
            case OP_BINARY_ST: // <
            case OP_BINARY_GT: // >
            case OP_BINARY_SE: // <=
            case OP_BINARY_EQ:
            case OP_BINARY_NEQ:
                src1 = translateExpression(expr1->left);
                src2 = translateExpression(expr1->right);
                generateBranch(expr1->left->type, trueBlock, map[expr1->operator_ - OP_BINARY_GT], src1, src2);
                break;
			default: assert(0); break;
        }
		return;
    }
    if(expr->id == NODE_EXP_UNARY){ //!a
		//printf("********************************here is a unary!!!\n");
        UnaryOpExpr expr1 = (UnaryOpExpr)expr;
        if(expr1->operator_ == OP_UNARY_LOGICAL_NOT){
            src1 = translateExpression(expr1->expr);
            Type type = expr1->expr->type;
            if(type->id < CONST_TYPE_BUILTIN_INT){
                src1 = translateCast(BuiltinType_::intType, expr1->expr->type, src1);
                type = BuiltinType_::intType;
            }
            generateBranch(type, trueBlock, JZ, src1, NULL);
        }
		return;
    }
    if(expr->isConstant()){ //1
		//printf("********************************here is a constant!!!\n");
        if(!(expr->valueUnion.i[0] == 0 && expr->valueUnion.i[1] == 0))
            generateJump(trueBlock);
    }
    else{ //a
		//printf("********************************here is an variable!!!\n");
        src1 = translateExpression(expr);
        if (src1->kind  == SK_Constant) {
            if (!(src1->valueUnion.i[0] == 0 && src1->valueUnion.i[1] == 0))
                generateJump(trueBlock);
        }
        else{
            Type type = expr->type;
            if(type->id < CONST_TYPE_BUILTIN_INT){
                src1 = translateCast(BuiltinType_::intType, type, src1);
                type = BuiltinType_::intType;
            }
            generateBranch(type, trueBlock, JNZ, src1, NULL);
        }
    }
}

Expr Translator_::notExpr(Expr expr)
{
    if(expr->id == NODE_EXP_BINARY){
        BinaryOpExpr expr1 = (BinaryOpExpr)expr;
        switch (expr1->operator_){
            case OP_BINARY_LOGICAL_AND:
                expr1->operator_ = OP_BINARY_LOGICAL_OR;
                expr1->left = notExpr(expr1->left);
                expr1->right = notExpr(expr1->right);
                return expr;
            case OP_BINARY_LOGICAL_OR:
                expr1->operator_ = OP_BINARY_LOGICAL_AND;
                expr1->left = notExpr(expr1->left);
                expr1->right = notExpr(expr1->right);
                return expr;
            case OP_BINARY_BE: // >=
                expr1->operator_ = OP_BINARY_ST;
                return expr;
            case OP_BINARY_ST: // <
                expr1->operator_ = OP_BINARY_BE;
                return expr;
            case OP_BINARY_GT: // >
                expr1->operator_ = OP_BINARY_SE;
                return expr;
            case OP_BINARY_SE: // <=
                expr1->operator_ = OP_BINARY_GT;
                return expr;
            case OP_BINARY_EQ:
                expr1->operator_ = OP_BINARY_NEQ;
                return expr;
            case OP_BINARY_NEQ:
                expr1->operator_ = OP_BINARY_EQ;
                return expr;
            default: break;
        }
    }
    else if(expr->id == NODE_EXP_UNARY){
        UnaryOpExpr expr1 = (UnaryOpExpr)expr;
        if(expr1->operator_ == OP_UNARY_LOGICAL_NOT)
            return expr1->expr;
    }
	else if (expr->isIntConstant()) {
		if (expr->valueUnion.i[0] || expr->valueUnion.i[1]) {
			expr->valueUnion.i[0] = 0;
			expr->valueUnion.i[1] = 0;
		}
		else {
			expr->valueUnion.i[0] = 1;
			expr->valueUnion.i[1] = 0;
		}
		return expr;
	}
    UnaryOpExpr expr2 = new UnaryOpExpr_(expr, OP_UNARY_LOGICAL_NOT, false);
    expr2->type = BuiltinType_::intType;
    return expr2;
}

void Translator_::translateStatement(Stmt stmt)
{
    switch (stmt->id){
        case NODE_STM_COMPOUND:
            translateCompoundStmt((CompoundStmt)stmt);
            break;
        case NODE_STM_EXPR:
            translateExprStmt((ExprStmt)stmt);
            break;
        case NODE_STM_DECL:
            //TODO
            break;
        case NODE_STM_SWITCH:
            translateSwitchStmt((SwitchStmt)stmt);
            break;
        case NODE_STM_CASE:
            translateCaseStmt((CaseStmt)stmt);
            break;
        case NODE_STM_DEFAULT:
            translateDefaultStmt((DefaultStmt)stmt);
            break;
        case NODE_STM_RETURN:
            translateReturnStmt((ReturnStmt)stmt);
            break;
        case NODE_STM_IF:
            translateIfStmt((IfStmt)stmt);
            break;
        case NODE_STM_WHILE:
            translateWhileStmt((WhileStmt)stmt);
            break;
        case NODE_STM_DO:
            translateDoStmt((DoStmt)stmt);
            break;
        case NODE_STM_FOR:
            translateForStmt((ForStmt)stmt);
            break;
        case NODE_STM_LABEL:
            translateLabelStmt((LabelStmt)stmt);
            break;
        case NODE_STM_CONTINUE:
            translateContinueStmt((ContinueStmt)stmt);
            break;
        case NODE_STM_BREAK:
            translateBreakStmt((BreakStmt)stmt);
            break;
        case NODE_STM_NULL:
            break;
        case NODE_STM_GOTO:
            translateGotoStmt((GoToStmt)stmt);
            break;
        default:
            break;
    }
}

Symbol Translator_::translateExpression(Expr expr)
{
	//printf("begin translate expression!!!\n");
    switch (expr->id){
        case NODE_EXP_PAREN:
            return translateExpression(((ParenExpr)expr)->expr);
        case NODE_EXP_INTLITERAL:
        case NODE_EXP_FLOATLITERAL: case NODE_EXP_STRLITERAL:
        case NODE_EXP_DECLREF: case NODE_EXP_CHARLITERAL:
            return translatePrimaryExpr(expr);
        case NODE_EXP_BINARY:
			//printf("begin translate binary expression!!!\n");
            return translateBinaryExpr((BinaryOpExpr)expr);
        case NODE_EXP_UNARY:
            return translateUnaryExpr((UnaryOpExpr)expr);
        case NODE_EXP_CONDITIONAL:
            return translateConditionalExpr((ConditionalExpr)expr);
        case NODE_EXP_ASSIGN:
            return translateAssignmentExpr((AssignExpr)expr);
        case NODE_EXP_CALL:
            return translateFunctionCall((CallExpr)expr);
        case NODE_EXP_ARRAYSUBSCRIPT:
            return translateArrayIndex((ArraySubscriptExpr)expr);
        case NODE_EXP_IMPLICITCAST: case NODE_EXP_CSTYLECAST:
            return translateCastExpr(expr);
        default:
            return NULL;
    }
}

Symbol Translator_::addressOf(Symbol p)
{
    
	if (p->kind == SK_Temp && dynamic_cast<VariableSymbol>(p)->def->op == DEREF)
	{
		Symbol t=dynamic_cast<VariableSymbol>(p)->def->src1;
		return t;
	}

	p->addressed = 1;

	if (p->kind == SK_Variable)
	{
		TrackValueChange(p);
	}
	Symbol t=TryAddValue(new PointerType_(p->type), ADDR, p, NULL);
	//debugSymbol(t);
	return t; 
}

Symbol Translator_::TryAddValue(Type ty, int op, Symbol src1, Symbol src2)
{
	int h = ((unsigned int)(long long)src1 + (unsigned int)(long long)src2 + op) & 15;

	valueDef def = program->currentFunc->valNumTable[h];

	Symbol t;

	if (op != ADDR && (src1->addressed || (src2 && src2->addressed)))
		goto new_temp;

	while (def)
	{
		if (def->op == op && (def->src1 == src1 && def->src2 == src2))
			break;
		def = def->link;
	}

	if (def && def->ownBB == program->currentBlock && def->dst != NULL)
		return def->dst;

new_temp:
	t = createTemp(ty);
	generateAssign(ty, t, op, src1, src2);

    def = dynamic_cast<VariableSymbol>(t)->def;

	def->link = program->currentFunc->valNumTable[h];
	program->currentFunc->valNumTable[h] = def;

	return t;
}

 Symbol Translator_::deReference(Type type,Symbol addr)
{
    Symbol tmp;

	if (addr->kind == SK_Temp && dynamic_cast<VariableSymbol>(addr)->def->op == ADDR)
	{
		return dynamic_cast<VariableSymbol>(addr)->def->src1;
	}

	tmp = createTemp(type);
	generateAssign(type, tmp, DEREF, addr, NULL);
	return tmp;
}

bool Translator_::isRealType(Type type)
{
    return !type && type->id== CONST_TYPE_BUILTIN &&
           (dynamic_cast<BuiltinType> (type)->builtinType == CONST_TYPE_BUILTIN_FLOAT ||
            dynamic_cast<BuiltinType> (type)->builtinType == CONST_TYPE_BUILTIN_DOUBLE ||
            dynamic_cast<BuiltinType> (type)->builtinType == CONST_TYPE_BUILTIN_LONG_DOUBLE
    );
}

bool Translator_::isIntegType(Type c)
{
    return !c && c->id== CONST_TYPE_BUILTIN &&
            (
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_CHAR ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_UNSIGNED_CHAR ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_SHORT ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_UNSIGNED_SHORT ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_INT ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_UNSIGNED_INT ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_UNSIGNED ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_LONG ||
                dynamic_cast<BuiltinType>(c)->builtinType==CONST_TYPE_BUILTIN_UNSIGNED_LONG
                
            );
}

bool Translator_::isPointerType(Type c)
{
    return !c && (c->id==CONST_TYPE_POINTER);
}

int Translator_::powerOf2(unsigned int u)
{
	int n;

	if (u > 1 && (u &(u - 1)) == 0)
	{
		for (n = 0; u; u >>= 1, n++)
		{
			if (u & 1)
				return n;
		}
	}
	return 0;
}


Symbol Translator_::simplify(Type ty, int opcode, Symbol src1, Symbol src2)
{
    VariableSymbol t;
	Symbol p1, p2;
	int c1, c2;

	if (isRealType(ty))
		goto add_value;

	if (src2 == NULL || (src2->kind != SK_Constant && opcode != SUB))
		goto add_value;

	switch (opcode)
	{
	case ADD:
		// a + 0 = a
		if (src2->valueUnion.i[0] == 0)
			return src1;

		// a + c1 + c2 = a + (c1 + c2)
		// a - c1 + c2 = a + (-c1 + c2)
		p1 = src1; c1 = 0;
		if (src1->kind == SK_Temp)
		{
			t = dynamic_cast<VariableSymbol>(src1);

			if (t->def->src2 && t->def->src2->kind == SK_Constant && 
			    (t->def->op == ADD || t->def->op == SUB))
			{
				p1 = t->def->src1;
				c1 = (t->def->op == ADD ? 1 : -1) * t->def->src2->valueUnion.i[0];
			}

		}
		if (c1 != 0)
		{
			src1 = p1;
			src2 = IntConstant(c1 + src2->valueUnion.i[0]);
		}
		break;

	case SUB:
		// a - 0 = a
		if (src2->kind == SK_Constant && src2->valueUnion.i[0] == 0)
			return src1;

		// put source operand into v + c format (v maybe NULL, c maybe 0)
		p1 = src1; c1 = 0;
		if (src1->kind == SK_Temp)
		{
			t = dynamic_cast<VariableSymbol>(src1);
			if (t->def->src2 && t->def->src2->kind == SK_Constant && 
			    (t->def->op == ADD || t->def->op == SUB))
			{
				p1 = t->def->src1;
				c1 = (t->def->op == ADD ? 1 : -1) * t->def->src2->valueUnion.i[0];
			}
		}
		else if (src1->kind == SK_Constant)
		{
			p1 = NULL;
			c1 = src1->valueUnion.i[0];
		}
		p2 = src2; c2 = 0;
		if (src2->kind == SK_Temp)
		{
			t = dynamic_cast<VariableSymbol>(src2);
			if (t->def->src2 && t->def->src2->kind == SK_Constant && 
			    (t->def->op == ADD || t->def->op == SUB))
			{
				p2 = t->def->src1;
				c2 = (t->def->op == ADD ? 1 : -1) * t->def->src2->valueUnion.i[0];
			}
		}
		else if (src2->kind == SK_Constant)
		{
			p2 = NULL;
			c2 = src2->valueUnion.i[0];
		}

		if (p1 == p2)
		{
			// (a + c1) - (a + c2) = c1 - c2
			return IntConstant(c1 - c2);
		}
		else if (p1 == NULL)
		{
			// c1 - (a + c2) = (c1 - c2) - a
			src1 = IntConstant(c1 - c2);
			src2 = p2;
		}
		else if (p2 == NULL)
		{
			// (a + c1) - c2 = a + (c1 - c2)
			src1 = p1;
			opcode = ADD;
			src2 = IntConstant(c1 - c2);
		}
		break;

	case MUL:
	case DIV:
		// a * 1 = a; a / 1 = a;
		if (src2->valueUnion.i[0] == 1)
			return src1;

		// a * 2 power of n = a >> n
		c1 = powerOf2(src2->valueUnion.i[0]);
		if (c1 != 0)
		{
			src2 = IntConstant(c1);
			opcode = opcode == MUL ? LSH : RSH;
        }
		break;

	case MOD:
		// a % 1 = 0
		if (src2->valueUnion.i[0] == 1)
			return IntConstant(0);

		// a % 2 power of n = a & (2 power of n - 1)
		c1 = powerOf2(src2->valueUnion.i[0]);
		if (c1 != 0)
		{
			src2 = IntConstant(src2->valueUnion.i[0] - 1);
			opcode = BAND;
		}
		break;

	case LSH:
	case RSH:
		// a >> 0 = a << 0 = a
		if (src2->valueUnion.i[0] == 0)
			return src1;
		break;

	case BOR:
		// a | 0 = a; a | -1 = -1
		if (src2->valueUnion.i[0] == 0)
			return src1;
		if (src2->valueUnion.i[0] == -1)
			return src2;
		break;

	case BXOR:
		// a ^ 0 = a
		if (src2->valueUnion.i[0] == 0)
			return src1;
		break;

	case BAND:
		// a & 0 = 0, a & -1 = a
		if (src2->valueUnion.i[0] == 0)
			return IntConstant(0);
		if (src2->valueUnion.i[0] == -1)
			return src1;
		break;

	default:
		break;
	}

add_value:
	return TryAddValue(ty, opcode, src1, src2);
}


Symbol Translator_::offset(Type ty, Symbol addr, Symbol voff, int coff)
{
	if (voff != NULL)
	{
		voff = simplify(new PointerType_(NULL), ADD, voff, IntConstant(coff));
		addr = simplify(new PointerType_(NULL), ADD, addr, voff);
		return deReference(ty, addr);
	}

	if (addr->kind == SK_Temp && dynamic_cast<VariableSymbol>(addr)->def->op == ADDR)
	{
		return createOffset(ty, dynamic_cast<VariableSymbol>(addr)->def->src1, coff);
	}

	return deReference(ty, simplify(new PointerType_(NULL), ADD, addr, IntConstant(coff)));

}


Symbol Translator_::createOffset(Type ty, Symbol base, int coff)
{
	VariableSymbol p;

	if (coff == 0)
		return base;

	p=new VariableSymbol_();

	if (base->kind == SK_Offset)
	{
		coff += dynamic_cast<VariableSymbol>(base)->offset;
		base = base->link;
	}
	p->addressed = 1;
	p->kind = SK_Offset;
	p->type = ty;
	p->link = base;
	p->offset = coff;
    p->name=base->name+"["+ to_string(coff)+"]";
    base->ref++;
	return dynamic_cast<Symbol>(p);
}


void Translator_::controlFlowOptimise()
{
    hash.clear();
    memset(isref,0,sizeof(isref));
    int startIndex;
    pair<BasicBlock,BasicBlock>pos[1000];
    for(startIndex=0;startIndex<program->functionList.size();startIndex++)
    {
        FunctionSymbol fsym=program->functionList[startIndex];
        BasicBlock startblock=program->bblocks[fsym->start];
        BasicBlock endblock=program->bblocks[fsym->end];
        pos[startIndex].first=startblock;
        pos[startIndex].second=endblock;
        checkBasicBlock(fsym->start,fsym->exitBB);
        isref[fsym->start]=1;
        isref[fsym->end]=1;
    }
    vector<BasicBlock>after;
    for(int i=0;i<program->bblocks.size();i++)
    {
        if(isref[i])
        {
            after.push_back(program->bblocks[i]);
        }
    }
    program->bblocks=after;
    for(startIndex=0;startIndex<program->functionList.size();startIndex++)
    {
        FunctionSymbol fsym=program->functionList[startIndex];
        auto newIndex=find(program->bblocks.begin(),
            program->bblocks.end(),pos[startIndex].first
        );
        int nPosition = distance(program->bblocks.begin(),newIndex);  
        
        fsym->start=nPosition;
        newIndex=find(program->bblocks.begin(),
            program->bblocks.end(),pos[startIndex].second
        );
        nPosition = distance(program->bblocks.begin(),newIndex); 
        fsym->end=nPosition;
    }




}
void Translator_::checkBasicBlock(int index,BasicBlock exit)
{
    if(hash[index]==1)
    {
        return;
    }
    hash[index]=1;
    BasicBlock bb=program->bblocks[index];
    if(!(bb->insts.size()))
    {
        return;
    }
    IrInst lastir=bb->insts[bb->insts.size()-1];
    switch (lastir->opcode) 
    {
        case RET:
            return;
		case JE:
		case JNE:
		case JG:
		case JL:
		case JGE:
		case JLE:
		case JZ:
		case JNZ:
		case JMP:{
            BasicBlock to=(BasicBlock)(lastir->opds[0]);
            auto newIndex=find(program->bblocks.begin(),
                program->bblocks.end(),to
            );
            int nPosition = distance(program->bblocks.begin(),newIndex);  
            int toIndex1=findBasicBlockNotEmpty(
                program->bblocks,nPosition,exit
            );
            linkBasicBlock(bb,program->bblocks[toIndex1]);
            int toIndex2=findBasicBlockNotEmpty(program->bblocks,index+1,exit);
            //linkBasicBlock(bb,program->bblocks[toIndex2]);

            checkBasicBlock(toIndex1,exit);
            checkBasicBlock(toIndex2,exit);
            isref[index]=1;
            isref[toIndex1]=1;
            isref[toIndex2]=1;
            cout<<"ref: "<<index<<" "<<toIndex1<<" "<<toIndex2<<endl;
            break;
            }

        default:
            int toIndex3=findBasicBlockNotEmpty(program->bblocks,index+1,exit);
            linkBasicBlock(bb,program->bblocks[toIndex3]);
            checkBasicBlock(toIndex3,exit);
            isref[index]=1;
            isref[toIndex3]=1;
            cout<<"ref: "<<index<<" "<<toIndex3<<endl;
            break;
	}
}


void Translator_::linkBasicBlock(BasicBlock from,BasicBlock to)
{
    assert(from->insts.size());
    IrInst lastir=from->insts[from->insts.size()-1];
    switch (lastir->opcode) 
    {
		case JE:
		case JNE:
		case JG:
		case JL:
		case JGE:
		case JLE:
		case JZ:
		case JNZ:
		case JMP:
            lastir->opds[0] = (Symbol)to;			
            break;
	}

}
int Translator_::findBasicBlockNotEmpty(vector<BasicBlock>&bbs,int from,BasicBlock exit)
{
    for(int i=from;i<bbs.size();i++)
    {
        if(bbs[i]==exit)
        {
            return i;
        }
        if(!bbs[i]->insts.empty())
        {
            return i;
        }
        if(bbs[i]->symbol->name.size()<6)
        {
            continue;
        }
        if(bbs[i]->symbol->name.substr(0,6)!=string("label_"))
        {
            return i;
        }
    }
    return bbs.size()-1;
}

void Translator_::variableOptimise()
{
    for(int i=0;i<program->bblocks.size();i++)
    {
        BasicBlock bb=program->bblocks[i];
        eliminateBlockTemp(bb);

    }
}

void Translator_::eliminateBlockTemp(BasicBlock bb)
{
    if(bb->insts.size()==0)  return;
    int preSize=bb->insts.size();
    map<Symbol,int> use;
    while(bb->insts.size()!=preSize)
    {
        use.clear();
        for(int i=0;i<bb->insts.size();i++)
        {
            IrInst ir=bb->insts[i];
            switch (ir->opcode) {
                case BOR:
                case BXOR:
                case BAND:
                case LSH:
                case RSH:
                case ADD:
                case SUB:
                case MUL:
                case DIV:
                case MOD:
                    //fprintf(stdout, "%s = %s %s %s", DST->name.c_str(), SRC1->name.c_str(), opCodeNames[op], SRC2->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    if(ir->opds[2]->kind==SK_Temp)
                    {
                        use[ir->opds[2]]=1;
                    }

                    break;
                case INC:
                case DEC:
                    //fprintf(stdout, "%s%s", opCodeNames[op], DST->name.c_str());
                    
                    break;
                case BCOM:
                case NEG:
                case ADDR:
                case DEREF:
                    //fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    
                    break;
                case MOV:
                    //fprintf(stdout, "%s = %s", DST->name.c_str(), SRC1->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    
                    break;
                case IMOV:
                    //fprintf(stdout, "*%s = %s", DST->name.c_str(), SRC1->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    
                    break;
                case JE:
                case JNE:
                case JG:
                case JL:
                case JGE:
                case JLE:
                    //fprintf(stdout, "if (%s %s %s) goto %s", SRC1->name.c_str(), opCodeNames[op],
                    //    SRC2->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    if(ir->opds[2]->kind==SK_Temp)
                    {
                        use[ir->opds[2]]=1;
                    }
                    break;
                case JZ:
                    //fprintf(stdout, "if (! %s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    
                    break;
                case JNZ:
                    //fprintf(stdout, "if (%s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    
                    break;
                case JMP:
                    /*printf("%p\n", inst->opds[0]);
                    fflush(stdout);
                    printf("%p\n", reinterpret_cast<BasicBlock>(inst->opds[0]));
                    fflush(stdout);*/
                    //assert(((BasicBlock)DST));
                    //assert(((BasicBlock)DST)->symbol);
                    //fprintf(stdout, "goto %s", ((BasicBlock)DST)->symbol->name.c_str());
                    
                    break;
                case RET:
                    //if(DST == NULL)
                    //    fprintf(stdout, "return", DST->name.c_str());
                    //fprintf(stdout, "return %s", DST->name.c_str());
                    break;
                case CALL:{
                    // vector<pair<Symbol, Type> > * args = (vector<pair<Symbol, Type> > *)SRC2;
                    // int i;

                    // if (DST != NULL)
                    //     fprintf(stdout, "%s = ", DST->name.c_str());
                    // fprintf(stdout, "%s(", SRC1->name.c_str());
                    // for (auto &arg: *args) {
                    //     fprintf(stdout, "%s, ", arg.first->name.c_str());
                    // }
                    // fprintf(stdout, ")");
                }
                    break;
                default:
                    //fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
                    if(ir->opds[1]->kind==SK_Temp)
                    {
                        use[ir->opds[1]]=1;
                    }
                    
                    break;
            }
        }
        vector<IrInst>irafter;
        // for(int i=0;i<bb->insts.size();i++)
        
    }

}

