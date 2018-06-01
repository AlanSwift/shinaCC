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
    static Type voidType;
    static Type shortType;
    static Type intType;
    static Type longType;
    static Type charType;
    static Type floatType;
    static Type doubleType;
    static Type longDoubleType;
    static Type unsignedShortType;
    static Type unsignedIntType;
    static Type unsignedLongType;
    static Type unsignedCharType;
    static Type invalidType;

    int builtinType;
    Type next;

    BuiltinType_(int builtinType, Type next):builtinType(builtinType), next(next){
        this->id = CONST_TYPE_BUILTIN;
    }
    void add2Tail(Type c)
    {
        if(!next)
        {
            next=c;
        }
        else{
            next->add2Tail(c);
        }
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

    bool isInteger()
    {
        if(builtinType == CONST_TYPE_BUILTIN_DOUBLE || builtinType == CONST_TYPE_BUILTIN_FLOAT
                || builtinType == CONST_TYPE_BUILTIN_LONG_DOUBLE)
            return false;
        return true;
    }
};

struct PointerType_:public Type_
{
    Type pointTo;

    PointerType_(Type pointTo):pointTo(pointTo){
        this->id = CONST_TYPE_POINTER;
    }

    void add2Tail(Type c)
    {
        if(!pointTo)
        {
            pointTo=c;
        }
        else{
            pointTo->add2Tail(c);
        }
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
    void add2Tail(Type c)
    {
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
    void add2Tail(Type c)
    {
        if(!basicType)
        {
            basicType=c;
        }
        else{
            basicType->add2Tail(c);
        }
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("ArrayType_: %s\n", this->getType().c_str());
        if(size)
        {
            size->show(space + 1);
        }
        
    }

    std::string getType()
    {
        
        return basicType->getType() + " []";
    }
};

struct FunctionType_:public Type_
{
    Type returnType;
    list<Type> argsType;
    bool isDefined= false;

    FunctionType_(Type reType):returnType(reType),isDefined(false){
        this->id = CONST_TYPE_FUNC;
    }


    FunctionType_(Type reType, list<Type> &argsType):FunctionType_(reType){

        this->argsType = argsType;
    }

    void add2Tail(Type c)
    {

        if(!returnType)
        {
            returnType=c;
        }
        else{
            returnType->add2Tail(c);
        }
    }

    void show(int space = 0)
    {
        for(int i = 0; i < space; i++)
            printf("%c", SPACE);
        printf("FunctionType_: %s\n",getType().c_str());

    }

    std::string getType()
    {

        string result = returnType->getType() + "  (";

        list<Type>::iterator it;
        for(it = argsType.begin(); it != argsType.end(); it++){
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
