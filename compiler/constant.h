//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H

#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

#define SPACE '-'
#define SYM_HASH_MASK 127

typedef int Identifier;
typedef int BasicOperator;
typedef int BinaryOperator;
typedef int UnaryOperator;
typedef int AssignOperator;

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
const int NODE_EXP_INITLIST=115;
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
const int CONST_TYPE_BUILTIN_LONG_DOUBLE=21;
const int CONST_TYPE_BUILTIN_INVALID=22;


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

const int OP_UNARY_NOT=396; //~
const int OP_UNARY_LOGICAL_NOT=397; //!
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

struct SourceLocation
{
    int line, col;

    SourceLocation(int line, int col):line(line), col(col)
    {

    }

    SourceLocation():SourceLocation(0, 0)
    {

    }

};

struct Node_
{
    Identifier id;

    SourceLocation sourceLoc;

    virtual void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf(" ");
        printf("Node_\n");
    }

    void setSourceLoc(int line, int col)
    {
        sourceLoc.line = line;
        sourceLoc.col = col;
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


enum
{
    SK_Tag,    SK_TypedefName, SK_EnumConstant, SK_Constant, SK_Variable, SK_Temp,
    SK_Offset, SK_String,      SK_Label,        SK_Function, SK_Register
};

enum {
    BOR,//     "|",                    Assign
    BXOR,//    "^",                    Assign
    BAND, //   "&",                    Assign
    LSH,//     "<<",                   Assign
    RSH,//     ">>",                   Assign
    ADD, //    "+",                    Assign
    SUB,//     "-",                    Assign
    MUL, //    "*",                    Assign
    DIV, //    "/",                    Assign
    MOD, //    "%",                    Assign
    NEG, //    "-",                    Assign
    BCOM, //   "~",                    Assign
    JZ, //     "",                     Branch
    JNZ,//     "!",                    Branch
    JE,  //    "==",                   Branch
    JNE,//     "!=",                   Branch
    JG, //     ">",                    Branch
    JL, //     "<",                    Branch
    JGE, //    ">=",                   Branch
    JLE, //    "<=",                   Branch
    JMP, //    "jmp",                  Jump
    IJMP, //   "ijmp",                 IndirectJump
    INC,  //   "++",                   Inc
    DEC, //    "--",                   Dec
    ADDR,//    "&",                    Address
    DEREF,//   "*",                    Deref
    EXTI1,//   "(int)(char)",          Cast
    EXTU1,//   "(int)(unsigned char)", Cast
    EXTI2,//   "(int)(short)",         Cast
    EXTU2,//   "(int)(unsigned short)",Cast
    TRUI1,//   "(char)(int)",          Cast
    TRUI2, //  "(short)(int)",         Cast
    CVTI4F4,// "(float)(int)",         Cast
    CVTI4F8, //"(double)(int)",        Cast
    CVTU4F4,// "(float)(unsigned)",    Cast
    CVTU4F8,// "(double)(unsigned)",   Cast
    CVTF4, //  "(double)(float)",      Cast
    CVTF4I4,// "(int)(float)",         Cast
    CVTF4U4,// "(unsigned)(float)",    Cast
    CVTF8,//   "(float)(double)",      Cast
    CVTF8I4,// "(int)(double)",        Cast
    CVTF8U4, //"(unsigned)(double)",   Cast
    MOV,//     "=",                    Move
    IMOV,//    "*=",                   IndirectMove
    CALL,//    "call",                 Call
    RET, //    "ret",                  Return
    CLR, //    "",                     Clear
    NOP, //    "NOP",                  NOP
};

enum {I1, U1, I2, U2, I4, U4, F4, F8, V, B};

struct Expr_:public Node_
{
    Type type;
    bool lvalue;
    union {
        int i[2];
        float f;
        double d;
        void *p;
    } valueUnion;

    Expr_():type(NULL), lvalue(false){}

    virtual void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("Expr_\n");
    }

    std::string getType()
    {
        //return "NULL";
        if(this->type == NULL)
            return "NULL";
        else
            return this->type->getType();
    }

    bool isConstant()
    {
        if(!type)
            return false;
        return this->id == NODE_EXP_INTLITERAL || this->id == NODE_EXP_CHARLITERAL
                || this->id == NODE_EXP_FLOATLITERAL || this->id == NODE_EXP_STRLITERAL;
    }

    bool isNumberConstant()
    {
        if(!type)
            return false;
        return this->id == NODE_EXP_INTLITERAL || this->id == NODE_EXP_CHARLITERAL
               || this->id == NODE_EXP_FLOATLITERAL;
    }

    bool isIntConstant()
    {
        if(!type)
            return false;
        return this->id == NODE_EXP_INTLITERAL || this->id == NODE_EXP_CHARLITERAL;
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

typedef class Symbol_ *Symbol;
typedef class VariableSymbol_ *VariableSymbol;
typedef class FunctionSymbol_ *FunctionSymbol;
typedef class IrInst_ *IrInst;
typedef class BasicBlock_ *BasicBlock;
typedef class valueDef_ *valueDef;
typedef class valueUse_ *valueUse;


class valueDef_
{
public:
    Symbol dst;
	int op;
	Symbol src1;
	Symbol src2;
    BasicBlock ownBB;

	valueDef link;

    valueDef_():dst(NULL),op(-1),src1(NULL),src2(NULL),ownBB(NULL)
    {

    }
};


class valueUse_
{
public:
	valueDef def;
    valueUse next;
    valueUse_():def(NULL),next(NULL)
    {

    }
};



class Symbol_
{
public:
    int kind;
    Type type;
    std::string name;
    union {
        int i[2];
        float f;
        double d;
        void *p;
    } valueUnion;
    bool addressed;
    Symbol link;
    Symbol_():type(NULL),link(NULL)
    {

    }
    virtual ~Symbol_(){}
};


class VariableSymbol_:public Symbol_
{
public:
    int offset;
    Expr initData;
    valueDef def;
    valueUse uses;
    VariableSymbol_():def(NULL),uses(NULL)
    {
        
    }
};

class FunctionSymbol_:public Symbol_
{
public:
    std::list<Symbol> params;
    std::vector<Symbol> locals;
    BasicBlock entryBB;
    BasicBlock exitBB;

    valueDef valNumTable[16];

    FunctionSymbol_():entryBB(NULL), exitBB(NULL){}
    ~FunctionSymbol_(){
        std::cout<<"~FunctionSymbol_()"<<std::endl;
    }
};

class IrInst_
{
public:
    Type type;
    int opcode;
    Symbol opds[3];// dst src src
    IrInst_(){
        opds[0] = opds[1] = opds[2] = NULL;
    }
};

class BasicBlock_
{
public:
    int reference;
    std::vector<IrInst>insts;
    Symbol symbol;
    BasicBlock_():reference(0), symbol(NULL){}
};


std::string id2name(int id);
//int name2id(std::string name);


typedef struct Node_ *Node;

#endif //COMPILER_CONSTANT_H
