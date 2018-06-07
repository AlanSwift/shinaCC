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

	Access access(Symbol symbol);


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