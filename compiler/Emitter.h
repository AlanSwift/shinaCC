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

// enum ASMCode
// {
// #define TEMPLATE(code, str) code,
// #include "x86win32.tpl"
// #undef TEMPLATE
// };

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
		char opCodeNames[][30] = {
			"or", "xor", "and", "sal", "sar", "add", "sub", "imul", "idiv", "idiv",
			"-", "~", "je", "jne", "je", "jne", "jg", "jl", "jge", "jle"
		};
		int code = typeCode(inst->type);
		if (code == F4 || code == F8) {
			assert(0);
			return;
		}
		if (inst->opcode == MUL || inst->opcode == DIV || inst->opcode == MOD) {

		}
		else {
			std::string src1, src2;
			if (SRC1->kind == SK_Constant)
				src1 = getConstant(code, SRC1);
			else {
				Access addr1 = allocator->access(SRC1);
				src1 = getAddress(addr1, 32, true);
			}
			
			if (SRC2->kind == SK_Constant)
				src2 = getConstant(code, SRC2);
			else {
				Access addr2 = allocator->access(SRC2);
				src2 = getAddress(addr2, 32);
			}

			if (code != P) {
				fprintf(fp, "\t%sl %s, %s\n", opCodeNames[inst->opcode], src2.c_str(), src1.c_str());
				fprintf(fp, "\t%movl %s, %s\n", src1.c_str(), 
					getAddress(allocator->access(DST), 32).c_str());
			}
			else {
				assert(0);
			}
		}
	}

	void emitCast(IrInst& inst)
	{

	}

	void emitBranch(IrInst& inst)
	{
		char opCodeNames[][30] = {
			"|", "^", "&", "<<", ">>", "+", "-", "*", "/", "%",
			"-", "~", "je", "jne", "je", "jne", "jg", "jl", "jge", "jle"
		};
		int code = typeCode(inst->type);
		if (code == F4 || code == F8) {
			assert(0);
			return;
		}
		if (SRC2) {
			assert(SRC1->kind != SK_Constant || SRC2->kind != SK_Constant);
			std::string src1, src2;
			if (SRC1->kind == SK_Constant)
				src1 = getConstant(code, SRC1);
			else {
				Access addr1 = allocator->access(SRC1);
				src1 = getAddress(addr1, 32, true);
			}
			if (SRC2->kind == SK_Constant)
				src2 = getConstant(code, SRC2);
			else {
				Access addr2 = allocator->access(SRC2);
				src2 = getAddress(addr2, 32, false);
			}
			fprintf(fp, "\tcmpl %s, %s\n", src2.c_str(), src1.c_str());
			fprintf(fp, "\t%s %s\n", opCodeNames[inst->opcode], ((BasicBlock)DST)->symbol->name.c_str());
		}
		else {
			std::string src;
			assert(SRC1->kind != SK_Constant);
			src = getAddress(allocator->access(SRC1));
			fprintf(fp, "\tcmpl $0, %s\n", src.c_str());
			fprintf(fp, "\t%s %s\n", opCodeNames[inst->opcode], ((BasicBlock)DST)->symbol->name.c_str());
		}
	}

	void emitJump(IrInst& inst)
	{
		fprintf(fp, "\tjmp %s\n", ((BasicBlock)DST)->symbol->name.c_str());
	}

	void emitReturn(IrInst& inst)
	{
		int code = typeCode(inst->type);
		if (code == F4 || code == F8) {
			assert(0);
			return;
		}
		std::string src, dst;
		if (DST->kind == SK_Constant)
			src = getConstant(code, DST);
		else
			src = getAddress(allocator->access(DST));
		fprintf(fp, "\tmovl %s, %%eax\n", src.c_str());
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
			return "$" + std::to_string(*((unsigned long long *)(&(s->valueUnion.d))));
		return "$" + std::to_string(s->valueUnion.i[0]);
	}

	std::string getAddress(Access access, int bits = 32, bool src = false)
	{
		if (access->kind == access->InReg) {
			if (bits == 64)
				return "%" + std::string(REGS[access->reg]);
			if (src || bits == 32)
				return "%" + std::string(WREGS[access->reg]);
			if (bits == 16)
				return "%" + std::string(HREGS[access->reg]);
			if (bits == 8)
				return "%" + std::string(BREGS[access->reg]);
		}
		else if (access->kind == access->InFrame) {
			if (src) {
				if (bits == 64) {
					fprintf(fp, "\tmovq %s, %%rax\n", (std::to_string(access->offset) + "(%rbp)").c_str());
					return "%rax";
				}
				if(bits == 32)
					fprintf(fp, "\tmovl %s, %%eax\n", (std::to_string(access->offset) + "(%rbp)").c_str());
				if (bits == 16)
					fprintf(fp, "\tmovzwl %s, %%eax\n", (std::to_string(access->offset) + "(%rbp)").c_str());
				fprintf(fp, "\tmovzbl %s, %%eax\n", (std::to_string(access->offset) + "(%rbp)").c_str());
				return "%eax";
			}
			return std::to_string(access->offset) + "(%rbp)";
		}
		else
			return access->global;
	}

	void emitMove(IrInst& inst)
	{
#define InFrame(addr) (((addr)->kind) == ((addr)->InFrame))
#define InReg(addr) (((addr)->kind) == ((addr)->InReg))
#define InGlobal(addr) (((addr)->kind) == ((addr)->InGlobal))
		Access dstAddr;
		int code = typeCode(inst->type);
		std::string src, dst;
		if (code == F4 || code == F8) {
			assert(0);
			return;
		}
		switch (code)
		{
		case I1: case U1: //Src1 -> Dst
			if (SRC1->kind == SK_Constant)
				src = getConstant(code, SRC1);
			else
				src = getAddress(allocator->access(SRC1), 8, true);
			dstAddr = allocator->access(DST);
			dst = getAddress(dstAddr, 8);
			if (InReg(dstAddr))
				fprintf(fp, "\tmovl %s, %s\n", src.c_str(), dst.c_str());
			fprintf(fp, "\tmovb %s, %s\n", src.c_str(), dst.c_str());
			break;
		case I2: case U2:
			if (SRC1->kind == SK_Constant)
				src = getConstant(code, SRC1);
			else
				src = getAddress(allocator->access(SRC1), 16, true);
			dstAddr = allocator->access(DST);
			dst = getAddress(dstAddr, 8);
			if (InReg(dstAddr))
				fprintf(fp, "\tmovl %s, %s\n", src.c_str(), dst.c_str());
			fprintf(fp, "\tmovw %s, %s\n", src.c_str(), dst.c_str());
			break;
		case I4: case U4:
			if (SRC1->kind == SK_Constant)
				src = getConstant(code, SRC1);
			else
				src = getAddress(allocator->access(SRC1));
			dst = getAddress(allocator->access(DST));
			fprintf(fp, "\tmovl %s, %s\n", src.c_str(), dst.c_str());
		case P:
			if (SRC1->kind == SK_Constant)
				src = getConstant(code, SRC1);
			else
				src = getAddress(allocator->access(SRC1), 64);
			dst = getAddress(allocator->access(DST), 64);
			fprintf(fp, "\tmovq %s, %s\n", src.c_str(), dst.c_str());
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
