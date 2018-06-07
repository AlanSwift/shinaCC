#ifndef EMITTER_H
#define EMITTER_H
#include <cstdio>
#include <cassert>
#include "constant.h"
#include "translator.h"
#include "allocator.h"
#include <string>
#define DST  inst->opds[0]
#define SRC1 inst->opds[1]
#define SRC2 inst->opds[2]

typedef class Emitter_ *Emitter;

enum ASMCode
{
#define TEMPLATE(code, str) code,
#include "x86win32.tpl"
#undef TEMPLATE
};

#define ASM_CODE(opcode, tcode) ((opcode << 2) + tcode - I4)

extern char *REGS[];
extern char *WREGS[];
extern char *HREGS[];
extern char *BREGS[];
extern char *FP;
extern char *SP;


class Emitter_
{
private:
	FILE *fp;
	Program program;
	Allocator* allocator;
	Symbol X87Top;

public:
	Emitter_()
	{
		X87Top = NULL;
		fp = stdout;
		allocator=new Allocator();
	}

	Emitter_(FILE *fp):fp(fp)
	{
		allocator=new Allocator();
	}

	~Emitter_()
	{

	}

	void emitCode(Program program)
	{
		assert(fp);
		this->program = program;
		allocator->allocate(program);
		fprintf(fp, "\t.text\n");
		for (auto &fsym : program->functionList) {
			emitFunction(fsym);
		}
	}

private:
	void emitFunction(FunctionSymbol fsym)
	{
		fprintf(fp, "\t.globl\t%s\n", fsym->name.c_str());
		fprintf(fp, "\t.seh_proc\t%s\n", fsym->name.c_str());

		int frameSize = calcFrameSize(fsym);

		fprintf(fp, "%s:\n", getAccessName(fsym).c_str());

		emitPrologue(frameSize);

		for (int i = fsym->start; i <= fsym->end; i++) {
			if(i != fsym->start)
				fprintf(fp, "%s:\n", getAccessName(program->bblocks[i]->symbol).c_str());
			emitBasicBlock(program->bblocks[i]);
		}

		emitEpilogue(frameSize);
	}

	void emitBasicBlock(BasicBlock block)
	{
		assert(block);
		allocator->precess(block);
		for (auto &inst : block->insts) {
			emitIrInst(inst);
		}
	}

	void emitAssign(IrInst& inst)
	{

	}

	void emitCast(IrInst& inst)
	{

	}

	void emitBranch(IrInst& inst)
	{

	}

	void emitJump(IrInst& inst)
	{

	}

	void emitReturn(IrInst& inst)
	{

	}

	void emitCall(IrInst& inst)
	{

	}

	void emitAddress(IrInst& inst)
	{

	}

	void emitDeref(IrInst& inst)
	{

	}

	void address(int code, Access access)
	{

	}

	void emitIndirectMove(IrInst& inst)
	{

	}

	std::string getConstant(int code, Symbol s)
	{
		if (code == F4 || code == F8)
			return std::to_string(*((unsigned long long *)(&(s->valueUnion.d))));
		return std::to_string(s->valueUnion.i[0]);
	}

	std::string getAddress(Access access, int bits = 32)
	{
		if (access->kind == access->InReg) {
			if (bits == 32)
				return std::string(WREGS[access->reg]);
			if (bits == 64)
				return std::string(REGS[access->reg]);
			if (bits == 16)
				return std::string(HREGS[access->reg]);
			if (bits == 8)
				return std::string(BREGS[access->reg]);
		}
		else if (access->kind == access->InFrame) {
			return std::to_string(access->offset) + "(%rbp)";
		}
		else
			return access->global;
	}

	void emitMove(IrInst& inst)
	{
		int code = typeCode(inst->type);
		std::string src, dst;
		if (code == F4 || code == F8) {
			assert(0);
			return;
		}
		switch (code)
		{
		case I1: case U1:
			if (SRC1->kind == SK_Constant)
				src = getConstant(code, SRC1);
			else
				src = getAddress(allocator->access(SRC1));
			dst = getAddress(allocator->access(DST));
			fprintf(fp, "\tmovl %s %s\n", src.c_str(), dst.c_str());
			break;

		case I2: case U2:
			/*if (SRC1->kind == SK_Constant)
				Move(X86_MOVI2, DST, SRC1);
			else{
				reg = GetWordReg();
				Move(X86_MOVI2, reg, SRC1);
				Move(X86_MOVI2, DST, reg);
			}*/
			break;

		case I4: case U4:
			/*if (SRC1->kind == SK_Constant)
				Move(X86_MOVI4, DST, SRC1);
			else {
				AllocateReg(inst, 1);
				AllocateReg(inst, 0);
				if (SRC1->reg == NULL && DST->reg == NULL) {
					reg = GetReg();
					Move(X86_MOVI4, reg, SRC1);
					Move(X86_MOVI4, DST, reg);
				}
				else {
					Move(X86_MOVI4, DST, SRC1);
				}
			}*/
		default:
			break;
		}
	}

