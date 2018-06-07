#include "allocator.h"
char *REGS[] = {  "rax", "rcx", "rdx", "rbx", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15" }; //64bit
char *WREGS[] = { "eax", "ecx", "edx", "ebx", "esi", "edi", "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d" }; //32bit
char *HREGS[] = { "ax", "cx", "dx", "bx", "si", "di", "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w" }; //16bit
char *BREGS[] = { "al", "cl", "dl", "bl", "sil", "sil", "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b" }; //8bit
char *FP = "rbp";
char *SP = "rsp";



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