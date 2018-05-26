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

struct ParenExpr_:public Expr_
{
    Expr expr;
    ParenExpr_(Expr expr):expr(expr){ this->id = NODE_EXP_PAREN; }
    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("ParenExpr_\n");
        expr->show(space + 1);
    }
};

struct BinaryOpExpr_:public Expr_
{
    BinaryOperator operator_;
    Expr left, right;

    BinaryOpExpr_(Expr left, BinaryOperator operator_, Expr right):left(left), right(right),
                                                                   operator_(operator_){
        this->id = NODE_EXP_BINARY;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("BinaryOpExpr_: %d\n", operator_);
        left->show(space + 1);
        right->show(space + 1);
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

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("UnaryOpExpr_: %d\n", operator_);
        expr->show(space + 1);
    }
};

struct ConditionalExpr_:public Expr_
{
    Expr condition, true_, false_;

    ConditionalExpr_(Expr condition, Expr true_, Expr false_):condition(condition), true_(true_),
                                                              false_(false_){
        this->id = NODE_EXP_CONDITIONAL;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("ConditionalExpr_\n");
        condition->show(space + 1);
        true_->show(space + 1);
        false_->show(space + 1);
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

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("AssignExpr_: %d\n", operator_);
        var->show(space + 1);
        expr->show(space + 1);
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

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("CallExpr_\n");
        func->show(space + 1);
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

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        if(isPointer)
            printf("MemberExpr_: ->%s\n", member.c_str());
        else
            printf("MemberExpr_: .%s\n", member.c_str());
        parent->show(space + 1);
    }
};

struct ArraySubscriptExpr_:public Expr_
{
    Expr array;
    Expr offset;

    ArraySubscriptExpr_(Expr array, Expr offset):array(array), offset(offset){
        this->id = NODE_EXP_ARRAYSUBSCRIPT;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("ArraySubscriptExpr_\n");
        array->show(space + 1);
        offset->show(space + 1);
    }
};


struct DeclRefExpr_:public Expr_
{
    string name;

    DeclRefExpr_(string name):name(name){
        this->id = NODE_EXP_DECLREF;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("DeclRefExpr_: %s\n", name.c_str());
    }
};

struct ImplicitCastExpr_:public Expr_
{
    Type castType;
    Expr expr;

    ImplicitCastExpr_(Type castType, Expr expr):castType(castType), expr(expr){
        this->id = NODE_EXP_IMPLICITCAST;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("ImplicitCastExpr_\n");
        expr->show(space + 1);
    }
};


struct CStyleCastExpr_:public Expr_
{
    Type castType;
    Expr expr;

    CStyleCastExpr_(Type castType, Expr expr):castType(castType), expr(expr){
        this->id = NODE_EXP_CSTYLECAST;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("CStyleCastExpr_\n");
        expr->show(space + 1);
    }
};

struct IntLiteral_:public Expr_
{
    long value;
    IntLiteral_(long value):value(value){
        this->id = NODE_EXP_INTLITERAL;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("IntLiteral_: %ld\n", value);
    }
};

struct CharLiteral_:public Expr_
{
    char value;
    CharLiteral_(char value):value(value){
        this->id = NODE_EXP_CHARLITERAL;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("CharLiteral_: %c\n", value);
    }
};


struct FloatLiteral_:public Expr_
{
    double value;
    FloatLiteral_(double value):value(value){
        this->id = NODE_EXP_FLOATLITERAL;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("FloatLiteral_: %.3f\n", value);
    }
};

struct StrLiteral_:public Expr_
{
    string value;
    StrLiteral_(string &value):value(value){this->id = NODE_EXP_STRLITERAL; }
    StrLiteral_(char *value){ this->value = string(value);this->id = NODE_EXP_STRLITERAL;}

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("-");
        printf("StrLiteral_: %.3f\n", value.c_str());
    }
};


#endif //COMPILER_EXPRESSION_H
