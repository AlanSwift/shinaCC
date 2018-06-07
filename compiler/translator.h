//
// Created by Administrator on 2018/6/4/004.
//

#ifndef CP_TRANSLATOR_H
#define CP_TRANSLATOR_H

#include "constant.h"
#include "expression.h"
#include "declaration.h"
#include "symbol.h"
#include "type.h"
#include "statement.h"
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>

typedef class Translator_ *Translator;
typedef class Program_ *Program;


class Program_
{
public:
    FunctionSymbol currentFunc;
    std::vector<Symbol> globals;
    std::vector<FunctionSymbol> functionList;
    Program_():currentBlock(NULL){

    }
    std::vector<BasicBlock> bblocks;
    BasicBlock currentBlock;
    void appendInst(IrInst e);
    BasicBlock createBasicBlock();
    void startBasicBlock(BasicBlock bb);
};

class Translator_
{
public:
	SymbolTable<Symbol> *table;
    Translator_(){
        program = new Program_();
    }
    Program translate(TranslationUnitDecl start);
    void translateStatement(Stmt stmt);
    Symbol translateExpression(Expr expr);
    void controlFlowOptimise();

private:
    int tmpNumber, labelNumber;
    Program program;
    /*translate expression*/
    Symbol translateFunctionCall(CallExpr expr);//1
    Symbol translateBinaryExpr(BinaryOpExpr expr);
    Symbol translateUnaryExpr(UnaryOpExpr expr);
    Symbol translateIncrement(UnaryOpExpr expr);//1
    Symbol translateConditionalExpr(ConditionalExpr expr);//1
    Symbol translateAssignmentExpr(AssignExpr expr);
    Symbol translateCommaExpr(BinaryOpExpr expr);//1
    Symbol translateCastExpr(Expr expr);
    Symbol translatePrimaryExpr(Expr expr); //id, str, int, float, parentheses
    Symbol translateArrayIndex(ArraySubscriptExpr expr);//1

    Symbol translateBranchExpr(Expr expr);

    /*translate statement*/
    void translateExprStmt(ExprStmt stmt);
    void translateLabelStmt(LabelStmt stmt);
    void translateCaseStmt(CaseStmt stmt);
    void translateDefaultStmt(DefaultStmt stmt);
    void translateIfStmt(IfStmt stmt);
    void translateWhileStmt(WhileStmt stmt);
    void translateDoStmt(DoStmt stmt);
    
    void translateForStmt(ForStmt stmt);
    void translateGotoStmt(GoToStmt stmt);
    void translateBreakStmt(BreakStmt stmt);
    void translateContinueStmt(ContinueStmt stmt);
    void translateReturnStmt(ReturnStmt stmt);
    void translateCompoundStmt(CompoundStmt stmt);
    void translateSwitchStmt(SwitchStmt stmt);


    /*utils*/
    Expr notExpr(Expr expr);

    void translateBranch(Expr expr, BasicBlock trueBlock, BasicBlock falseBlock);

    void generateBranch(Type type, BasicBlock dstBlock, int opcode, Symbol src1, Symbol src2)
    {
        IrInst inst = new IrInst_();
        inst->type = type;
        inst->opcode = opcode;
        dstBlock->reference++;
        src1->ref++;
        if(src2)    src2->ref++;

        inst->opds[0] = (Symbol)dstBlock; //!!!
        inst->opds[1] = src1;
        inst->opds[2] = src2;
        program->appendInst(inst);
    }

    void generateJump(BasicBlock dstBlock)
    {
        IrInst inst = new IrInst_();
        inst->opcode = JMP;
        inst->type = BuiltinType_::voidType;
        dstBlock->reference++;
        inst->opds[0] = (Symbol)dstBlock; //!!!
		//printf("\n-----------------------addr1 = %p\n", inst->opds[0]);
        program->appendInst(inst);
    }

    void generateAssign(Type type, Symbol dst, int opcode, Symbol src1, Symbol src2)
    {
        IrInst inst = new IrInst_();
        inst->opcode = opcode;
        inst->opds[0] = dst;
        inst->opds[1] = src1;
        inst->opds[2] = src2;
        dst->ref++;
        src1->ref++;
        if(src2)    src2->ref++;
        program->appendInst(inst);
        DefineTemp(dst,opcode,src1,src2);
    }

    void generateMove(Type type, Symbol dst, Symbol src)
    {
        IrInst inst = new IrInst_();
        dst->ref++;
        src->ref++;
        inst->opcode = MOV;
        inst->opds[0] = dst;
        inst->opds[1] = src;
        program->appendInst(inst);
		
		if (dst->kind == SK_Variable){
			TrackValueChange(dst);
		}
		else if (dst->kind == SK_Temp){
			DefineTemp(dst, MOV, (Symbol)inst, NULL);
		}
    }

