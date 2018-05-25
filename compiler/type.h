//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_TYPE_H
#define COMPILER_TYPE_H

#include <list>
#include <string>
#include "constant.h"
using namespace std;

typedef struct Type_ *Type;
typedef struct BuiltinType_ *BuiltinType;
typedef struct PointerType_ *PointerType;
typedef struct RecordType_ *RecordType;
typedef struct ArrayType_ *ArrayType;
typedef struct FunctionType_ *FunctionType;
typedef struct TypedefType_ *TypedefType;

struct Type_:public Node_
{

};

struct BuiltinType_:public Type_
{
    int builtinType;
};

struct PointerType_:public Type_
{
    Type pointTo;
};

struct RecordType_:public Type_
{
    bool isStruct;
    string id;
};

struct ArrayType_:public Type_
{
    int size;
    Type basicType;
};

struct FunctionType_:public Type_
{
    Type returnType;
    list<Type> argsType;
};

struct TypedefType_:public Type_
{
    string ref;
    Type typedef_;
};

#endif //COMPILER_TYPE_H
