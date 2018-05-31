#include "utils.h"
using namespace std;

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
