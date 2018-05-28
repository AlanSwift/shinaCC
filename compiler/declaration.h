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

struct VarDecl_;
struct FunctionDecl_;
struct ParmVarDecl_;
struct RecordDecl_;
struct FieldDecl_;
struct TypedefDecl_;
struct TranslationUnitDecl_;

typedef struct VarDecl_ *VarDecl;
typedef struct FunctionDecl_ *FunctionDecl;
typedef struct ParmVarDecl_ *ParmVarDecl;
typedef struct RecordDecl_ *RecordDecl;
typedef struct FieldDecl_ *FieldDecl;
typedef struct TypedefDecl_ *TypdefDecl;
typedef struct TranslationUnitDecl_ *TranslationUnitDecl;

struct TranslationUnitDecl_:public Decl_
{
    list<Decl> declarations;

    TranslationUnitDecl_()
    {
        this->id = NODE_DECL_TRANSLATION;
    }

    TranslationUnitDecl_(list<Decl> &declarations):TranslationUnitDecl_()
    {
        this->declarations = declarations;
    }

    bool addDeclaration(Decl decl)
    {
        declarations.push_back(decl);
        return true;
    }

};

struct VarDecl_:public Decl_
{
    Type type;
    string name;
    Expr init;
};

struct FunctionDecl_:public Decl_
{
    string name;
    Type returnType;
    list<ParmVarDecl> parameters;
    Stmt stmt; /*function body, can be null*/

    FunctionDecl_(string name, Type returnType, Stmt stmt):stmt(stmt), name(name),
                                                           returnType(returnType){
        this->id = NODE_DECL_FUNCTION;
    }

    FunctionDecl_(string name, Type returnType, list<ParmVarDecl> parameters, Stmt stmt):
            FunctionDecl_(name, returnType, stmt)
    {
        this->parameters = parameters;
    }

    void setParameters(list<ParmVarDecl> parameters)
    {
        this->parameters = parameters;
    }
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
