//
// Created by Administrator on 2018/5/30/030.
//

#ifndef CP_TRANSLATE_H
#define CP_TRANSLATE_H

#include "constant.h"
#include "expression.h"
#include "type.h"
#include "declaration.h"
#include "statement.h"
#include "SymbolTable.h"
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

IRTreeNode translateExpr(SymbolTable &valueEnv, SymbolTable &typeEnv, Expr expr)
{
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
        }
            break;
        case NODE_EXP_UNARY:{
            UnaryOpExpr expr1 = (UnaryOpExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->expr);
            //TODO:
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
            if(!expr1->var || expr1->var->id != NODE_EXP_DECLREF){
                printf("%d:%d: error: expression is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->var->type->id == CONST_TYPE_ARRAY){
                printf("%d:%d: error: array type is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            if(expr1->var->type->id == CONST_TYPE_FUNC){
                printf("%d:%d: error: function type is not assignable\n", expr1->sourceLoc.line, expr1->sourceLoc.col);
                exit(0);
            }
            translateExpr(valueEnv, typeEnv, expr1->var);
            translateExpr(valueEnv, typeEnv, expr1->expr);
            expr1->type = expr1->var->type;
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
            //TODO: character index
            if(expr1->offset->id != NODE_EXP_INTLITERAL
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
            expr1->type = type;
        }
            break;
        case NODE_EXP_PAREN:{
            ParenExpr expr1 = (ParenExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->expr);
            expr1->type = expr->type;
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

}

IRTreeNode translateDecl(SymbolTable &valueEnv, SymbolTable &typeEnv, Decl decl)
{
    //type is all valid
    switch(decl->id)
    {
        case NODE_DECL_VAR:
        {
            Type c=typeEnv.lookUp(decl->name);
            if(c!=NULL)
            {
                std::cerr<<"error: redefinition of '"<< decl->name <<"' with a different type: '"<< c->getType() <<"' vs '"<< ((VarDecl)decl)->type->getType()<<"'"<<std::endl;
                assert(0);
            }
            else{
                typeEnv.addSymbol(decl->name,((VarDecl)decl)->type);
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

            Type c=typeEnv.lookUp(decl->name);
            if(c==NULL)
            {
                if(((FunctionDecl)decl)->stmt!=NULL)
                {
                    ((FunctionType)funType)->isDefined=true;
                }
                typeEnv.addSymbol(decl->name,funType);
            }
            else if(c->id!=CONST_TYPE_FUNC)
            {
                std::cerr<<"error: redefinition of '"<<decl->name<<"' as different kind of symbol"<<std::endl;
                assert(0);
            }
            if(c!=NULL && ((FunctionType)c)->isDefined && ((FunctionDecl)decl)->stmt!=NULL)
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
