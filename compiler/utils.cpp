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
