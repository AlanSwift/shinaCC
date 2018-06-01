//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_SEMANT_H
#define CP_SEMANT_H

#include "SymbolTable.h"
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
    SymbolTable valueEnv, typeEnv;

    IRTreeNode translateExpr(Expr expr);

    IRTreeNode translateStmt(Stmt stmt);

    IRTreeNode translateDecl(Decl decl);

    Expr transformImplicitExp(Expr expr, int type);

    Expr castFromTo(Expr expr, Type type);
};

#endif //CP_SEMANT_H
