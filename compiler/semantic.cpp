//
// Created by Administrator on 2018/6/1/001.
//

#include "semantic.h"

void Semantic::semanticAnalysis(TranslationUnitDecl start)
{
    for(auto &decl: start->declarations){
        semanticDecl(decl);
    }
}

void Semantic::semanticExpr(Expr expr)
{/*type: Func, Pointer, Array, Basic*/
    switch (expr->id){
        case NODE_EXP_STRLITERAL:{
            StrLiteral expr1 = (StrLiteral)expr;
            //TODO:
        }
            break;
        case NODE_EXP_FLOATLITERAL:{
            FloatLiteral expr1 = (FloatLiteral)expr;
            //TODO:
        }
            break;
        case NODE_EXP_INTLITERAL:{
            IntLiteral expr1 = (IntLiteral)expr;
            //TODO:
        }
            break;
        case NODE_EXP_CHARLITERAL:{
            CharLiteral expr1 = (CharLiteral)expr;
            //TODO:
        }
            break;
        case NODE_EXP_CONDITIONAL:{
            ConditionalExpr expr1 = (ConditionalExpr)expr;
            semanticExpr(expr1->condition);
            semanticExpr(expr1->true_);
            semanticExpr(expr1->false_);
            if(expr1->true_->type->id == CONST_TYPE_FUNC || expr1->true_->type->id == CONST_TYPE_ARRAY){
                Expr tmp = transformImplicitExp(expr1->true_, CONST_TYPE_POINTER);
                expr1->true_ = tmp; //to Pointer
            }
            if(expr1->false_->type->id == CONST_TYPE_FUNC || expr1->false_->type->id == CONST_TYPE_ARRAY){
                Expr tmp = transformImplicitExp(expr1->false_, CONST_TYPE_POINTER);
                expr1->false_ = tmp; //to Pointer
            }
            if(expr1->true_->type->id == CONST_TYPE_BUILTIN && expr1->false_->type->id == CONST_TYPE_BUILTIN){
                int types[7] = {CONST_TYPE_BUILTIN_INT, CONST_TYPE_BUILTIN_UNSIGNED_INT, CONST_TYPE_BUILTIN_LONG,
                                CONST_TYPE_BUILTIN_UNSIGNED_LONG, CONST_TYPE_BUILTIN_FLOAT, CONST_TYPE_BUILTIN_DOUBLE,
                                CONST_TYPE_BUILTIN_LONG_DOUBLE};
                for(int i = 6; i >= 0; i--){
                    if(i == 0){
                        if(((BuiltinType)(expr1->true_->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->true_, types[i]);
                            expr1->true_ = tmp;
                        }
                        if(((BuiltinType)(expr1->false_->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->false_, types[i]);
                            expr1->false_ = tmp;
                        }
                    }
                    else if(((BuiltinType)(expr1->true_->type))->builtinType == types[i]){
                        if(((BuiltinType)(expr1->false_->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->false_, types[i]);
                            expr1->false_ = tmp;
                        }
                        break;
                    }
                    else if(((BuiltinType)(expr1->false_->type))->builtinType == types[i]){
                        if(((BuiltinType)(expr1->true_->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->true_, types[i]);
                            expr1->true_ = tmp;
                        }
                        break;
                    }
                }
                expr1->type = expr1->true_->type;
            }
            else if(!isMatchType(expr1->true_->type, expr1->false_->type)){
                fprintf(stderr, "%d:%d: error: type mismatch in conditional expression\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            else{
                expr1->type = expr1->true_->type;
            }
        }
            break;
        case NODE_EXP_BINARY:{
            BinaryOpExpr expr1 = (BinaryOpExpr)expr;
            semanticExpr(expr1->left);
            semanticExpr(expr1->right);
            if(expr1->operator_ == OP_BINARY_COMMA){
                expr1->type = expr1->right->type;
                return;
            }
            if(expr1->left->type->id == CONST_TYPE_FUNC || expr1->left->type->id == CONST_TYPE_ARRAY){
                Expr tmp = transformImplicitExp(expr1->left, CONST_TYPE_POINTER);
                expr1->left = tmp; //to Pointer
            }
            if(expr1->right->type->id == CONST_TYPE_FUNC || expr1->right->type->id == CONST_TYPE_ARRAY){
                Expr tmp = transformImplicitExp(expr1->right, CONST_TYPE_POINTER);
                expr1->right = tmp; //to Pointer
            }
            if(expr1->left->type->id == CONST_TYPE_POINTER && expr1->right->type->id == CONST_TYPE_POINTER){
                fprintf(stderr, "%d:%d: error: invalid operands to binary(pointer and pointer)\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->left->type->id == CONST_TYPE_BUILTIN && expr1->right->type->id == CONST_TYPE_BUILTIN){
                int types[7] = {CONST_TYPE_BUILTIN_INT, CONST_TYPE_BUILTIN_UNSIGNED_INT, CONST_TYPE_BUILTIN_LONG,
                                CONST_TYPE_BUILTIN_UNSIGNED_LONG, CONST_TYPE_BUILTIN_FLOAT, CONST_TYPE_BUILTIN_DOUBLE,
                                CONST_TYPE_BUILTIN_LONG_DOUBLE};
                for(int i = 6; i >= 0; i--){
                    //printf("%d\n", ((BuiltinType)(expr1->left->type))->builtinType);
                    if(i == 0){
                        if(((BuiltinType)(expr1->right->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->right, types[i]);
                            expr1->right = tmp;
                        }
                        if(((BuiltinType)(expr1->left->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->left, types[i]);
                            expr1->left = tmp;
                        }
                    }
                    else if(((BuiltinType)(expr1->left->type))->builtinType == types[i]){
                        if(((BuiltinType)(expr1->right->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->right, types[i]);
                            expr1->right = tmp;
                        }
                        break;
                    }
                    else if(((BuiltinType)(expr1->right->type))->builtinType == types[i]){
                        if(((BuiltinType)(expr1->left->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->left, types[i]);
                            expr1->left = tmp;
                        }
                        break;
                    }
                }
                if(isLogicalOp(expr1->operator_) || isRelationalOp(expr1->operator_))
                    expr1->type = BuiltinType_::intType;
                else
                    expr1->type = expr1->left->type;
            }
            else {
                if(expr1->operator_ != OP_BINARY_ADD && expr1->operator_ != OP_BINARY_MINUS){
                    fprintf(stderr, "%d:%d: error: invalid operator to binary(pointer and integer)\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                Expr p = (expr1->left->type->id == CONST_TYPE_BUILTIN) ? expr1->left : expr1->right;
                if(!p->isIntConstant() && !(p->type->id == CONST_TYPE_BUILTIN && ((BuiltinType)p->type)->isInteger())){
                    fprintf(stderr, "%d:%d: error: invalid operands to binary(pointer and integer)\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                p = (expr1->left->type->id != CONST_TYPE_BUILTIN) ? expr1->left : expr1->right;

                if(isLogicalOp(expr1->operator_) || isRelationalOp(expr1->operator_))
                    expr1->type = BuiltinType_::intType;
                else
                    expr1->type = p->type;
            }
        }
            break;
        case NODE_EXP_UNARY:{
            UnaryOpExpr expr1 = (UnaryOpExpr)expr;
            semanticExpr(expr1->expr);
            if(expr1->operator_ == OP_UNARY_SIZEOF){
                //TODO:
            }
            else if(expr1->operator_ == OP_UNARY_CAST){
                //TODO:
            }
            else if(expr1->operator_ == OP_UNARY_STAR){
                if(expr1->expr->type->id == CONST_TYPE_ARRAY) {
                    Expr tmp = transformImplicitExp(expr1->expr, CONST_TYPE_POINTER);
                    expr1->expr = tmp;//to Pointer
                }
                else if(expr1->expr->type->id == CONST_TYPE_FUNC){
                    Expr tmp = transformImplicitExp(expr1->expr, CONST_TYPE_POINTER);
                    expr1->expr = tmp;//to Pointer
                }
                if(expr1->expr->type->id != CONST_TYPE_POINTER){
                    fprintf(stderr, "%d:%d: error: invalid unary operation '*'\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                else
                    expr1->type = ((PointerType)expr1->expr->type)->pointTo;
            }
            else if(expr1->operator_ == OP_UNARY_AND){
                expr1->type = new PointerType_(expr1->expr->type);
            }
            else{ //+, -, ++, --, ~, !
                if((expr1->expr->type == BuiltinType_::floatType
                    || expr1->expr->type == BuiltinType_::doubleType || expr1->expr->type == BuiltinType_::longDoubleType)
                   && isBitWiseOp(expr1->operator_)){
                    fprintf(stderr, "%d:%d: error: wrong type argument to bit-complement\n",
                            expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                if(expr1->expr->type->id == CONST_TYPE_ARRAY || expr1->expr->type->id == CONST_TYPE_FUNC){
                    fprintf(stderr, "%d:%d: error: invalid unary operation\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                if(expr1->expr->type->id == CONST_TYPE_POINTER)
                    if(expr1->operator_ != OP_UNARY_DOUBLEADD && expr1->operator_ != OP_UNARY_DOUBLEMINUS){
                        fprintf(stderr, "%d:%d: error: invalid unary operation\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                        exit(0);
                    }
                if(isLogicalOp(expr1->operator_))
                    expr1->type = BuiltinType_::intType;
                else
                    expr1->type = expr1->expr->type;
            }

        }
            break;
        case NODE_EXP_ASSIGN:{
            AssignExpr expr1 = (AssignExpr)expr;
            semanticExpr(expr1->var);
            semanticExpr(expr1->expr);
            if(expr1->expr->type == BuiltinType_::voidType){
                fprintf(stderr, "%d:%d: error: void value is not assignable\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(!expr1->var || expr1->isConstant()){
                fprintf(stderr, "%d:%d: error: expression is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->var->type->id == CONST_TYPE_ARRAY){
                fprintf(stderr, "%d:%d: error: array type is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->var->type->id == CONST_TYPE_FUNC){
                fprintf(stderr, "%d:%d: error: function type is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            expr1->type = expr1->var->type;
            Expr tmp = castFromTo(expr1->expr, expr1->var->type);
            if(!tmp){
                fprintf(stderr, "%d:%d: error: incompatible implicit type\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            expr1->expr = tmp;
            //TODO:
        }
            break;
        case NODE_EXP_CALL:{
            CallExpr expr1 = (CallExpr)expr;
            semanticExpr(expr1->func);
            for(auto &e: expr1->args){
                semanticExpr(e);
            }
            Type func = expr1->func->type;
            if(func->id != CONST_TYPE_FUNC && !(func->id == CONST_TYPE_POINTER
                                                && ((PointerType)func)->pointTo->id == CONST_TYPE_FUNC)){
                fprintf(stderr, "%d:%d: error: called object is not a function or function pointer\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            //exit(0)
            if(func->id != CONST_TYPE_FUNC){
                //expr1->func = transformImplicitExp(expr1->func, CONST_TYPE_POINTER);
                //expr1->func->show();
                //func = expr1->func->type;
                func = ((PointerType)func)->pointTo;
            }
            list<Type> *paras;
            paras = &((FunctionType)func)->argsType;
            list<Expr>::iterator it1;
            list<Type>::iterator it2;
            for(it1 = expr1->args.begin(), it2 = paras->begin();
                it1 != expr1->args.end() && it2 != paras->end(); it1++, it2++){
                Expr tmp = castFromTo(*it1, *it2);
                if(!tmp){
                    fprintf(stderr, "%d:%d: error: incompatible implicit type\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                *it1 = tmp;
            }
            if(it1 != expr1->args.end()){
                fprintf(stderr, "%d:%d: error:  too many arguments to function\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            else if(it2 != paras->end()){
                fprintf(stderr, "%d:%d: error:  too few arguments to function\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            expr1->type = ((FunctionType)func)->returnType;
        }
            break;
        case NODE_EXP_ARRAYSUBSCRIPT:{
            ArraySubscriptExpr expr1 = (ArraySubscriptExpr)expr;
            semanticExpr(expr1->array);
            semanticExpr(expr1->offset);
            if(!expr1->array || (expr1->array->type->id != CONST_TYPE_ARRAY && expr1->array->type->id != CONST_TYPE_POINTER)){
                fprintf(stderr, "%d:%d: error: subscripted value is not an array, pointer\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(!expr1->offset){
                fprintf(stderr, "%d:%d: error: array subscript is not an integer\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(!expr1->offset->isIntConstant()
               && (expr1->offset->type->id != CONST_TYPE_BUILTIN || !((BuiltinType)(expr1->offset->type))->isInteger())){
                fprintf(stderr, "%d:%d: error: array subscript is not an integer\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->array->type->id == CONST_TYPE_ARRAY){
                expr1->type = ((ArrayType)expr1->array->type)->basicType;
                expr1->array = transformImplicitExp(expr1->array, CONST_TYPE_POINTER);
            }
            else
                expr1->type = ((PointerType)expr1->array->type)->pointTo;
        }
            break;
        case NODE_EXP_DECLREF:{
            DeclRefExpr expr1 = (DeclRefExpr)expr;
            Symbol symbol = valueEnv.lookUp(expr1->name);
            if(!symbol){
                fprintf(stderr, "%d:%d: error: use of undeclared identifier \'%s\'\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col, expr1->name.c_str());
                exit(0);
            }
            /*if(type->id == CONST_TYPE_FUNC && !((FunctionType)type)->isDefined){
                fprintf(stderr, "%d:%d: error: function \'%s\' is not defined\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col, expr1->name.c_str());
                exit(0);
            }*/
            expr1->type = symbol->type;
            expr1->valueUnion.p = (void *)symbol;
        }
            break;
        case NODE_EXP_PAREN:{
            ParenExpr expr1 = (ParenExpr)expr;
            semanticExpr(expr1->expr);
            expr1->type = expr1->expr->type;
        }
            break;
        case NODE_EXP_IMPLICITCAST:{
            ImplicitCastExpr expr1 = (ImplicitCastExpr)expr;
            //TODO:
        }
            break;
        case NODE_EXP_MEMBER:{
            MemberExpr expr1 = (MemberExpr)expr;
            //TODO:
        }
            break;
        case NODE_EXP_CSTYLECAST:{
            CStyleCastExpr expr1 = (CStyleCastExpr)expr;
            //TODO:
        }
            break;
        case NODE_EXP_INITLIST:{
            InitListExpr expr1 = (InitListExpr)expr;
            if(expr1->type->id != CONST_TYPE_ARRAY){
                fprintf(stderr, "%d:%d: error: lvalue should be array\n",
                        expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            std::list<Expr>::iterator it;
            for(it = expr1->values.begin(); it != expr1->values.end(); it++){
                semanticExpr(*it);
                if((*it)->type->id != CONST_TYPE_ARRAY){
                    if(!isMatchType((*it)->type, ((ArrayType)expr1->type)->basicType)){
                        if(!(*it = castFromTo(*it, ((ArrayType)expr1->type)->basicType))){
                            fprintf(stderr, "%d:%d: error: incompatible implicit type\n", expr1->sourceLoc.line,
                                    expr1->sourceLoc.col);
                            exit(0);
                        }
                    }
                }
            }
        }
            break;
        default:
            break;
    }
}

Stmt targetStmt = NULL;

void Semantic::semanticStmt(Stmt stmt)
{
    switch (stmt->id){
        case NODE_STM_COMPOUND:
            valueEnv.pushEnv();
            typeEnv.pushEnv();
            for(auto &s: ((CompoundStmt)stmt)->stmtList)
                semanticStmt(s);
            valueEnv.popEnv();
            typeEnv.popEnv();
            break;
        case NODE_STM_EXPR:
            semanticExpr(((ExprStmt)stmt)->expr);
            break;
        case NODE_STM_DECL:
            for(auto &d: ((DeclStmt)stmt)->declarations)
                semanticDecl(d);
            break;
        case NODE_STM_SWITCH:{
            targetStmt = stmt;
            Expr expr = ((SwitchStmt)stmt)->expr;
            semanticExpr(expr);
            if(!expr->isIntConstant() &&
               !(expr->type->id == CONST_TYPE_BUILTIN && ((BuiltinType)expr->type)->isInteger())){
                fprintf(stderr, "%d:%d: error: switch quantity not an integer\n",
                        expr->sourceLoc.line, expr->sourceLoc.col);
                exit(0);
            }
            semanticStmt( ((SwitchStmt)stmt)->stmt);
            targetStmt = NULL;
        }
            break;
        case NODE_STM_CASE:{
            if(!targetStmt){
                fprintf(stderr, "%d:%d: error: case label not within a switch statement\n",
                        stmt->sourceLoc.line, stmt->sourceLoc.col);
                exit(0);
            }
            Expr expr = ((CaseStmt)stmt)->const_;
            semanticExpr(expr);
            if(!expr->isIntConstant()){
                fprintf(stderr, "%d:%d: error: case label can't be reduced to an Integer constant\n",
                        expr->sourceLoc.line, expr->sourceLoc.col);
                exit(0);
            }
            semanticStmt( ((CaseStmt)stmt)->stmt);
        }
            break;
        case NODE_STM_DEFAULT:
            if(!targetStmt){
                fprintf(stderr, "%d:%d: error: default label not within a switch statement\n",
                        stmt->sourceLoc.line, stmt->sourceLoc.col);
                exit(0);
            }
            semanticStmt( ((DefaultStmt)stmt)->stmt);
            break;
        case NODE_STM_RETURN:
            semanticExpr(((ReturnStmt)stmt)->result);
            break;
        case NODE_STM_IF:
            semanticExpr(((IfStmt)stmt)->condition);
            semanticStmt( ((IfStmt)stmt)->if_);
            if(((IfStmt)stmt)->else_)
                semanticStmt( ((IfStmt)stmt)->else_);
            break;
        case NODE_STM_WHILE:
            semanticExpr(((WhileStmt)stmt)->expr);
            targetStmt = stmt;
            semanticStmt(((WhileStmt)stmt)->stmt);
            targetStmt = NULL;
            break;
        case NODE_STM_DO:
            semanticExpr(((DoStmt)stmt)->expr);
            targetStmt = stmt;
            semanticStmt(((DoStmt)stmt)->stmt);
            targetStmt = NULL;
            break;
        case NODE_STM_FOR:{

            ForStmt stmt1 = (ForStmt)stmt;
            if(stmt1->init)
                semanticExpr(stmt1->init);
            if(stmt1->condition)
                semanticExpr(stmt1->condition);
            if(stmt1->next)
                semanticExpr(stmt1->next);
            targetStmt = stmt;
            semanticStmt( stmt1->stmt);
            targetStmt = NULL;
        }
            break;
        case NODE_STM_LABEL:
            semanticStmt( ((LabelStmt)stmt)->stmt);
            break;
        case NODE_STM_CONTINUE:
            if(!targetStmt || targetStmt->id == NODE_STM_SWITCH){
                fprintf(stderr, "%d:%d: error: continue label not within a loop statement\n",
                        stmt->sourceLoc.line, stmt->sourceLoc.col);
                exit(0);
            }
            ((ContinueStmt)stmt)->target = targetStmt;
            break;
        case NODE_STM_BREAK:
            if(!targetStmt){
                fprintf(stderr, "%d:%d: error: continue label not within a right statement\n",
                        stmt->sourceLoc.line, stmt->sourceLoc.col);
                exit(0);
            }
            ((BreakStmt)stmt)->target = targetStmt;
            break;
        case NODE_STM_NULL:
            break;
        case NODE_STM_GOTO:
            break;
        default:
            break;
    }
}

void Semantic::semanticDecl(Decl decl)
{
    //type is all valid

    switch(decl->id)
    {
        case NODE_DECL_VAR:
        {
            Symbol c=valueEnv.lookUp(decl->name);
            if(((VarDecl)decl)->init)
                semanticExpr(((VarDecl)decl)->init);
            if(c!=NULL)
            {
                std::cerr<<"error: redefinition of '"<< decl->name <<"' with a different type: '"<< c->type->getType() <<"' vs '"<< ((VarDecl)decl)->type->getType()<<"'"<<std::endl;
                assert(0);
            }
            else{
                Type c=((VarDecl)decl)->type;
                switch(c->id)
                {
                    case CONST_TYPE_ARRAY:
                    {
                        ArrayType content=(ArrayType)c;
                        //check size
                        isTypeValid(((VarDecl)decl)->name,c,((VarDecl)decl)->init);


                        break;
                    }
                }
                Symbol symbol = new VariableSymbol_();
                symbol->type = ((VarDecl)decl)->type;
                symbol->name = decl->name;
                symbol->kind = SK_Variable;
                valueEnv.addSymbol(decl->name, symbol);
                //TODO
            }
            break;
        }
        case NODE_DECL_FUNCTION:
        {

            Type ret=((FunctionDecl)decl)->returnType;
            std::list<Type> args;
            for(auto &e:((FunctionDecl)decl)->parameters)
            {
                args.push_back(((ParmVarDecl)e)->type);
            }

            Symbol c=valueEnv.lookUp(decl->name);
            FunctionType funType=new FunctionType_(ret,args);
            if(c==NULL)
            {
                FunctionSymbol funcSym = new FunctionSymbol_();
                funcSym->type = funType;
                funcSym->kind = SK_Function;
                funcSym->name = decl->name;
                ((FunctionDecl)decl)->functionSymbol = funcSym;
                if(((FunctionDecl)decl)->stmt!=NULL)
                {
                    ((FunctionType)funType)->isDefined=true;
                    valueEnv.pushEnv();
                    typeEnv.pushEnv();
                    for(auto & e:((FunctionDecl)decl)->parameters)
                    {
                        if(e->name=="")
                        {
                            std::cerr<<"error: parameter name omitted"<<std::endl;
                            assert(0);
                        }
                        else{
                            semanticDecl(e);

                        }

                    }
                    for(auto & e:((FunctionDecl)decl)->parameters)
                    {
                        Symbol symbol = new VariableSymbol_();
                        symbol->name = ((ParmVarDecl)e)->name;
                        symbol->type = ((ParmVarDecl)e)->type;
                        symbol->kind = SK_Variable;
                        valueEnv.addSymbol(((ParmVarDecl)e)->name, symbol);
                        funcSym->params.push_back(symbol);
                    }
                    valueEnv.addSymbol(decl->name, funcSym);
                    semanticStmt(((FunctionDecl)decl)->stmt);
                    valueEnv.popEnv();
                    typeEnv.popEnv();
                }
                else{
                    for(auto & e:((FunctionDecl)decl)->parameters)
                    {
                        if(e->name=="")
                        {
                            std::cerr<<"error: parameter name omitted"<<std::endl;
                            assert(0);
                        }
                        else{
                            Symbol symbol = new VariableSymbol_();
                            symbol->name = ((ParmVarDecl)e)->name;
                            symbol->type = ((ParmVarDecl)e)->type;
                            symbol->kind = SK_Variable;
                            funcSym->params.push_back(symbol);
                            semanticDecl(e);
                        }

                    }
                }
                valueEnv.addSymbol(decl->name,funcSym);

            }
            else if(c->type->id!=CONST_TYPE_FUNC)
            {
                std::cerr<<"error: redefinition of '"<<decl->name<<"' as different kind of symbol"<<std::endl;
                assert(0);
            }
            else if(isMatchFunctionType((FunctionType)c->type, funType)&& ((FunctionType)c->type)->isDefined
                    && ((FunctionDecl)decl)->stmt!=NULL)
            {
                std::cerr<<"error: redefinition of '"<<decl->name<<"'"<<std::endl;
                assert(0);
            }
            else{
                ((FunctionDecl)decl)->functionSymbol = (FunctionSymbol)c;
                ((FunctionType)funType)->isDefined=true;
                ((FunctionType)c)->isDefined=true;

                FunctionSymbol funcSym = (FunctionSymbol)c;

                valueEnv.pushEnv();
                typeEnv.pushEnv();
                for(auto & e:((FunctionDecl)decl)->parameters)
                {
                    if(e->name=="")
                    {
                        std::cerr<<"error: parameter name omitted"<<std::endl;
                        assert(0);
                    }
                    else{
                        semanticDecl(e);

                    }

                }
                for(auto & e: funcSym->params)
                {
                    valueEnv.addSymbol(e->name, e);
                }

                semanticStmt(((FunctionDecl)decl)->stmt);
                valueEnv.popEnv();
                typeEnv.popEnv();

            }
            break;
        }
        case NODE_DECL_PARMVAR:
        {
            if(((ParmVarDecl)decl)->type->id==CONST_TYPE_ARRAY||
               ((ParmVarDecl)decl)->type->id==CONST_TYPE_FUNC  )
            {
                std::cerr<<"error: parameter type error"<<std::endl;
                assert(0);
            }
            else{
                if(!isTypeValid(decl->name,((ParmVarDecl)decl)->type,NULL))
                {
                    std::cerr<<"error: parameter type error"<<std::endl;
                    assert(0);
                }

            }
            break;
        }
    }

}

Expr Semantic::transformImplicitExp(Expr expr, int type)
{
    switch(type){
        case CONST_TYPE_BUILTIN_LONG_DOUBLE:
            return new ImplicitCastExpr_(BuiltinType_::longDoubleType, expr);
        case CONST_TYPE_BUILTIN_DOUBLE:
            return new ImplicitCastExpr_(BuiltinType_::doubleType, expr);
        case CONST_TYPE_BUILTIN_FLOAT:
            return new ImplicitCastExpr_(BuiltinType_::floatType, expr);
        case CONST_TYPE_BUILTIN_LONG:
            return new ImplicitCastExpr_(BuiltinType_::longType, expr);
        case CONST_TYPE_BUILTIN_INT:
            return new ImplicitCastExpr_(BuiltinType_::intType, expr);
        case CONST_TYPE_BUILTIN_UNSIGNED_LONG:
            return new ImplicitCastExpr_(BuiltinType_::unsignedLongType, expr);
        case CONST_TYPE_BUILTIN_UNSIGNED_INT:
            return new ImplicitCastExpr_(BuiltinType_::unsignedIntType, expr);
        case CONST_TYPE_POINTER:
            if(expr->type->id == CONST_TYPE_POINTER)
                return expr;
            if(expr->type->id == CONST_TYPE_FUNC){
                //Expr tmpq = new ImplicitCastExpr_((Type)new PointerType_(expr->type), expr);
                //printf("DEBUG> %d\n", tmpq->type);
                return new ImplicitCastExpr_((Type)new PointerType_(expr->type), expr);
            }
            if(expr->type->id == CONST_TYPE_ARRAY){
                return new ImplicitCastExpr_((Type)new PointerType_(((ArrayType)expr->type)->basicType), expr);
            }
            assert(0);
        default:
            assert(0);
            break;
    }
}

Expr Semantic::castFromTo(Expr expr, Type type)
{
    if(!isMatchType(expr->type, type)){
        if(type->id == CONST_TYPE_POINTER){
            if(expr->type->id == CONST_TYPE_FUNC){
                //printf("impossible!!!!!");
                //exit(0);
                if(isMatchType(((PointerType)type)->pointTo, expr->type))
                    return transformImplicitExp(expr, CONST_TYPE_POINTER);
                return NULL;
            }
            if(expr->type->id == CONST_TYPE_ARRAY){
                //printf("impossible2!!!!!");
                //exit(0);
                //printf("%s %s\n", ((ArrayType)expr->type)->basicType->getType().c_str(),
                //       ((PointerType)type)->pointTo->getType().c_str());
                if(isMatchType(((ArrayType)expr->type)->basicType, ((PointerType)type)->pointTo))
                    return transformImplicitExp(expr, CONST_TYPE_POINTER);
                return NULL;
            }
            return NULL;
        }
        else{
            //printf("impossible3!!!!!: %s\n",type->getType().c_str());
            //exit(0);
            if(expr->type->id != CONST_TYPE_BUILTIN)
                return NULL;
            return transformImplicitExp(expr, ((BuiltinType)type)->builtinType);
        }
    }
    return expr;
}

bool Semantic::isTypeComplete(Type c)
{
    switch(c->id)
    {
        case CONST_TYPE_ARRAY:
        {
            if(((ArrayType)c)->size==NULL||((ArrayType)c)->basicType==NULL)
            {
                return false;
            }
            return isTypeComplete(((ArrayType)c)->basicType);
            break;
        }
        case CONST_TYPE_POINTER:
        {
            return isTypeComplete(((PointerType)c)->pointTo);
            break;
        }
        default:
        {
            return true;
        }

    }
}

bool Semantic::isTypeValid(std::string name,Type c,Expr init)
{
    switch(c->id)
    {
        case CONST_TYPE_ARRAY:
        {
            ArrayType content=(ArrayType)c;
            //check complement
            if(!isTypeComplete(((ArrayType)c)->basicType))
            {
                std::cerr<<"error: array has incomplete element type '"<<((ArrayType)c)->basicType->getType()<<"'"<<std::endl;
                assert(0);
            }
            //check size
            if(content->size==NULL)
            {
                if(init==NULL)
                {
                    std::cerr<<"error: definition of variable with array type needs an explicit size or an initializer"<<std::endl;
                    assert(0);
                }
                else{

                    if(content->basicType->id==CONST_TYPE_BUILTIN && ((BuiltinType)(content->basicType))->builtinType==CONST_TYPE_BUILTIN_CHAR && init->id==NODE_EXP_STRLITERAL)
                    {
                        content->size=new IntLiteral_(((StrLiteral)init)->value.size()+1);


                    }
                    else if(init->id!=NODE_EXP_INITLIST)
                    {
                        std::cerr<<"error: array initializer must be an initializer list"<<std::endl;
                        assert(0);
                    }
                    else{
                        //caculate size
                        content->size=new IntLiteral_(((InitListExpr)init)->values.size());
                        //check each element's type
                        if(((ArrayType)c)->basicType->id==CONST_TYPE_ARRAY)
                        {
                            for(auto it=((InitListExpr)init)->values.begin();it!=((InitListExpr)init)->values.end();it++)
                            {
                                if((*it)->id!=NODE_EXP_INITLIST)
                                {
                                    auto &expr=*it;
                                    std::list<Expr> vals=std::list<Expr>();
                                    vals.push_back(expr);
                                    *it=new InitListExpr_(vals);
                                }
                            }
                        }

                        //TODO
                        for(auto & e:((InitListExpr)init)->values)
                        {
                            isTypeValid(name,content->basicType,e);
                        }
                    }

                }
            }
            else if(content->size->id!=NODE_EXP_INTLITERAL)
            {
                std::cerr<<"error: size of array has non-integer type"<<std::endl;
                assert(0);
            }
            else{

                if(((IntLiteral)(content->size))->value<0)
                {
                    std::cerr<<"error: '"<<name<<"' declared as an array with a negative size"<<std::endl;
                    assert(0);
                }
                else if(init==NULL)
                {
                    isTypeValid(name,content->basicType,NULL);
                }
                else if(content->basicType->id==CONST_TYPE_BUILTIN && ((BuiltinType)(content->basicType))->builtinType==CONST_TYPE_BUILTIN_CHAR && init->id==NODE_EXP_STRLITERAL)
                {
                    if(((IntLiteral)(content->size))->value < ((StrLiteral)init)->value.size()+1)
                    {

                        std::cerr<<"error: initializer-string for char array is too long"<<std::endl;
                        assert(0);
                    }

                }
                else
                {

                    if( ((IntLiteral)(content->size))->value <((InitListExpr)init)->values.size())
                    {
                        std::cerr<<"error: excess elements in array initializer"<<std::endl;
                        assert(0);
                    }
                    else{
                        //refill
                        int number2Fill=((IntLiteral)(content->size))->value -((InitListExpr)init)->values.size();
                        std::cout<<number2Fill<<"&&&&"<<std::endl;

                        if(((ArrayType)c)->basicType->id==CONST_TYPE_ARRAY)
                        {
                            for(int i=0;i<number2Fill;i++)
                            {
                                std::list<Expr> vals=std::list<Expr>();

                                ((InitListExpr)init)->values.push_back(new InitListExpr_(vals));

                            }
                        }
                        else{
                            for(int i=0;i<number2Fill;i++)
                            {
                                ((InitListExpr)init)->values.push_back(new IntLiteral_(0));
                            }
                        }


                        //change to initialist
                        if(((ArrayType)c)->basicType->id==CONST_TYPE_ARRAY)
                        {
                            for(auto it=((InitListExpr)init)->values.begin();it!=((InitListExpr)init)->values.end();it++)
                            {
                                if((*it)->id!=NODE_EXP_INITLIST)
                                {
                                    auto &expr=*it;
                                    std::list<Expr> vals=std::list<Expr>();
                                    vals.push_back(expr);
                                    *it=new InitListExpr_(vals);
                                }
                            }
                        }


                    }
                    //check each element
                    //TODO
                    for(auto &e:((InitListExpr)init)->values)
                    {
                        isTypeValid(name,content->basicType,e);
                    }
                }
            }
            break;
        }
        case CONST_TYPE_POINTER:
        {
            //TODO
            break;
        }
        case CONST_TYPE_BUILTIN:
        {
            //std::cout<<id2name( ((BuiltinType)c)->builtinType)<<"****"<<std::endl;
            //std::cout<<id2name(init->id)<<"****"<<std::endl;
            if(init==NULL)
            {
                return true;
            }
            switch(((BuiltinType)c)->builtinType)
            {
                case CONST_TYPE_BUILTIN_INT:
                {
                    if(init->id==NODE_EXP_INTLITERAL)
                    {
                        return true;
                    }
                    else if(init->id==NODE_EXP_CHARLITERAL)
                    {
                        //TODO char->int implicate cast
                        return true;
                    }
                    else if(init->id==NODE_EXP_FLOATLITERAL)
                    {
                        //TODO char->int implicate cast
                        return true;
                    }
                    else
                    {

                    }
                    break;
                }

            }

            break;
        }
        default:
        {
            std::cout<<id2name(c->id)<<"fuckyou"<<std::endl;

        }
    }
    return true;
}

