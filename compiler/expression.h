//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H
#include <string>
#include <list>
#include "type.h"
#include "constant.h"
using namespace std;

//can be modified
struct Expr_;
struct BinaryOpExpr_;
struct ConditionalExpr_;
struct AssignExpr_;
struct CallExpr_;
struct MemberExpr_;
struct ArraySubscriptExpr_;
struct DeclRefExpr_;
struct ImplicitCastExpr_;
struct CStyleCastExpr_;
struct IntLiteral_;
struct CharLiteral_;
struct FloatLiteral_;
struct StrLiteral_;
struct ParenExpr_;

typedef struct Expr_ *Expr;
typedef struct BinaryOpExpr_ *BinaryOpExpr;
typedef struct ConditionalExpr_ *ConditionalExpr;
typedef struct AssignExpr_ *AssignExpr;
typedef struct CallExpr_ *CallExpr;
typedef struct MemberExpr_ *MemberExpr;
typedef struct ArraySubscriptExpr_ *ArraySubscriptExpr;
typedef struct DeclRefExpr_ *DeclRefExpr;
typedef struct ImplicitCastExpr_ *ImplicitCastExpr;
typedef struct CStyleCastExpr_ *CStyleCastExpr;
typedef struct IntLiteral_ *IntLiteral;
typedef struct CharLiteral_ *CharLiteral;
typedef struct FloatLiteral_ *FloatLiteral;
typedef struct StrLiteral_ *StrLiteral;
typedef struct ParenExpr_ *ParenExpr;

struct Expr_:public Node_
{
    Type type;
};

struct ParenExpr_:public Expr_
{
    Expr expr;
    ParenExpr_(Expr expr):expr(expr){}
};

struct BinaryOpExpr_:public Expr_
{
    BinaryOperator operator_;
    Expr left, right;

    BinaryOpExpr_(Expr left, BinaryOperator operator_, Expr right):left(left), right(right),
                                                                   operator_(operator_){}
};

struct UnaryOpExpr_:public Expr_
{
    UnaryOperator operator_;
    bool postfix;
    Expr expr;

    UnaryOpExpr_(Expr expr, UnaryOperator operator_, bool postfix):expr(expr), operator_(operator_),
                                                                  postfix(postfix){}
};

struct ConditionalExpr_:public Expr_
{
    Expr condition, true_, false_;

    ConditionalExpr_(Expr condition, Expr true_, Expr false_):condition(condition), true_(true_),
                                                               false_(false_){}
};

struct AssignExpr_:public Expr_
{
    AssignOperator operator_;
    DeclRefExpr var;
    Expr expr;

    AssignExpr_(DeclRefExpr var, AssignOperator operator_, Expr expr):var(var), expr(expr),
                                                                      operator_(operator_){}
};

struct CallExpr_:public Expr_
{
    DeclRefExpr func;
    list<Expr> args;

    CallExpr_(DeclRefExpr func, list<Expr> &args):func(func), args(args){}
};

struct MemberExpr_:public Expr_
{
    DeclRefExpr parent;
    bool isPointer;
    string member;

    MemberExpr_(DeclRefExpr parent, string member, bool isPointer):parent(parent), isPointer(isPointer),
                                                                   member(member){}
};

struct ArraySubscriptExpr_:public Expr_
{
    DeclRefExpr array;
    Expr offset;

    ArraySubscriptExpr_(DeclRefExpr array, Expr offset):array(array), offset(offset){}
};


struct DeclRefExpr_:public Expr_
{
    string name;

    DeclRefExpr_(string name):name(name){}
};

struct ImplicitCastExpr_:public Expr_
{
    Type castType;
    Expr expr;

    ImplicitCastExpr_(Type castType, Expr expr):castType(castType), expr(expr){}
};


struct CStyleCastExpr_:public Expr_
{
    Type castType;
    Expr expr;

    CStyleCastExpr_(Type castType, Expr expr):castType(castType), expr(expr){}
};

struct IntLiteral_:public Expr_
{
    long value;
    IntLiteral_(long value):value(value){}
};

struct CharLiteral_:public Expr_
{
    char value;
    CharLiteral_(char value):value(value){}
};


struct FloatLiteral_:public Expr_
{
    double value;
    FloatLiteral_(double value):value(value){}
};

struct StrLiteral_:public Expr_
{
    string value;
    StrLiteral_(string &value):value(value){}
    StrLiteral_(char *value){ this->value = string(value);}
};


#endif //COMPILER_EXPRESSION_H
