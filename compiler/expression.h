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
    ParenExpr_(Expr expr):expr(expr){ this->id = NODE_EXP_PAREN; }
};

struct BinaryOpExpr_:public Expr_
{
    BinaryOperator operator_;
    Expr left, right;

    BinaryOpExpr_(Expr left, BinaryOperator operator_, Expr right):left(left), right(right),
                                                                   operator_(operator_){
        this->id = NODE_EXP_BINARY;
    }
};

struct UnaryOpExpr_:public Expr_
{
    UnaryOperator operator_;
    bool postfix;
    Expr expr;

    UnaryOpExpr_(Expr expr, UnaryOperator operator_, bool postfix):expr(expr), operator_(operator_),
                                                                  postfix(postfix){
        this->id = NODE_EXP_UNARY;
    }
};

struct ConditionalExpr_:public Expr_
{
    Expr condition, true_, false_;

    ConditionalExpr_(Expr condition, Expr true_, Expr false_):condition(condition), true_(true_),
                                                               false_(false_){
        this->id = NODE_EXP_CONDITIONAL;
    }
};

struct AssignExpr_:public Expr_
{
    AssignOperator operator_;
    Expr var;
    Expr expr;

    AssignExpr_(Expr var, AssignOperator operator_, Expr expr):var(var), expr(expr),
                                                                      operator_(operator_){
        this->id = NODE_EXP_ASSIGN;
    }
};

struct CallExpr_:public Expr_
{
    Expr func;
    list<Expr> args;

    CallExpr_(Expr func):func(func){
        this->id = NODE_EXP_CALL;
    }

    CallExpr_(Expr func, list<Expr> &args):func(func), args(args){
        this->id = NODE_EXP_CALL;
    }
};

struct MemberExpr_:public Expr_
{
    Expr parent;
    bool isPointer;
    string member;

    MemberExpr_(Expr parent, string member, bool isPointer):parent(parent), isPointer(isPointer),
                                                                   member(member){
        this->id = NODE_EXP_MEMBER;
    }
};

struct ArraySubscriptExpr_:public Expr_
{
    Expr array;
    Expr offset;

    ArraySubscriptExpr_(Expr array, Expr offset):array(array), offset(offset){
        this->id = NODE_EXP_ARRAYSUBSCRIPT;
    }
};


struct DeclRefExpr_:public Expr_
{
    string name;

    DeclRefExpr_(string name):name(name){
        this->id = NODE_EXP_DECLREF;
    }
};

struct ImplicitCastExpr_:public Expr_
{
    Type castType;
    Expr expr;

    ImplicitCastExpr_(Type castType, Expr expr):castType(castType), expr(expr){
        this->id = NODE_EXP_IMPLICITCAST;
    }
};


struct CStyleCastExpr_:public Expr_
{
    Type castType;
    Expr expr;

    CStyleCastExpr_(Type castType, Expr expr):castType(castType), expr(expr){
        this->id = NODE_EXP_CSTYLECAST;
    }
};

struct IntLiteral_:public Expr_
{
    long value;
    IntLiteral_(long value):value(value){
        this->id = NODE_EXP_INTLITERAL;
    }
};

struct CharLiteral_:public Expr_
{
    char value;
    CharLiteral_(char value):value(value){
        this->id = NODE_EXP_CHARLITERAL;
    }
};


struct FloatLiteral_:public Expr_
{
    double value;
    FloatLiteral_(double value):value(value){
        this->id = NODE_EXP_FLOATLITERAL;
    }
};

struct StrLiteral_:public Expr_
{
    string value;
    StrLiteral_(string &value):value(value){this->id = NODE_EXP_STRLITERAL; }
    StrLiteral_(char *value){ this->value = string(value);this->id = NODE_EXP_STRLITERAL;}
};


#endif //COMPILER_EXPRESSION_H
