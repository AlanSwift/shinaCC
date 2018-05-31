#ifndef UTILS_H
#define UTILS_H
#include "type.h"

bool isMatchFunctionType(FunctionType a,FunctionType b);
bool isMatchBuiltinType(BuiltinType a,BuiltinType b);
bool isMatchPointerType(PointerType a,PointerType b);
bool isMatchArrayType(ArrayType a,ArrayType b);


#endif