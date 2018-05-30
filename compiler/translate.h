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

typedef void IRTreeNode;

bool checkType(Type type);

IRTreeNode translateExpr(SymbolTable &valueEnv, SymbolTable &typeEnv, Expr expr);

IRTreeNode translateStmt(SymbolTable &valueEnv, SymbolTable &typeEnv, Stmt stmt);

IRTreeNode translateDecl(SymbolTable &valueEnv, SymbolTable &typeEnv, Decl decl);

IRTreeNode translate(TranslationUnitDecl start)
{
    SymbolTable valueEnv, typeEnv;
    for(auto &decl: start->declarations){
        translateDecl(valueEnv, typeEnv, decl);
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
                printf("expression is not assignable\n");
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
            //if(!expr1->array || expr1->array->type != )
            //TODO:
        }
            break;
        case NODE_EXP_DECLREF:{
            DeclRefExpr expr1 = (DeclRefExpr)expr;
            //TODO:
        }
            break;
        case NODE_EXP_PAREN:{
            ParenExpr expr1 = (ParenExpr)expr;
            translateExpr(valueEnv, typeEnv, expr1->expr);
            expr1->type = expr->type;
            //TODO:
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

}

#endif //CP_TRANSLATE_H
