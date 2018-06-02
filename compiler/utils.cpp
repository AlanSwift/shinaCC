#include "utils.h"
#include "expression.h"
using namespace std;

Expr doBinaryOp(Expr expr1, int op, Expr expr2)
{
    if(expr1->isNumberConstant() && expr2->isNumberConstant()){
        long lvalue1, lvalue2;
        double fvalue1, fvalue2;
        bool l1 = false, l2 = false;
        long result1;
        double result2;
        if(expr1->type == BuiltinType_::doubleType)
            fvalue1 = ((FloatLiteral)expr1)->value;
        else if(expr1->type == BuiltinType_::intType)
            lvalue1 = ((IntLiteral)expr1)->value, l1 = true;
        else
            lvalue1 = ((CharLiteral)expr1)->value, l1 = true;
        if(expr2->type == BuiltinType_::doubleType)
            fvalue2 = ((FloatLiteral)expr2)->value;
        else if(expr2->type == BuiltinType_::intType)
            lvalue2 = ((IntLiteral)expr2)->value, l2 = true;
        else
            lvalue2 = ((CharLiteral)expr2)->value, l2 = true;
        if(l1 && l2){
            switch (op){
                case OP_BINARY_MULTIPLY:
                    result1 = lvalue1 * lvalue2;
                    break;
                case OP_BINARY_DIV:
                    result1 = lvalue1 / lvalue2;
                    break;
                case OP_BINARY_MOD:
                    result1 = lvalue1 % lvalue2;
                    break;
                case OP_BINARY_ADD:
                    result1 = lvalue1 + lvalue2;
                    break;
                case OP_BINARY_MINUS:
                    result1 = lvalue1 - lvalue2;
                    break;
                case OP_BINARY_SHIFTLEFT:
                    result1 = lvalue1 << lvalue2;
                    break;
                case OP_BINARY_SHIFTRIGHT:
                    result1 = lvalue1 >> lvalue2;
                    break;
                case OP_BINARY_GT:
                    result1 = lvalue1 > lvalue2;
                    break;
                case OP_BINARY_ST:
                    result1 = lvalue1 < lvalue2;
                    break;
                case OP_BINARY_BE:
                    result1 = lvalue1 >= lvalue2;
                    break;
                case OP_BINARY_SE:
                    result1 = lvalue1 <= lvalue2;
                    break;
                case OP_BINARY_EQ:
                    result1 = lvalue1 == lvalue2;
                    break;
                case OP_BINARY_NEQ:
                    result1 = lvalue1 != lvalue2;
                    break;
                case OP_BINARY_AND:
                    result1 = lvalue1 & lvalue2;
                    break;
                case OP_BINARY_OR:
                    result1 = lvalue1 | lvalue2;
                    break;
                case OP_BINARY_XOR:
                    result1 = lvalue1 ^ lvalue2;
                    break;
                case OP_BINARY_LOGICAL_AND:
                    result1 = lvalue1 && lvalue2;
                    break;
                case OP_BINARY_LOGICAL_OR:
                    result1 = lvalue1 || lvalue2;
                    break;
                default:
                    return NULL;
            }
            delete expr1;
            delete expr2;
            return new IntLiteral_(result1);
        }
        else{
            if(l1) fvalue1 = lvalue1;
            if(l2) fvalue2 = lvalue2;
            switch (op){
                case OP_BINARY_MULTIPLY:
                    result2 = fvalue1 * fvalue2;
                    break;
                case OP_BINARY_DIV:
                    result2 = fvalue1 / fvalue2;
                    break;
                case OP_BINARY_ADD:
                    result2 = fvalue1 + fvalue2;
                    break;
                case OP_BINARY_MINUS:
                    result2 = fvalue1 - fvalue2;
                    break;
                case OP_BINARY_GT:
                    result2 = fvalue1 > fvalue2;
                    break;
                case OP_BINARY_ST:
                    result2 = fvalue1 < fvalue2;
                    break;
                case OP_BINARY_BE:
                    result2 = fvalue1 >= fvalue2;
                    break;
                case OP_BINARY_SE:
                    result2 = fvalue1 <= fvalue2;
                    break;
                case OP_BINARY_EQ:
                    result2 = fvalue1 == fvalue2;
                    break;
                case OP_BINARY_NEQ:
                    result2 = fvalue1 != fvalue2;
                    break;
                case OP_BINARY_LOGICAL_AND:
                    result2 = fvalue1 && fvalue2;
                    break;
                case OP_BINARY_LOGICAL_OR:
                    result2 = fvalue1 || fvalue2;
                    break;
                default:
                    return NULL;
            }
            delete expr1;
            delete expr2;
            return new FloatLiteral_(result2);
        }
    }
    return NULL;
}

