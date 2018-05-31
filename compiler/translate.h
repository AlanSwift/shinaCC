//
// Created by Administrator on 2018/5/30/030.
//

#ifndef CP_TRANSLATE_H
#define CP_TRANSLATE_H

#include <cassert>
#include "constant.h"
#include "expression.h"
#include "type.h"
#include "declaration.h"
#include "statement.h"
#include "SymbolTable.h"
#include "utils.h"
#include <cassert>
#include <iostream>

typedef void IRTreeNode;

bool checkType(Type type);

IRTreeNode translateExpr(SymbolTable &valueEnv, SymbolTable &typeEnv, Expr expr);

IRTreeNode translateStmt(SymbolTable &valueEnv, SymbolTable &typeEnv, Stmt stmt);

IRTreeNode translateDecl(SymbolTable &valueEnv, SymbolTable &typeEnv, Decl decl);

IRTreeNode translate(TranslationUnitDecl start)
{
    SymbolTable* valueEnv= nullptr, *typeEnv= nullptr;
    valueEnv=new SymbolTable();
    typeEnv=new SymbolTable();
    for(auto &decl: start->declarations){
        translateDecl(*valueEnv, *typeEnv, decl);
    }
}

Expr transformImplicitExp(Expr expr, int type)
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


Expr castFromTo(Expr expr, Type type)
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
                printf("%s %s\n", ((ArrayType)expr->type)->basicType->getType().c_str(),
                       ((PointerType)type)->pointTo->getType().c_str());
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

