//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_FRAME_H
#define CP_FRAME_H

#include <string>
#include "type.h"
#include "constant.h"
#include "translator.h"

typedef unsigned int Register_;
typedef char *Register;
typedef struct Access_ *Access;

struct Access_
{
	enum { InReg, InFrame, InGlobal } kind;
	union {
		int offset; /*InFrame*/
		Register reg; /*In Reg*/
		char *global;
	}u;

	Access_() {
	}

	void putInReg(Register reg)
	{
		kind = InReg;
		u.reg = reg;
	}

	void putInGlobal(char *global)
	{
		kind = InGlobal;
		u.global = global;
	}

	void putInFrame(int offset)
	{
		kind = InFrame;
		u.offset = offset;
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

	}

private:


};

#endif //CP_FRAME_H