Expr doUnaryOp(Expr expr1, int op)
{
    if(expr1->isIntConstant()){

    }
}

bool isRelationalOp(int op)
{
    if(op == OP_BINARY_BE || op == OP_BINARY_GT || op == OP_BINARY_ST
            ||op == OP_BINARY_SE || op == OP_BINARY_EQ || op == OP_BINARY_NEQ)
        return true;
    return false;
}

bool isLogicalOp(int op)
{
    if(op == OP_BINARY_LOGICAL_OR || op == OP_BINARY_LOGICAL_AND
            || op == OP_UNARY_LOGICAL_NOT)
        return true;
    return false;
}

bool isBitWiseOp(int op)
{
    if(op == OP_UNARY_NOT || op == OP_BINARY_AND || op == OP_BINARY_XOR
    || op == OP_BINARY_OR)
            return true;
    return false;
}

bool canFloatIn(int op)
{
    if(isBitWiseOp(op) || op == OP_BINARY_MOD || op == OP_BINARY_SHIFTLEFT ||
            op == OP_BINARY_SHIFTRIGHT)
        return false;
    return true;
}

bool isMatchType(Type a,Type b)
{
    if(a->id!=b->id)
    {
        return false;
    }
    switch(a->id)
    {
        case CONST_TYPE_POINTER:
        {
            return isMatchPointerType(
                (PointerType) a,
                (PointerType) b
            );
        }
        case CONST_TYPE_ARRAY:
        {
            return isMatchArrayType(
                (ArrayType) a,
                (ArrayType) b
            );
        }
        case CONST_TYPE_FUNC:
        {
            return isMatchFunctionType(
                (FunctionType) a,
                (FunctionType) b
            );
        }
        case CONST_TYPE_BUILTIN:
        {
            return isMatchBuiltinType(
                (BuiltinType) a,
                (BuiltinType) b

            );
        }
        default:
        {
            assert(0);
        }
    }

}

bool isMatchFunctionType(FunctionType a,FunctionType b)
{
    //TODO
    assert(a->returnType);
    assert(b->returnType);
    if(!isMatchType(a->returnType,b->returnType))
    {
        return false;
    }
    if(a->argsType.size()!=b->argsType.size())
    {
        return false;
    }
    auto iterA=a->argsType.begin();
    auto iterB=b->argsType.begin();
    while(iterA!=a->argsType.end())
    {
        if(!isMatchType(*iterA,*iterB))
        {
            return false;
        }
        iterA++;
        iterB++;
    }
    return true;
}
bool isMatchBuiltinType(BuiltinType a,BuiltinType b)
{
    //TODO
    assert(a->next==NULL);
    assert(b->next==NULL);
    
    return a->builtinType==b->builtinType;
}
bool isMatchPointerType(PointerType a,PointerType b)
{
    //TODO
    if(a->id!=b->id)
    {
        return false;
    }
    return isMatchType(a->pointTo,b->pointTo);
}
bool isMatchArrayType(ArrayType a,ArrayType b)
{
    //TODO
    return isMatchType(((ArrayType)a)->basicType,((ArrayType)b)->basicType);
}

void freeSpace(Type type)
{
    if(type)
        freeSpace(((BuiltinType)type)->next);
    delete type;
}