IRTreeNode translateExpr(SymbolTable &valueEnv, SymbolTable &typeEnv, Expr expr)
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
        case NODE_EXP_BINARY:{
            BinaryOpExpr expr1 = (BinaryOpExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->left);
            translateExpr(valueEnv, typeEnv, expr1->right);
            //TODO:
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
                    if(i == 0 || ((BuiltinType)(expr1->left->type))->builtinType == types[i]){
                        if(((BuiltinType)(expr1->left->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->left, types[i]);
                            expr1->left = tmp;
                            break;
                        }
                        if(((BuiltinType)(expr1->right->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->right, types[i]);
                            expr1->right = tmp;
                            break;
                        }
                    }
                    else if(((BuiltinType)(expr1->right->type))->builtinType == types[i]){
                        if(((BuiltinType)(expr1->left->type))->builtinType != types[i]){
                            Expr tmp = transformImplicitExp(expr1->left, types[i]);
                            expr1->left = tmp;
                            break;
                        }
                    }
                }
                expr1->type = expr1->left->type;
                /*if(expr1->left->isIntConstant() && expr1->right->isIntConstant()){
                    Expr tmp = new IntLiteral_();
                }*/
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
                expr1->type = p->type;
            }
        }
            break;
        case NODE_EXP_UNARY:{
            UnaryOpExpr expr1 = (UnaryOpExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->expr);
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
                    printf("%d:%d: error: invalid unary operation '*'\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                else
                    expr1->type = ((PointerType)expr1->expr->type)->pointTo;
            }
            else if(expr1->operator_ == OP_UNARY_AND){
                expr1->type = new PointerType_(expr1->expr->type);
            }
            else{ //+, -, ++, --, ~, !
                if(expr1->expr->type->id == CONST_TYPE_ARRAY || expr1->expr->type->id == CONST_TYPE_FUNC){
                    fprintf(stderr, "%d:%d: error: invalid unary operation\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                    exit(0);
                }
                if(expr1->expr->type->id == CONST_TYPE_POINTER)
                    if(expr1->operator_ != OP_UNARY_DOUBLEADD && expr1->operator_ != OP_UNARY_DOUBLEMINUS){
                        fprintf(stderr, "%d:%d: error: invalid unary operation\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                        exit(0);
                    }
                expr1->type = expr1->expr->type;
            }

        }
            break;
        case NODE_EXP_CONDITIONAL:{
            ConditionalExpr expr1 = (ConditionalExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->condition);
            translateExpr(valueEnv, typeEnv, expr1->true_);
            translateExpr(valueEnv, typeEnv, expr1->false_);
            //TODO:
        }
            break;
        case NODE_EXP_ASSIGN:{
            AssignExpr expr1 = (AssignExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->var);
            translateExpr(valueEnv, typeEnv, expr1->expr);
            if(!expr1->var || expr1->var->id != NODE_EXP_DECLREF){
                printf("%d:%d: error: expression is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->var->type->id == CONST_TYPE_ARRAY){
                printf("%d:%d: error: array type is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->var->type->id == CONST_TYPE_FUNC){
                fprintf(stderr, "%d:%d: error: function type is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            expr1->type = expr1->var->type;
            expr1->expr->show();
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
            //TODO:
        }
            break;
        case NODE_EXP_ARRAYSUBSCRIPT:{
            ArraySubscriptExpr expr1 = (ArraySubscriptExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->array);
            translateExpr(valueEnv, typeEnv, expr1->offset);
            if(!expr1->array || (expr1->array->type->id != CONST_TYPE_ARRAY && expr1->array->type->id != CONST_TYPE_POINTER)){
                printf("%d:%d: error: subscripted value is not an array, pointer\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(!expr1->offset){
                printf("%d:%d: error: array subscript is not an integer\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(!expr1->offset->isIntConstant()
               && (expr1->offset->type->id != CONST_TYPE_BUILTIN || !((BuiltinType)(expr1->offset->type))->isInteger())){
                printf("%d:%d: error: array subscript is not an integer\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->array->type->id != CONST_TYPE_ARRAY)
                expr1->type = ((ArrayType)expr1->array->type)->basicType;
            else
                expr1->type = ((PointerType)expr1->array->type)->pointTo;
        }
            break;
        case NODE_EXP_DECLREF:{
            DeclRefExpr expr1 = (DeclRefExpr)expr;
            Type type = valueEnv.lookUp(expr1->name);
            if(!type){
                printf("%d:%d: error: use of undeclared identifier \'%s\'\n",
                       expr1->sourceLoc.line, expr1->sourceLoc.col, expr1->name.c_str());
                exit(0);
            }
            //printf("DEBUG> %s %s\n", expr1->name.c_str(), type->getType().c_str());
            expr1->type = type;
        }
            break;
        case NODE_EXP_PAREN:{
            ParenExpr expr1 = (ParenExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->expr);
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
        default:
            break;
    }
}

IRTreeNode translateStmt(SymbolTable &valueEnv, SymbolTable &typeEnv, Stmt stmt)
{
    switch (stmt->id){
        case NODE_STM_COMPOUND:
            for(auto &s: ((CompoundStmt)stmt)->stmtList)
                translateStmt(valueEnv, typeEnv, s);
            break;
        case NODE_STM_EXPR:
            translateExpr(valueEnv, typeEnv, ((ExprStmt)stmt)->expr);
            break;
        case NODE_STM_DECL:
            for(auto &d: ((DeclStmt)stmt)->declarations)
                translateDecl(valueEnv, typeEnv, d);
            break;
        default:
            break;
    }
}

IRTreeNode translateDecl(SymbolTable &valueEnv, SymbolTable &typeEnv, Decl decl)
{
    //type is all valid
    
    switch(decl->id)
    {
        case NODE_DECL_VAR:
        {
            Type c=valueEnv.lookUp(decl->name);
            if(c!=NULL)
            {
                std::cerr<<"error: redefinition of '"<< decl->name <<"' with a different type: '"<< c->getType() <<"' vs '"<< ((VarDecl)decl)->type->getType()<<"'"<<std::endl;
                assert(0);
            }
            else{
                
                valueEnv.addSymbol(decl->name,((VarDecl)decl)->type);
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
            FunctionType funType=new FunctionType_(ret,args);
                        
            Type c=valueEnv.lookUp(decl->name);
            
            if(c==NULL)
            {
                
                if(((FunctionDecl)decl)->stmt!=NULL)
                {
                    
                    ((FunctionType)funType)->isDefined=true;
                    valueEnv.pushEnv();
                    typeEnv.pushEnv();
                    translateStmt(valueEnv, typeEnv, ((FunctionDecl)decl)->stmt);
                    valueEnv.popEnv();
                    typeEnv.popEnv();
                }
                valueEnv.addSymbol(decl->name,funType);
                
            }
            else if(c->id!=CONST_TYPE_FUNC)
            {
                std::cerr<<"error: redefinition of '"<<decl->name<<"' as different kind of symbol"<<std::endl;
                assert(0);
            }
            else if(isMatchFunctionType((FunctionType)c,funType)&& ((FunctionType)c)->isDefined && ((FunctionDecl)decl)->stmt!=NULL)
            {
                std::cerr<<"error: redefinition of '"<<decl->name<<"'"<<std::endl;
                assert(0);
            }
            else{


            }
            break;
        }
    }
    
}

#endif //CP_TRANSLATE_H