    void generateReturn(Type type,Symbol src)
    {
        IrInst inst=new IrInst_();
        inst->type=type;
        inst->opcode=RET;
        inst->opds[0]=src;
        inst->opds[1]=inst->opds[2]=NULL;
        src->ref++;
        program->appendInst(inst);

    }

	void generateIndirectMove(Type ty, Symbol dst, Symbol src)
	{
		IrInst inst = new IrInst_();
		inst->type = ty;
		inst->opcode = IMOV;
		inst->opds[0] = dst;
		inst->opds[1] = src;
		inst->opds[2] = NULL;
        dst->ref++;
        src->ref++;

		program->appendInst(inst);
	}

    void generateFunctionCall(Type type,Symbol recv,Symbol faddr, std::vector<std::pair<Symbol,Type> > *args)
    {
        pair<Symbol,Type> p;
        IrInst inst=new IrInst_();
        inst->type=type;
        inst->opcode=CALL;
        inst->opds[0] = recv;
        inst->opds[1] = faddr;
        inst->opds[2] = (Symbol)( args );
        program->appendInst(inst);

        faddr->ref++;
        if(recv)
        {
            recv->ref++;
        }
        for(auto &i:*args )
        {
            i.first->ref++;

        }

        if(!recv) {
            this->DefineTemp(recv, CALL, (Symbol)inst, NULL);
        }

        

    }

    Symbol translateCast(Type to, Type from, Symbol src)
    {
        Symbol dst;	
		if (to->id == CONST_TYPE_POINTER) {
			assert(from->id == CONST_TYPE_ARRAY || from->id == CONST_TYPE_FUNC);
			dst = createTemp(to);
			if(from->id == CONST_TYPE_ARRAY)
				generateMove(to, dst, src);
			else
				generateMove(to, dst, addressOf(src));
			return dst;
		}
		int scode = typeCode(from), dcode = typeCode(to), opcode;
        switch (scode) {
            case I1: opcode = EXTI1; break;
            case I2: opcode = EXTI2; break;
            case U1: opcode = EXTU1; break;
            case U2: opcode = EXTU2; break;
            case I4:
                if (dcode <= U1)
                    opcode = TRUI1;
                else if (dcode <= U2)
                    opcode = TRUI2;
                else if (dcode == F4)
                    opcode = CVTI4F4;
                else if (dcode == F8)
                    opcode = CVTI4F8;
                else
                    return src;
                break;
            case U4:
                if (dcode == F4)
                    opcode = CVTU4F4;
                else if (dcode == F8)
                    opcode = CVTU4F8;
                else
                    return src;
                break;
            case F4:
                if (dcode == I4)
                    opcode = CVTF4I4;
                else if (dcode == U4)
                    opcode = CVTF4U4;
                else
                    opcode = CVTF4;
                break;
            case F8:
                if (dcode == I4)
                    opcode = CVTF8I4;
                else if (dcode == U4)
                    opcode = CVTF8U4;
                else
                    opcode = CVTF8;
                break;
            default:
                assert(0);
                return NULL;
        }
        dst = createTemp(to);
        generateAssign(from, dst, opcode, src, NULL);
        return dst;
    }

    int typeCode(Type type)
    {
        if(type == BuiltinType_::intType || type == BuiltinType_::longType)
            return I4;
        else if(type == BuiltinType_::unsignedIntType || type == BuiltinType_::unsignedLongType)
            return U4;
        else if(type == BuiltinType_::shortType)
            return I2;
        else if(type == BuiltinType_::unsignedShortType)
            return U2;
        else if(type == BuiltinType_::charType)
            return I1;
        else if(type == BuiltinType_::unsignedCharType)
            return U1;
        else if(type == BuiltinType_::floatType)
            return F4;
        else if(type == BuiltinType_::doubleType || type == BuiltinType_::longDoubleType)
            return F8;
        else if(type->id == CONST_TYPE_POINTER)
            return U4;
        assert(type == BuiltinType_::voidType);
        return V;
    }

    void TrackValueChange(Symbol p)
    {
        valueUse use = dynamic_cast<VariableSymbol>(p)->uses;

        while (use)
        {
            //printf("------%p-----\n",use);
            //printf("++++++%p+++++\n",use->def);
            if (use->def->op != ADDR)
                use->def->dst = NULL;
            use = use->next;
        }
    }

    void TrackValueUse(Symbol p, valueDef  def)
    {
        valueUse use=new valueUse_();

        use->def = def;

        use->next = dynamic_cast<VariableSymbol>(p)->uses;
        dynamic_cast<VariableSymbol>(p)->uses = use;

    }