void changeType(Type &type, int t)
{
    //printf("\nchange To..............%s\n", id2name(t).c_str());
    freeSpace(type);
    switch (t)
    {
        case CONST_TYPE_BUILTIN_VOID:
            type = BuiltinType_::voidType;
            break;
        case CONST_TYPE_BUILTIN_CHAR:
            type = BuiltinType_::charType;
            break;
        case CONST_TYPE_BUILTIN_UNSIGNED_CHAR:
            type = BuiltinType_::unsignedCharType;
            break;
        case CONST_TYPE_BUILTIN_SHORT:
            type = BuiltinType_::shortType;
            break;
        case CONST_TYPE_BUILTIN_UNSIGNED_SHORT:
            type = BuiltinType_::unsignedShortType;
            break;
        case CONST_TYPE_BUILTIN_INT:
            type = BuiltinType_::intType;
            break;
        case CONST_TYPE_BUILTIN_UNSIGNED_INT:
            type = BuiltinType_::unsignedIntType;
            break;
        case CONST_TYPE_BUILTIN_LONG:
            type = BuiltinType_::longType;
            break;
        case CONST_TYPE_BUILTIN_UNSIGNED_LONG:
            type = BuiltinType_::unsignedLongType;
            break;
        case CONST_TYPE_BUILTIN_FLOAT:
            type = BuiltinType_::floatType;
            break;
        case CONST_TYPE_BUILTIN_DOUBLE:
            type = BuiltinType_::doubleType;
            break;
        case CONST_TYPE_BUILTIN_LONG_DOUBLE:
            type = BuiltinType_::longDoubleType;
            break;
        case CONST_TYPE_BUILTIN_INVALID:
            type = BuiltinType_::invalidType;
            break;
        default:
            type = BuiltinType_::invalidType;
            break;
    }
}