	void emitIrInst(IrInst inst)
	{
		switch (inst->opcode) {
		case BOR:case BXOR:case BAND:case LSH:case RSH:case ADD:
		case SUB:case MUL:case DIV:case MOD:case NEG:case BCOM:
			emitAssign(inst); break;
		case JZ:case JNZ:case JG:case JL:case JGE:case JLE:
			emitBranch(inst); break;
		case JMP:
			emitJump(inst); break;
		case ADDR:
			emitAddress(inst); break;
		case DEREF:
			emitDeref(inst);break;
		case RET:
			emitReturn(inst);break;
		case CALL:
			emitCall(inst);break;
		case MOV:
			emitMove(inst);break;
		case IMOV:
			emitIndirectMove(inst);break;
		default:
			emitCast(inst);
		}
	}

	void emitPrologue(int size)
	{
		fprintf(fp, "\tpushq\t%rbq\n");
		fprintf(fp, "\t.seh_pushreg	%rbp\n");
		fprintf(fp, "\tmovq	%rsp, %rbp\n");
		fprintf(fp, "\t.seh_setframe\t%rbp, 0\n");
		fprintf(fp, "\tsubq	$%d, %rsp\n", size);
		fprintf(fp, "\t.seh_stackalloc	%d\n", size);
		fprintf(fp, "\t.seh_endprologuep\n");
	}

	void emitEpilogue(int size)
	{
		fprintf(fp, "\taddq	$%d, %rsp\n", size);
		fprintf(fp, "\tpopq	%rbp\n");
		fprintf(fp, "\tret\n");
		fprintf(fp, "\t.seh_endproc\n");
	}

	int calcFrameSize(FunctionSymbol fsym)
	{
		return 0;
	}

	std::string getAccessName(Symbol symbol)
	{
		switch (symbol->kind) {
		case SK_Label:case SK_Function:case SK_Constant:
			return symbol->name;
		case SK_String:
			return std::string((char *)symbol->valueUnion.p);
		}
	}

	int sizeOf(Type type)
	{
		assert(type != BuiltinType_::voidType);
		if (type == BuiltinType_::intType || type == BuiltinType_::unsignedIntType || type == BuiltinType_::longType || type == BuiltinType_::unsignedLongType)
			return 4;
		if (type == BuiltinType_::unsignedCharType || type == BuiltinType_::charType)
			return 1;
		if (type == BuiltinType_::unsignedShortType || type == BuiltinType_::shortType)
			return 2;
		if (type == BuiltinType_::floatType)
			return 4;
		if (type == BuiltinType_::doubleType || type == BuiltinType_::longDoubleType)
			return 8;
		if (type->id == CONST_TYPE_ARRAY)
			return sizeOf(dynamic_cast<ArrayType>(type)->basicType) * dynamic_cast<ArrayType>(type)->size->valueUnion.i[0];
		if (type->id == CONST_TYPE_POINTER || type->id == CONST_TYPE_FUNC)
			return 8;
	}

	int typeCode(Type type)
	{
		if (type == BuiltinType_::intType || type == BuiltinType_::longType)
			return I4;
		else if (type == BuiltinType_::unsignedIntType || type == BuiltinType_::unsignedLongType)
			return U4;
		else if (type == BuiltinType_::shortType)
			return I2;
		else if (type == BuiltinType_::unsignedShortType)
			return U2;
		else if (type == BuiltinType_::charType)
			return I1;
		else if (type == BuiltinType_::unsignedCharType)
			return U1;
		else if (type == BuiltinType_::floatType)
			return F4;
		else if (type == BuiltinType_::doubleType || type == BuiltinType_::longDoubleType)
			return F8;
		else if (type->id == CONST_TYPE_POINTER)
			return P;
		assert(type == BuiltinType_::voidType);
		return V;
	}
};
#endif
