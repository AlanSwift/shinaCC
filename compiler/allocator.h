//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_FRAME_H
#define CP_FRAME_H

#include <string>
#include <map>
#include "type.h"
#include "constant.h"
#include "translator.h"


typedef int Register;
typedef struct Access_ *Access;

struct Access_
{
	enum { InReg, InFrame, InGlobal } kind;
	int offset; /*InFrame*/
	Register reg; /*In Reg*/
	std::string global;

	Access_() 
	{
	}

	void putInReg(Register reg)
	{
		kind = InReg;
		this->reg = reg;
	}

	void putInGlobal(std::string global)
	{
		kind = InGlobal;
		this->global = global;
	}

	void putInFrame(int offset)
	{
		kind = InFrame;
		this->offset = offset;
	}
};

char *FP = "rbp";
char *SP = "rsp";
char *REGS[] = {  "rax", "rcx", "rdx", "rbx", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15" }; //64bit
char *WREGS[] = { "eax", "ecx", "edx", "ebx", "esi", "edi", "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d" }; //32bit
char *HREGS[] = { "ax", "cx", "dx", "bx", "si", "di", "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w" }; //16bit
char *BREGS[] = { "al", "cl", "dl", "bl", "sil", "sil", "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b" }; //8bit

class Allocator
{
public:
	void allocate(Program program)
	{
		
	}

	Access access(Symbol symbol)
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

private:
    bool regUsed[100];
    const int regStart=6;
    const int regEnd=13;
    const int generalCnt=8;

    std::map<std::string,int>stringMap;
    int stringCnt=0;


    void clear()
    {
        memset(regUsed,0,sizeof(regUsed));
    }
    bool isGeneralUsedUp()
    {
        for(int i=regStart;i<=regEnd;i++)
        {
            if(regUsed[i])  return true;
        }
        return false;
    }
    int getFirstReg()
    {
        for(int i=regStart;i<=regEnd;i++)
        {
            if(regUsed[i])  return i;
        }
        assert(0);
    }

};

#endif //CP_FRAME_H
