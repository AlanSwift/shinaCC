//
// Created by Administrator on 2018/6/4/004.
//

#ifndef CP_TRANSLATOR_H
#define CP_TRANSLATOR_H

#include "constant.h"
#include "expression.h"
#include "declaration.h"
#include "type.h"
#include "statement.h"

typedef class Symbol_ *Symbol;
typedef class IrInst_ *IrInst;
typedef class BasicBlock_ *BasicBlock;
typedef class Translator_ *Translator;
typedef class Program_ *Program;

class Symbol_
{

};

class IrInst_
{

};

class BasicBlock_
{

};

class Program_
{

};

class Translator_
{
public:
    Program translate(TranslationUnitDecl start);
    void translateStatement(Stmt stmt);
    Symbol translateExpression(Expr expr);
private:
    /*translate expression*/
    Symbol translateFunctionCall(CallExpr expr);
    Symbol translateBinaryExpr(BinaryOpExpr expr);
    Symbol translateUnaryExpr(UnaryOpExpr expr);
    Symbol translateIncrement(UnaryOpExpr expr);
    Symbol translateConditionalExpr(ConditionalExpr expr);
    Symbol translateAssignmentExpr(AssignExpr expr);
    Symbol translateCommaExpr(BinaryOpExpr expr);
    Symbol translateCastExpr(Expr expr);
    Symbol translatePrimaryExpr(Expr expr); //id, str, int, float, parentheses
    Symbol translateArrayIndex(ArraySubscriptExpr expr);

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
};

#endif //CP_TRANSLATOR_H
