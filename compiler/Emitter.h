#pragma once
#include <cstdio>
#include <cassert>
#include "constant.h"
#include "translator.h"
#include "allocator.h"
class Emitter
{
private:
	FILE *fp;
public:
	Emitter()
	{
		fp = stdout;
	}

	Emitter(FILE *fp):fp(fp)
	{

	}

	~Emitter();

	void emitCode(Program program)
	{
		assert(fp);
		for (auto &fsym : program->functionList) {

		}
	}
};