bool checkType(Type &type)
{
    //printf("\nbegin to check..............%s\n", type->getType().c_str());
    switch (type->id)
    {
        case CONST_TYPE_BUILTIN:
        {
            BuiltinType now_BuiltinType = reinterpret_cast<BuiltinType>(type);
            BuiltinType next_BuiltinType = reinterpret_cast<BuiltinType>((now_BuiltinType)->next);
            switch ((now_BuiltinType)->builtinType)
            {
                case CONST_TYPE_BUILTIN_VOID:
                    if (next_BuiltinType != NULL)
                    {
                        printf("void error!");
                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                        return false;
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_VOID);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_CHAR:
                    if (next_BuiltinType != NULL)
                    {
                        switch (next_BuiltinType->builtinType)
                        {
                            case CONST_TYPE_BUILTIN_SIGNED:
                                if (next_BuiltinType->next != NULL)
                                {
                                    printf("signed char error!");
                                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                    return false;
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_CHAR);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_UNSIGNED:
                                if (next_BuiltinType->next != NULL)
                                {
                                    printf("unsigned char error!");
                                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                    return false;
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_CHAR);
                                    return true;
                                }
                            default:
                                printf("char error!");
                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                return false;
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_CHAR);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_SHORT:
                    if (next_BuiltinType != NULL) {
                        switch (next_BuiltinType->builtinType)
                        {
                            case CONST_TYPE_BUILTIN_INT:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    switch (next_BuiltinType->builtinType)
                                    {
                                        case CONST_TYPE_BUILTIN_SIGNED:
                                            if (next_BuiltinType->next != NULL)
                                            {
                                                printf("signed short int error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_SIGNED_SHORT);
                                                return true;
                                            }
                                        case CONST_TYPE_BUILTIN_UNSIGNED:
                                            if (next_BuiltinType->next != NULL)
                                            {
                                                printf("unsigned short int error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_SHORT);
                                                return true;
                                            }
                                        default:
                                            printf("short int error!");
                                            changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                            return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SHORT);
                                    return true;
                                }
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_SHORT);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_INT:
                    if (next_BuiltinType != NULL) {
                        switch (next_BuiltinType->builtinType)
                        {
                            case CONST_TYPE_BUILTIN_SIGNED:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_SHORT) {
                                        changeType(type, CONST_TYPE_BUILTIN_SIGNED_SHORT);
                                        return true;
                                    }
                                    else {
                                        printf("int signed error!");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_INT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_UNSIGNED:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);;
                                    switch (next_BuiltinType->builtinType)
                                    {
                                        case CONST_TYPE_BUILTIN_SHORT:
                                            next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);;
                                            if (next_BuiltinType != NULL) {
                                                printf("int unsigned short error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_SHORT);
                                                return true;
                                            }
                                        case CONST_TYPE_BUILTIN_LONG:
                                            next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);;
                                            if (next_BuiltinType != NULL) {
                                                printf("int unsigned long error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG);
                                                return true;
                                            }
                                        default:
                                            printf("int unsigned error!");
                                            changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                            return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_INT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_SHORT:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);;
                                    switch (next_BuiltinType->builtinType)
                                    {
                                        case CONST_TYPE_BUILTIN_SIGNED:
                                            if (next_BuiltinType->next != NULL) {
                                                printf("int short signed error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_SIGNED_SHORT);
                                                return true;
                                            }
                                        case CONST_TYPE_BUILTIN_UNSIGNED:
                                            if (next_BuiltinType->next != NULL) {
                                                printf("int short unsigned error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_SHORT);
                                                return true;
                                            }
                                        default:
                                            printf("int short error!");
                                            changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                            return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SHORT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_LONG:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_UNSIGNED) {
                                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG_INT);
                                        return true;
                                    }
                                    else {
                                        printf("int long error");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    printf("int long error!");
                                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                    return false;
                                }
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_INT);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_LONG:
                    if (next_BuiltinType != NULL) {
                        switch (next_BuiltinType->builtinType) {
                            case CONST_TYPE_BUILTIN_INT:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    switch (next_BuiltinType->builtinType)
                                    {
                                        case CONST_TYPE_BUILTIN_SIGNED:
                                            if (next_BuiltinType->next != NULL) {
                                                printf("long int signed error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_SIGNED_LONG_INT);
                                                return true;
                                            }
                                        case CONST_TYPE_BUILTIN_UNSIGNED:
                                            if (next_BuiltinType->next != NULL) {
                                                printf("long int unsigned error!");
                                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                                return false;
                                            }
                                            else {
                                                changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG_INT);
                                                return true;
                                            }
                                        default:
                                            printf("long int error!");
                                            changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                            return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_LONG_INT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_SIGNED:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_INT) {
                                        changeType(type, CONST_TYPE_BUILTIN_SIGNED_LONG_INT);
                                        return true;
                                    }
                                    else {
                                        printf("long signed error!");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_LONG);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_UNSIGNED:
                                if (next_BuiltinType->next != NULL)
                                {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_INT) {
                                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG_INT);
                                        return true;
                                    }
                                    else {
                                        printf("long unsigned error!");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_DOUBLE:
                                if (next_BuiltinType->next != NULL) {
                                    printf("long double error!");
                                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                    return false;
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_LONG_DOUBLE); //LONG_DOUBLE
                                    return true;
                                }
                            default:
                                printf("long error!");
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_LONG);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_ENUM:
                    return 0;
                case CONST_TYPE_BUILTIN_SIGNED:
                    if (next_BuiltinType != NULL) {
                        switch (next_BuiltinType->builtinType)
                        {
                            case CONST_TYPE_BUILTIN_INT:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_SHORT) {
                                        changeType(type, CONST_TYPE_BUILTIN_SIGNED_SHORT);
                                        return true;
                                    }
                                    else {
                                        printf("signed int error！");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_INT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_SHORT:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_INT) {
                                        changeType(type, CONST_TYPE_BUILTIN_SIGNED_SHORT);
                                        return true;
                                    }
                                    else {
                                        printf("signed short error！");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_SHORT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_CHAR:
                                if (next_BuiltinType->next != NULL) {
                                    printf("signed char error!");
                                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                    return false;
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_CHAR);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_LONG:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_INT) {
                                        changeType(type, CONST_TYPE_BUILTIN_SIGNED_LONG_INT);
                                        return true;
                                    }
                                    else {
                                        printf("signed long error！");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_SIGNED_LONG);
                                    return true;
                                }
                            default:
                                printf("signed error!");
                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                return false;
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_SIGNED);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_UNSIGNED:
                    if (next_BuiltinType != NULL) {
                        switch (next_BuiltinType->builtinType)
                        {
                            case CONST_TYPE_BUILTIN_INT:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_SHORT) {
                                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_SHORT);
                                        return true;
                                    }
                                    else if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_LONG) {
                                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG_INT);
                                        return true;
                                    }
                                    else {
                                        printf("unsigned int error！");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_INT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_SHORT:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_INT) {
                                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_SHORT);
                                        return true;
                                    }
                                    else {
                                        printf("unsigned short error！");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_SHORT);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_CHAR:
                                if (next_BuiltinType->next != NULL) {
                                    printf("unsigned char error!");
                                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                    return false;
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_CHAR);
                                    return true;
                                }
                            case CONST_TYPE_BUILTIN_LONG:
                                if (next_BuiltinType->next != NULL) {
                                    next_BuiltinType = reinterpret_cast<BuiltinType>((next_BuiltinType)->next);
                                    if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_INT) {
                                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG_INT);
                                        return true;
                                    }
                                    else {
                                        printf("unsigned long error！");
                                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                        return false;
                                    }
                                }
                                else {
                                    changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_LONG);
                                    return true;
                                }
                            default:
                                printf("unsigned error!");
                                changeType(type, CONST_TYPE_BUILTIN_INVALID);
                                return false;
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_UNSIGNED_INT);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_FLOAT:
                    if (next_BuiltinType != NULL) {
                        printf("float error!");
                        changeType(type, CONST_TYPE_BUILTIN_INVALID);
                        return false;
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_FLOAT);
                        return true;
                    }
                case CONST_TYPE_BUILTIN_DOUBLE:
                    if (next_BuiltinType != NULL) {
                        if (next_BuiltinType->builtinType == CONST_TYPE_BUILTIN_LONG) {
                            changeType(type, CONST_TYPE_BUILTIN_LONG_DOUBLE); //LONG_DOUBLE
                        }
                        else {
                            printf("double error!");
                            changeType(type, CONST_TYPE_BUILTIN_INVALID);
                            return false;
                        }
                    }
                    else {
                        changeType(type, CONST_TYPE_BUILTIN_DOUBLE);
                        return true;
                    }
                default:
                    printf("Builtin error!");
                    changeType(type, CONST_TYPE_BUILTIN_INVALID);
                    return false;
            }
        }
        case CONST_TYPE_POINTER:
        {
            Type next_Pointertype = reinterpret_cast<PointerType>(type)->pointTo;
            return checkType(next_Pointertype);
        }
        case CONST_TYPE_ARRAY:
        {
            Type basic_ArrayType = reinterpret_cast<ArrayType>(type)->basicType;
            return checkType(basic_ArrayType);
        }
        case CONST_TYPE_FUNC:
        {
            FunctionType now_FunctionType = reinterpret_cast<FunctionType>(type);
            Type return_FunctionType = now_FunctionType->returnType;
            if (checkType(return_FunctionType)) {
                list<Type>::iterator it;
                for (it = now_FunctionType->argsType.begin(); it != now_FunctionType->argsType.end(); it++) {
                    if (!checkType((*it))) {
                        return false;
                    }
                }
                return true;
            }
            else {
                return false;
            }
        }
        case CONST_TYPE_TYPEDEF:
        {
            Type typedef_Type = reinterpret_cast<TypedefType>(type)->typedef_;
            return checkType(typedef_Type);
        }
        default:
            printf("type error!");
            return false;
    }
    return false;
}
