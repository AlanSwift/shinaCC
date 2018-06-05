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
            (*it)->show(space+1);
        }
    }
};

struct VarDecl_:public Decl_
{
    Type type;
    Expr init;
    VarDecl_(Type type,Expr init):
            type(type),init(init)
    {
        this->id=NODE_DECL_VAR;
    }
    void add2Tail(Type c) override
    {
        if(!type)
        {
            type=c;
        }
        else{
            type->add2Tail(c);
        }
    }
    void show(int space=0) override
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("VarDecl_: %s, %s\n", this->name.c_str(), type->getType().c_str());

        if(init)
            init->show(space + 1);
        if(type)
        {
            //type->show(space+1);
        }
        else{
            printf("*******************null_ptr************************\n");
        }
    }
};

struct FunctionDecl_:public Decl_
{
    Type returnType;
    list<Decl> parameters;
    Stmt stmt; /*function body, can be null*/
    FunctionSymbol functionSymbol;
    FunctionDecl_(string name, Type returnType, Stmt stmt):stmt(stmt),
                                                           returnType(returnType){
        this->id = NODE_DECL_FUNCTION;
        this->name=name;
        functionSymbol = NULL;
    }

    FunctionDecl_(string name, Type returnType, list<Decl> parameters, Stmt stmt):
            FunctionDecl_(name, returnType, stmt)
    {
        this->parameters = parameters;
    }

    bool hasParameters()
    {
        return parameters.size();
    }

    void setParameters(list<Decl> parameters)
    {
        this->parameters = parameters;
    }
    void show(int space=0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        //exit(0);
        printf("FunctionDecl_: %s, %s, %08x\n", this->name.c_str(), returnType->getType().c_str(), functionSymbol);
        /*if(returnType)
        {
            returnType->show(space+1);
        }*/
        for(auto &i:parameters)
        {
            i->show(space+1);
        }
        if(stmt)
            stmt->show(space + 1);
    }
    void add2Tail(Type c) override
    {
        if(!returnType)
        {
            returnType=c;
        }
        else{
            returnType->add2Tail(c);
        }
    }
};

struct ParmVarDecl_:public Decl_
{
    Type type;
    ParmVarDecl_(string name,Type type):
            type(type)
    {
        this->name=name;
        this->id=NODE_DECL_PARMVAR;
    }
    ParmVarDecl_(Type type):type(type)
    {
        this->id=NODE_DECL_PARMVAR;
    }

    void show(int space=0)
    {
        
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        if(type){
            printf("ParmVarDecl_: %s, %s\n", this->name.c_str(), type->getType().c_str());
        }
        else
            printf("ParmVarDecl_: %s, null\n", this->name.c_str());
    }
    void add2Tail(Type c) override
    {
        if(!type)
        {
            type=c;
        }
        else{
            type->add2Tail(c);
        }
    }
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
