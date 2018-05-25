//
// Created by Alan on 18/05/2018.
//

#ifndef CODE_ABSYN_H
#define CODE_ABSYN_H
#include <iostream>
#include <string>
#include "symbol.h"
#define A_pos int
extern char * yytext;
extern int yylineno;
using namespace std;

//Assert:  This all is for tiger. They all remains to be fit for C.



// enum definition

enum A_op{
    A_plusOp, A_minusOp, A_timesOp, A_divideOp,
    A_eqOp, A_neqOp, A_ltOp, A_leOp, A_gtOp, A_geOp
} ;

enum E_storage_class_specifier
{
    SC_AUTO, SC_TYPEDEF, SC_EXTERN, SC_STATIC, SC_REGISTER
};
enum E_type_specifier
{
    TS_VOID, TS_CHAR, TS_SHORT, TS_INT, TS_LONG,
    TS_FLOAT, TS_DOUBLE, TS_BOOL, TS_COMPLEX,
    TS_STRUCT, TS_ENUM, TS_TYPENAME,
    TS_SIGNED, TS_UNSIGNED,
    TS_COUNT,
    TS_UNION,
};
enum E_type_qualifier
{
    TQ_CONST, TQ_VOLATILE
};

enum E_declaration_specifier
{
    DS_storage_class_specifier,
    DS_type_specifier,
    DS_type_qualifier
};
struct declaration_specifiers_;
typedef struct A_declaration_specifiers_* A_declaration_specifiers;



typedef struct A_typequalifierlist_* A_typequalifierlist;
struct A_typequalifierlist_
{
    E_type_qualifier content;
    A_typequalifierlist next;
};
A_typequalifierlist A_TypequalifierList(A_pos,A_typequalifierlist lst,E_type_qualifier);



A_declaration_specifiers A_DecSpeciferList(A_pos pos,A_declaration_specifiers lst,E_declaration_specifier type1, int type2);




#endif
