//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_DECLARATION_H
#define COMPILER_DECLARATION_H

#include <list>
#include "statement.h"
#include "type.h"
#include "constant.h"
using namespace std;

typedef struct CompoundStmt_ *CompoundStmt;

struct Decl_;
struct VarDecl_;
struct FunctionDecl_;
struct ParmVarDecl_;
struct RecordDecl_;
struct FieldDecl_;
struct TypedefDecl_;

typedef struct Expr_ *Expr;
typedef struct Decl_ *Decl;

typedef struct VarDecl_ *VarDecl;
typedef struct FunctionDecl_ *FunctionDecl;
typedef struct ParmVarDecl_ *ParmVarDecl;
typedef struct RecordDecl_ *RecordDecl;
typedef struct FieldDecl_ *FieldDecl;
typedef struct TypedefDecl_ *TypdefDecl;


struct Decl_:public Node_
{

};

struct VarDecl_:public Decl_
{
    Type type;
    string name;
    Expr init;
};

struct FunctionDecl_:public Decl_
{
    Type returnType;
    list<ParmVarDecl> parameters;
    CompoundStmt stmt; /*function body, can be null*/
};

struct ParmVarDecl_:public Decl_
{
    Type type;
    string name;
};

struct RecordDecl_:public Decl_
{
    bool struct_; //true = struct, false = union
    list<FieldDecl> fields;
};

struct FieldDecl_:public Decl_
{
    Type type;
    string name;
};

struct TypedefDecl_:public Decl_
{
    TypedefType type;
};

#endif //COMPILER_DECLARATION_H
