//
// Created by Alan on 18/05/2018.
//

#ifndef CODE_ABSYN_H
#define CODE_ABSYN_H
#include <iostream>
#include <string>
#include "symbol.h"

extern char * yytext;
extern int yylineno;
using namespace std;

//Assert:  This all is for tiger. They all remains to be fit for C.



// enum definition
enum spec_type{
    TS, // type specifier 类型说明符
    SC, // storage class  存储类型
    TQ  // type qualifier 类型限定
};

enum type_specs{
    TS_VOID, TS_CHAR, TS_SHORT, TS_INT, TS_LONG,
    TS_FLOAT, TS_DOUBLE, TS_BOOL, TS_COMPLEX,
    TS_STRUCT, TS_ENUM, TS_TYPENAME,
    TS_SIGNED, TS_UNSIGNED,
    TS_COUNT
};

enum storage_classes {
    SC_AUTO, SC_TYPEDEF, SC_EXTERN, SC_STATIC, SC_REGISTER, SC_COUNT
};

enum type_quals {
    TQ_CONST, TQ_RESTRICT, TQ_VOLATILE, TQ_COUNT
};

enum A_op{
    A_plusOp, A_minusOp, A_timesOp, A_divideOp,
    A_eqOp, A_neqOp, A_ltOp, A_leOp, A_gtOp, A_geOp
} ;
struct A_var_;
struct A_exp_;


typedef int A_pos;
typedef A_var_* A_var;
typedef A_exp_* A_exp;

struct A_var_
{
    enum {A_simpleVar, A_fieldVar, A_subscriptVar} kind;
    A_pos pos;
    union {
        S_symbol simple;
        struct
        {
            A_var var;
            S_symbolList symList;
        } field;//TODO: Whether symList is right  Alan
        struct
        {
            A_var var;
            A_exp exp;
        } subscript;
    } u;
};

struct A_exp_
{
    //TODO:
    A_exp_();

    enum {A_varExp, A_nilExp, A_intExp, A_callExp,
        A_opExp, A_structExp,A_unionExp, A_seqExp /*comma exp*/, A_assignExp, A_ifExp,
        A_whileExp,A_dowhileExp, A_forExp, A_breakExp,A_continueExp,A_gotoExp, A_arrayExp,A_pointerExp} kind;
    A_pos pos;
    union {A_var var;
        /* nil; - needs only the pos */
        int intt;
        string stringg;
        struct {S_symbol func; A_expList args;} call;
        struct {A_oper oper; A_exp left; A_exp right;} op;
        struct {S_symbol typ; A_efieldList fields;} record;
        A_expList seq;
        struct {A_var var; A_exp exp;} assign;
        struct {A_exp test, then, elsee;} iff; /* elsee is optional */
        struct {A_exp test, body;} whilee;
        struct {S_symbol var; A_exp lo,hi,body; bool escape;} forr;
        /* break; - need only the pos */
        struct {A_decList decs; A_exp body;} let;
        struct {S_symbol typ; A_exp size, init;} array;
    } u;
};

class A_expList_{

};

struct A_dec_
{enum {A_functionDec, A_varDec, A_typeDec} kind;
    A_pos pos;
    union {A_fundecList function;
        /* escape may change after the initial declaration */
        struct {S_symbol var; S_symbol typ; A_exp init; bool escape;} var;
        A_nametyList type;
    } u;
};

class A_decList_{

};

struct A_ty_ {enum {A_typedefTy, A_structTy,A_unionTy, A_arrayTy} kind;
    A_pos pos;
    union {S_symbol name;
        A_fieldList record;
        S_symbol array;
    } u;
};





#endif
