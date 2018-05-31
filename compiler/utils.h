#ifndef UTILS_H
#define UTILS_H
#include "type.h"
#include "constant.h"
#include "expression.h"
#include <cassert>


bool isMatchType(Type a,Type b);

bool isMatchFunctionType(FunctionType a,FunctionType b);
bool isMatchBuiltinType(BuiltinType a,BuiltinType b);
bool isMatchPointerType(PointerType a,PointerType b);
bool isMatchArrayType(ArrayType a,ArrayType b);


bool isRelationalOp(int op);
bool isBitWiseOp(int op);

Expr doBinaryOp(Expr expr1, int op, Expr expr2);
Expr doUnaryOp(Expr expr1, int op);


#endif