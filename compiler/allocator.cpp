#include "allocator.h"



Access Allocator::access(Symbol symbol)
{
    assert(symbol!=NULL);
    if(symbol->kind==SK_Function)
    {
        FunctionSymbol funsym=dynamic_cast<FunctionSymbol>(symbol);
        std::string ret="."+funsym->name+"(%rip)";
        Access retAccess=new Access_();
        retAccess->kind=Access_::InGlobal;
        retAccess->global=ret;
        return retAccess;
    }
    else if(symbol->kind==SK_Variable)
    {
        VariableSymbol sym=dynamic_cast<VariableSymbol>(symbol);
        int offset=sizeOf(sym->type);
        
        Access ret=new Access_();
        ret->kind=Access_::InFrame;
        ret->offset=offset;
        return ret;
    }
    else if(symbol->kind==SK_String)
    {
        std::string str=std::string(reinterpret_cast<char*>(symbol->valueUnion.p));
        int cnt;
        if(stringMap.count(str)==0)
        {
            stringMap[str]=stringCnt++;
            //TODO
        }
        else{
            //TODO
        }
        cnt=stringMap[str];
        std::string retStr = std::string(".LC")+std::to_string(cnt)+"(%rip)";
        Access ret=new Access_();
        ret->global=retStr;
        ret->kind=Access_::InGlobal;
        return ret;
    }
    else if(symbol->kind==SK_Temp)
    {
        if(isGeneralUsedUp())
        {
            //spill
            int offset=sizeOf(symbol->type);
            Access ret=new Access_();
            ret->kind= Access_::InFrame;
            ret->offset=offset;
            return ret;
        }
        else{
            int regPosition=getFirstReg();
            regUsed[regPosition]=1;
            Access ret=new Access_();
            ret->kind=Access_::InReg;
            ret->reg=regPosition;
        }
    }

}