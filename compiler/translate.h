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

}

IRTreeNode translateStmt(SymbolTable &valueEnv, SymbolTable &typeEnv, Stmt stmt)
{

}

IRTreeNode translateDecl(SymbolTable &valueEnv, SymbolTable &typeEnv, Decl decl)
{

}

#endif //CP_TRANSLATE_H
