//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_TYPE_H
#define COMPILER_TYPE_H

#include <list>
#include <string>
#include "constant.h"
using namespace std;

typedef struct BuiltinType_ *BuiltinType;
typedef struct PointerType_ *PointerType;
typedef struct RecordType_ *RecordType;
typedef struct ArrayType_ *ArrayType;
typedef struct FunctionType_ *FunctionType;
typedef struct TypedefType_ *TypedefType;

struct BuiltinType_:public Type_
{
    int builtinType;
    Type next;

    BuiltinType_(int builtinType, Type next):builtinType(builtinType), next(next){
        this->id = CONST_TYPE_BUILTIN;
    }

    void show(int space)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("BuiltinType_: %s\n", this->getType().c_str());
    }

    std::string getType()
    {
        std::string result = id2name(this->builtinType);
        if(next)
            result += " " + next->getType();
        return result;
    }
};

struct PointerType_:public Type_
{
    Type pointTo;

    PointerType_(Type pointTo):pointTo(pointTo){
        this->id = CONST_TYPE_POINTER;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("PointerType_: %s\n", this->getType().c_str());
    }

    std::string getType()
    {
        if(this->id == CONST_TYPE_POINTER)
            return pointTo->getType() + " *";
        else
            return pointTo->getType();
    }
};

struct RecordType_:public Type_
{
    bool isStruct;
    string id;
    RecordType_(string id, bool isStruct):isStruct(isStruct), id(id){
        this->id = CONST_TYPE_RECORD;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("RecordType_: %s\n", this->getType().c_str());
    }

    std::string getType()
    {
        return "";
    }
};

struct ArrayType_:public Type_
{
    Expr size;
    Type basicType;
    ArrayType_(Type basicType, Expr size):size(size), basicType(basicType){
        this->id = CONST_TYPE_ARRAY;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("ArrayType_: %s\n", this->getType().c_str());
        size->show(space + 1);
    }

    std::string getType()
    {
        return basicType->getType() + "[]";
    }
};

struct FunctionType_:public Type_
{
    Type returnType;
    list<Type> argsType;

    FunctionType_(Type returnType){
        this->id = CONST_TYPE_FUNC;
    }

    FunctionType_(Type returnType, list<Type> &argsType):FunctionType_(returnType){
        this->argsType = argsType;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("FunctionType_: %s\n");
    }

    std::string getType()
    {
        string result = returnType->getType() + "  (";
        list<Type>::iterator it;
        for(it = args.begin(); it != args.end(); it++){
            result += (*it)->getType() + ", ";
        }
        result += ")";
        return result;
    }
};

struct TypedefType_:public Type_
{
    string ref;
    Type typedef_;

    TypedefType_(string ref, Type typedef_):ref(ref), typedef_(typedef_){
        this->id = CONST_TYPE_TYPEDEF;
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("TypedefType_\n");
    }
};

#endif //COMPILER_TYPE_H
