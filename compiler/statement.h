//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_STATEMENT_H
#define COMPILER_STATEMENT_H

#include <list>
#include <string>
#include "declaration.h"
#include "expression.h"
#include "constant.h"
using namespace std;

typedef struct Decl_ *Decl;

struct Stmt_;
struct BreakStmt_;
struct CompoundStmt_;
struct ContinueStmt_;
struct WhileStmt_;
struct ForStmt_;
struct DoStmt_;
struct GoToStmt_;
struct IfStmt_;
struct LabelStmt_;
struct NullStmt_;
struct ReturnStmt_;
struct SwitchStmt_;
struct CaseStmt_;
struct DefaultStmt_;
struct ExprStmt_;
struct DeclStmt_;


typedef struct Stmt_ *Stmt;
typedef struct BreakStmt_ *BreakStmt;
typedef struct CompoundStmt_ *CompoundStmt;
typedef struct ContinueStmt_ *ContinueStmt;
typedef struct WhileStmt_ *WhileStmt;
typedef struct ForStmt_ *ForStmt;
typedef struct DoStmt_ *DoStmt;
typedef struct GoToStmt_ *GoToStmt;
typedef struct IfStmt_ *IfStmt;
typedef struct LabelStmt_ *LabelStmt;
typedef struct NullStmt_ *NullStmt;
typedef struct ReturnStmt_ *ReturnStmt;
typedef struct SwitchStmt_ *SwitchStmt;
typedef struct CaseStmt_ *CaseStmt;
typedef struct DefaultStmt_ *DefaultStmt;
typedef struct ExprStmt_ *ExprStmt;
typedef struct DeclStmt_ *DeclStmt;

struct Stmt_:public Node_
{

};

struct BreakStmt_:public Stmt_
{

};

struct ContinueStmt_:public Stmt_
{

};

struct CompoundStmt_:public Stmt_
{
    list<Stmt> stmtList;
};

struct DoStmt_:public Stmt_
{
    Stmt stmt;
    Expr expr;
};

struct WhileStmt_:public Stmt_
{
    Expr expr;
    Stmt stmt;
};

struct ForStmt_:public Stmt_
{
    Expr init, condition, next;
};

struct GoToStmt_:public Stmt_
{
    string label;
};

struct IfStmt_:public Stmt_
{
    Expr condition;
    Stmt if_, else_;
};

struct LabelStmt_:public Stmt_
{
    string label;
    Stmt stmt;
};

struct ReturnStmt_:public Stmt_
{
    Expr result;
};

struct SwitchStmt_:public Stmt_
{
    Expr expr;
    Stmt stmt;
};

struct CaseStmt_:public Stmt_
{
    Expr const_;
    Stmt stmt;
};

struct DefaultStmt_:public Stmt_
{
    Stmt stmt;
};

struct ExprStmt_:public Stmt_
{
    Expr expr;
};

struct DeclStmt_:public Stmt_
{
    list<Decl> declarations;
};

struct NullStmt_:public Stmt_
{

};

#endif //COMPILER_STATEMENT_H
