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
        printf("BuiltinType_: %s\n", id2name(this->builtinType).c_str());
    }
};

struct PointerType_:public Type_
{
    Type pointTo;
    PointerType_(Type pointTo):pointTo(pointTo){
        this->id = CONST_TYPE_POINTER;
    }
};

struct RecordType_:public Type_
{
    bool isStruct;
    string id;
    RecordType_(string id, bool isStruct):isStruct(isStruct), id(id){
        this->id = CONST_TYPE_RECORD;
    }
};

struct ArrayType_:public Type_
{
    Expr size;
    Type basicType;
    ArrayType_(Type basicType, Expr size):size(size), basicType(basicType){
        this->id = CONST_TYPE_ARRAY;
    }
};

struct FunctionType_:public Type_
{
    Type returnType;
    list<Type> argsType;
    string id;

    FunctionType_(string id, Type returnType){
        this->id = CONST_TYPE_FUNC;
    }

    FunctionType_(string id, Type returnType, list<Type> &argsType):FunctionType_(id, returnType){
        this->argsType = argsType;
    }
};

struct TypedefType_:public Type_
{
    string ref;
    Type typedef_;

    TypedefType_(string ref, Type typedef_):ref(ref), typedef_(typedef_){
        this->id = CONST_TYPE_TYPEDEF;
    }
};

#endif //COMPILER_TYPE_H
