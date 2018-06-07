#pragma once
#include <cstdio>
#include <cassert>
#include "constant.h"
#include "translator.h"
#include <string>

typedef class Emitter_ *Emitter;

class Emitter_
{
private:
	FILE *fp;
	Program program;
public:
	Emitter_()
	{
		fp = stdout;
	}

	Emitter_(FILE *fp):fp(fp)
	{

	}

	~Emitter_()
	{

	}

	void emitCode(Program program)
	{
		assert(fp);
		this->program = program;
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

		

		emitEpilogue(frameSize);
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
};

