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

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("TranslationUnitDecl_\n");
        list<Decl>::iterator it;
        for(it = declarations.begin(); it != declarations.end(); it++){
            //printf("%d\n", *it);
            //(*it)->show();
        }
    }
};

struct VarDecl_:public Decl_
{
    Type type;
    Expr init;
};

struct FunctionDecl_:public Decl_
{
    Type returnType;
    list<Decl> parameters;
    Stmt stmt; /*function body, can be null*/

    FunctionDecl_(string name, Type returnType, Stmt stmt):stmt(stmt),
                                                           returnType(returnType){
        this->id = NODE_DECL_FUNCTION;
        this->name=name;
    }

    FunctionDecl_(string name, Type returnType, list<Decl> parameters, Stmt stmt):
            FunctionDecl_(name, returnType, stmt)
    {
        this->id = NODE_DECL_FUNCTION;
        this->parameters = parameters;
    }

    void setParameters(list<Decl> parameters)
    {
        this->parameters = parameters;
    }
};

struct ParmVarDecl_:public Decl_
{
    Type type;
};

struct RecordDecl_:public Decl_
{
    bool struct_; //true = struct, false = union
    list<FieldDecl> fields;
};

struct FieldDecl_:public Decl_
{
    Type type;
};

struct TypedefDecl_:public Decl_
{
    TypedefType type;
};

#endif //COMPILER_DECLARATION_H
