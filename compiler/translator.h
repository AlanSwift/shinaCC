//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_SEMANT_H
#define CP_SEMANT_H

#include "symbol.h"
#include "constant.h"
#include "declaration.h"
#include "expression.h"
#include "type.h"
#include "expression.h"
#include "utils.h"

typedef void IRTreeNode;

class Translator
{
public:
    IRTreeNode translate(TranslationUnitDecl start);
private:
    SymbolTable<Type> valueEnv, typeEnv;

    IRTreeNode translateExpr(Expr expr);

    IRTreeNode translateStmt(Stmt stmt);

    IRTreeNode translateDecl(Decl decl);

    Expr transformImplicitExp(Expr expr, int type);

    Expr castFromTo(Expr expr, Type type);

    bool isTypeComplete(Type c);

    bool isTypeValid(std::string name,Type c,Expr init);
};

#endif //CP_SEMANT_H