    void DefineTemp(Symbol t, int op, Symbol src1, Symbol src2)
    {
        valueDef def=new valueDef_();
        if(!t)
        {
            printf("NULL!!!!!!!!!!!!!!\n");
            
        }
        def->dst = t;
        def->op = op;
        def->src1 = src1;
        def->src2 = src2;
        def->ownBB = program->currentBlock;

        if (op == MOV || op == CALL)
        {
            def->link = dynamic_cast<VariableSymbol>(t)->def;
            dynamic_cast<VariableSymbol>(t)->def = def;
            return;
        }

        if (src1->kind == SK_Variable)
        {
            TrackValueUse(src1, def);
        }
        if (src2 && src2->kind == SK_Variable)
        {
            TrackValueUse(src2, def);
        }
        dynamic_cast<VariableSymbol>(t)->def = def;
    }

    bool lookUp(std::string name)
    {
        for(auto &symbol: program->currentFunc->locals)
            if(symbol->name == name)
                return true;
        return false;
    }

    Symbol createTemp(Type type)
    {
        assert(program->currentFunc);
        std::string name;
        do{
            name = "tmp" + std::to_string(tmpNumber++);
			//printf("???%s, %d\n", name.c_str(), lookUp(name));
        }while(lookUp(name));
        Symbol tmp = new VariableSymbol_();
        tmp->name = name;
        tmp->kind = SK_Temp;
        tmp->type = type;
        program->currentFunc->locals.push_back(tmp);
        //table.addSymbol(name, tmp);
        return tmp;
    }

    Symbol createLabel()
    {
        Symbol label = new Symbol_();
        label->name = "label_" + std::to_string(labelNumber++);
        label->kind = SK_Label;
        return label;
    }

    Symbol simplify(Type ty, int opcode, Symbol src1, Symbol src2);
    
    Symbol addressOf(Symbol symbol);

    Symbol deReference(Type type,Symbol symbol);
    Symbol offset(Type ty, Symbol addr, Symbol voff, int coff);
    Symbol createOffset(Type ty, Symbol base, int coff);


    Symbol IntConstant(int i)
    {
        Symbol p = new Symbol_();
        p->kind = SK_Constant;
        p->name = std::to_string(i);
        p->valueUnion.i[0] = i;
        p->valueUnion.i[1] = 0;
        p->type = BuiltinType_::intType;
        return p;
    }

    Symbol DoubleConst(double d)
    {
        Symbol p = new Symbol_();
        p->kind = SK_Constant;
        p->name = std::to_string(d);
        p->valueUnion.d = d;
        p->type = BuiltinType_::doubleType;
        return p;
    }

    Symbol TryAddValue(Type ty, int op, Symbol src1, Symbol src2);
    bool isRealType(Type c);
    bool isIntegType(Type c);
    bool isPointerType(Type c);
    int powerOf2(unsigned int u);

	void showProgram(TranslationUnitDecl start)
	{
		int ptr = 0;
		printf("global(%d): ", program->globals.size());
		for (auto &s : program->globals)
			printf("%s, ", s->name.c_str());
		printf("\n");
		for (auto &decl : start->declarations) {
			if (decl->id == NODE_DECL_FUNCTION) {
				FunctionDecl decl1 = (FunctionDecl)decl;
				if (!decl1->stmt)
					continue;
				program->currentFunc = decl1->functionSymbol;
				program->currentFunc->entryBB->symbol->name = program->currentFunc->name;
				showFunction(decl1->functionSymbol, ptr);
			}
		}
	}

	void showFunction(FunctionSymbol functionSymbol, int& ptr)
	{
		printf("locals temporary variables: ");
		for(auto &s: program->currentFunc->locals)
			if (s->kind == SK_Temp) 
				printf("%s, ", s->name.c_str());
		printf("\n");
		printf("locals variables: ");
		for (auto &s : program->currentFunc->locals)
			if (s->kind == SK_Variable)
				printf("%s, ", s->name.c_str());
		printf("\n");
		for (; program->bblocks[ptr] != functionSymbol->exitBB; ptr++) {
			fprintf(stdout, "%s: \n", program->bblocks[ptr]->symbol->name.c_str());
			for (auto &i : program->bblocks[ptr]->insts) {
				showInstruction(i);
			}
		}
		assert(program->bblocks[ptr]);
		fprintf(stdout, "%s: \n", program->bblocks[ptr]->symbol->name.c_str());
		for (auto &i : program->bblocks[ptr]->insts) {
			showInstruction(i);
		}
		ptr++;
	}

