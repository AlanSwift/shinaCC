//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H

#include <string>
#include <cstdio>

#define SPACE '-'

typedef int A_identifier;
typedef int BasicOperator;
typedef int BinaryOperator;
typedef int UnaryOperator;
typedef int AssignOperator;



struct Node_
{
    A_identifier id;
    virtual void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf(" ");
        printf("Node_\n");
    }
};

typedef struct Type_ *Type;
typedef struct Decl_ *Decl;
typedef struct Stmt_ *Stmt;
typedef struct Expr_ *Expr;

struct Type_:public Node_
{
    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("Type_\n");
    }
    virtual void add2Tail(Type c)
    {

    }

    virtual std::string getType()
    {
        return "AbstractType";
    }
};


struct Stmt_:public Node_
{
    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("Stmt_\n");
    }
};

struct Expr_:public Node_
{
    Type type;

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("Expr_\n");
    }
};

struct Decl_:public Node_
{
    std::string name;
    Decl_()
    {

    }
    virtual void add2Tail(Type c)
    {

    }
    void show(int space=0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("Decl_\n");
    }
};




const int CONST_TYPE_POINTER=1;
const int CONST_TYPE_RECORD=2;
const int CONST_TYPE_ARRAY=3;
const int CONST_TYPE_FUNC=4;
const int CONST_TYPE_TYPEDEF=5;


const int CONST_TYPE_BUILTIN=6;
const int CONST_TYPE_BUILTIN_VOID=7;

const int CONST_TYPE_BUILTIN_CHAR=8;
const int CONST_TYPE_BUILTIN_SIGNED_CHAR=8;

const int CONST_TYPE_BUILTIN_UNSIGNED_CHAR=9;

const int CONST_TYPE_BUILTIN_SHORT=10;
const int CONST_TYPE_BUILTIN_SIGNED_SHORT=10;

const int CONST_TYPE_BUILTIN_UNSIGNED_SHORT=11;
const int CONST_TYPE_BUILTIN_INT=12;
const int CONST_TYPE_BUILTIN_SIGNED_INT=12;
const int CONST_TYPE_BUILTIN_UNSIGNED_INT=13;
const int CONST_TYPE_BUILTIN_LONG=14;
const int CONST_TYPE_BUILTIN_LONG_INT=14;
const int CONST_TYPE_BUILTIN_SIGNED_LONG=14;
const int CONST_TYPE_BUILTIN_SIGNED_LONG_INT=14;
const int CONST_TYPE_BUILTIN_UNSIGNED_LONG=15;
const int CONST_TYPE_BUILTIN_UNSIGNED_LONG_INT=15;
const int CONST_TYPE_BUILTIN_ENUM=16;

const int CONST_TYPE_BUILTIN_SIGNED=17;
const int CONST_TYPE_BUILTIN_UNSIGNED=18;
const int CONST_TYPE_BUILTIN_FLOAT=19;
const int CONST_TYPE_BUILTIN_DOUBLE=20;

const int NODE_EXP_PAREN=100;
const int NODE_EXP_BINARY=101;
const int NODE_EXP_UNARY=102;
const int NODE_EXP_CONDITIONAL=103;
const int NODE_EXP_ASSIGN=104;
const int NODE_EXP_CALL=105;
const int NODE_EXP_MEMBER=106;
const int NODE_EXP_ARRAYSUBSCRIPT=107;
const int NODE_EXP_DECLREF=108;
const int NODE_EXP_IMPLICITCAST=109;
const int NODE_EXP_CSTYLECAST=110;
const int NODE_EXP_INTLITERAL=111;
const int NODE_EXP_CHARLITERAL=112;
const int NODE_EXP_FLOATLITERAL=113;
const int NODE_EXP_STRLITERAL=114;


const int NODE_DECL_VAR=200;
const int NODE_DECL_FUNCTION=201;
const int NODE_DECL_PARMVAR=202;
const int NODE_DECL_RECORD=203;
const int NODE_DECL_FIELD=204;
const int NODE_DECL_TYPEDEF=205;
const int NODE_DECL_TRANSLATION=206;
const int NODE_DECL_FATHER=207;


const int NODE_STM_BREAK=300;
const int NODE_STM_CONTINUE=301;
const int NODE_STM_COMPOUND=302;
const int NODE_STM_DO=303;
const int NODE_STM_WHILE=304;
const int NODE_STM_FOR=305;
const int NODE_STM_GOTO=306;
const int NODE_STM_IF=307;
const int NODE_STM_LABEL=308;
const int NODE_STM_RETURN=309;
const int NODE_STM_SWITCH=310;
const int NODE_STM_CASE=311;
const int NODE_STM_DEFAULT=312;
const int NODE_STM_EXPR=313;
const int NODE_STM_DECL=314;
const int NODE_STM_NULL=315;

const int OP_UNARY_NOT=398; //~
const int OP_UNARY_LOGICAL_NOT=398; //!
const int OP_UNARY_POSITIVE=398; //+
const int OP_UNARY_NEGATIVE=399; //-
const int OP_UNARY_CAST=400;
const int OP_UNARY_STAR=401;//*
const int OP_UNARY_AND=402;//&
const int OP_UNARY_DOUBLEADD=403;//++
const int OP_UNARY_DOUBLEMINUS=404;//--
const int OP_UNARY_SIZEOF=405;

const int OP_BINARY_MULTIPLY=406;
const int OP_BINARY_DIV=407;
const int OP_BINARY_MOD=408;
const int OP_BINARY_ADD=409;
const int OP_BINARY_MINUS=410;
const int OP_BINARY_SHIFTLEFT=411;//<<
const int OP_BINARY_SHIFTRIGHT=412;//>>
const int OP_BINARY_GT=413;//>
const int OP_BINARY_ST=414;//<
const int OP_BINARY_BE=415;//>=
const int OP_BINARY_SE=416;//<=
const int OP_BINARY_EQ=417;//==
const int OP_BINARY_NEQ=418;//!=
const int OP_BINARY_AND=419;// 1&2
const int OP_BINARY_OR=420;// 1|2
const int OP_BINARY_XOR=421;// 1^2
const int OP_BINARY_LOGICAL_AND=422;//&&
const int OP_BINARY_LOGICAL_OR=423;// ||
const int OP_BINARY_COMMA=424;// ,

const int OP_ASSIGN_EQ=430;// =
const int OP_ASSIGN_EQ_ADD=431;//+=
const int OP_ASSIGN_EQ_MINUS=432;
const int OP_ASSIGN_EQ_MULTIPLY=433;
const int OP_ASSIGN_EQ_DIV=434;
const int OP_ASSIGN_EQ_MOD=435;
const int OP_ASSIGN_EQ_AND=436;
const int OP_ASSIGN_EQ_XOR=437;
const int OP_ASSIGN_EQ_OR=438;
const int OP_ASSIGN_EQ_SHIFTLEFT=439;
const int OP_ASSIGN_EQ_SHIFTRIGHT=440;

std::string id2name(int id);
//int name2id(std::string name);


typedef struct Node_ *Node;

#endif //COMPILER_CONSTANT_H
