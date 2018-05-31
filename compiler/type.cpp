//
// Created by Administrator on 2018/5/31/031.
//


#include "type.h"

Type BuiltinType_::voidType = new BuiltinType_(CONST_TYPE_BUILTIN_VOID, NULL);
Type BuiltinType_::shortType = new BuiltinType_(CONST_TYPE_BUILTIN_SHORT, NULL);
Type BuiltinType_::intType = new BuiltinType_(CONST_TYPE_BUILTIN_INT, NULL);
Type BuiltinType_::longType = new BuiltinType_(CONST_TYPE_BUILTIN_LONG, NULL);
Type BuiltinType_::charType = new BuiltinType_(CONST_TYPE_BUILTIN_CHAR, NULL);
Type BuiltinType_::floatType = new BuiltinType_(CONST_TYPE_BUILTIN_FLOAT, NULL);
Type BuiltinType_::doubleType = new BuiltinType_(CONST_TYPE_BUILTIN_DOUBLE, NULL);
Type BuiltinType_::longDoubleType = new BuiltinType_(CONST_TYPE_BUILTIN_LONG_DOUBLE, NULL);
Type BuiltinType_::unsignedShortType = new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED_SHORT, NULL);
Type BuiltinType_::unsignedIntType = new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED_INT, NULL);
Type BuiltinType_::unsignedLongType = new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED_LONG, NULL);
Type BuiltinType_::unsignedCharType = new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED_CHAR, NULL);