	void showInstruction(IrInst inst)
	{
#define DST  inst->opds[0]
#define SRC1 inst->opds[1]
#define SRC2 inst->opds[2]
		assert(inst);
		char opCodeNames[][30] = { 
			"|", "^", "&", "<<", ">>", "+", "-", "*", "/", "%",
			"-", "~", "", "!", "==", "!=", ">", "<", ">=", "<=",
			"jump", "ijump", "++", "--", "&", "*", "(int)(char)", "(int)(unsigned char)",
			"(int)(short)", "(int)(unsigned short)", "(char)(int)",
			"(short)(int)", "(float)(int)", "(double)(int)", "(float)(unsigned)",
			"(double)(unsigned)", "(double)(float)", "(int)(float)", "(unsigned)(float)",
			"(float)(double)", "(int)(double)", "(unsigned)(double)", "=", "*=", "call", "ret", "", "NOP"
		};
		int op = inst->opcode;
		//printf("=============op = %d %s\n", op, opCodeNames[op]);
		fprintf(stdout, "\t");
		fflush(stdout);
		switch (op) {
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
			fprintf(stdout, "%s = %s %s %s", DST->name.c_str(), SRC1->name.c_str(), opCodeNames[op], SRC2->name.c_str());
			// fprintf(stdout,"\nshow def use of op0:\n");
            // if(DST)
            // {
            //     DST->show();
            // }
            
            // fprintf(stdout,"show def use of src1:\n");
            // if(SRC1)
            // {
            //     SRC1->show();
            // }
            // fprintf(stdout,"show def use of src2:\n");
            // if(SRC2)
            // {
            //     SRC2->show();
            // }
            break;
		case INC:
		case DEC:
			fprintf(stdout, "%s%s", opCodeNames[op], DST->name.c_str());
			break;
		case BCOM:
		case NEG:
		case ADDR:
		case DEREF:
			fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
			// fprintf(stdout,"\nshow def use of op0:\n");
            // if(DST)
            // {
            //     DST->show();
            // }
            
            // fprintf(stdout,"show def use of src1:\n");
            // if(SRC1)
            // {
            //     SRC1->show();
            // }
            // fprintf(stdout,"show def use of src2:\n");
            // if(SRC2)
            // {
            //     SRC2->show();
            // }
            break;
		case MOV:
			fprintf(stdout, "%s = %s", DST->name.c_str(), SRC1->name.c_str());
			// fprintf(stdout,"\nshow def use of op0:\n");
            // if(DST)
            // {
            //     DST->show();
            // }
            
            // fprintf(stdout,"show def use of src1:\n");
            // if(SRC1)
            // {
            //     SRC1->show();
            // }
            // fprintf(stdout,"show def use of src2:\n");
            // if(SRC2)
            // {
            //     SRC2->show();
            // }
            break;
		case IMOV:
			fprintf(stdout, "*%s = %s", DST->name.c_str(), SRC1->name.c_str());
			// fprintf(stdout,"\nshow def use of op0:\n");
            // if(DST)
            // {
            //     DST->show();
            // }
            
            // fprintf(stdout,"show def use of src1:\n");
            // if(SRC1)
            // {
            //     SRC1->show();
            // }
            // fprintf(stdout,"show def use of src2:\n");
            // if(SRC2)
            // {
            //     SRC2->show();
            // }
            break;
		case JE:
		case JNE:
		case JG:
		case JL:
		case JGE:
		case JLE:
			fprintf(stdout, "if (%s %s %s) goto %s", SRC1->name.c_str(), opCodeNames[op],
				SRC2->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
			break;
		case JZ:
			fprintf(stdout, "if (! %s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
			break;
		case JNZ:
			fprintf(stdout, "if (%s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
			break;
		case JMP:
			/*printf("%p\n", inst->opds[0]);
			fflush(stdout);
			printf("%p\n", reinterpret_cast<BasicBlock>(inst->opds[0]));
			fflush(stdout);*/
			assert(((BasicBlock)DST));
			assert(((BasicBlock)DST)->symbol);
			fprintf(stdout, "goto %s", ((BasicBlock)DST)->symbol->name.c_str());
			
            break;
		case RET:
			if(DST == NULL)
				fprintf(stdout, "return", DST->name.c_str());
			fprintf(stdout, "return %s", DST->name.c_str());
			break;
		case CALL:{
			vector<pair<Symbol, Type> > * args = (vector<pair<Symbol, Type> > *)SRC2;
			int i;

			if (DST != NULL)
				fprintf(stdout, "%s = ", DST->name.c_str());
			fprintf(stdout, "%s(", SRC1->name.c_str());
			for (auto &arg: *args) {
				fprintf(stdout, "%s, ", arg.first->name.c_str());
			}
			fprintf(stdout, ")");
		}
			break;
		default:
			fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
			break;
		}
		fprintf(stdout, ";\n");
		fflush(stdout);
        

	}
};

#endif //CP_TRANSLATOR_H
