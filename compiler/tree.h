//
// Created by Administrator on 2018/6/3/003.
//

#ifndef CP_TREE_H
#define CP_TREE_H

#include <string>
#include <vector>
#include "allocator.h"

typedef class T_stm_ *T_stm;
typedef class T_exp_ *T_exp;
typedef int T_relOp;
typedef int T_binOp;
typedef int T_unaOp;

class T_stm_ {
    enum {
        T_SEQ, T_LABEL, T_JUMP, T_CJUMP, T_MOVE, T_EXP,
    } kind;
    union {
        struct { T_stm left, right; } SEQ;
        Temp_label LABEL;
        struct { T_exp exp; std::vector<Label> *jumps; };
        struct {T_relOp op; T_exp left, right;
            Temp_label true_, false_;} CJUMP;
        struct { T_exp dst, src; } MOVE;
        T_exp EXP;
    };
};

class T_exp_ {
    enum {T_BINOP, T_UNAOP, T_MEM, T_TEMP, T_ESEQ, T_NAME,
        T_CONST, T_CALL} kind;
    union {
        struct {T_binOp op; T_exp left, right;} BINOP;
        struct {T_unaOp op; T_exp op;} UNAOP;
        T_exp MEM;
        Temp_temp TEMP;
        struct {T_stm stm; T_exp exp;} ESEQ;
        Temp_label NAME;
        struct {
            enum {
                INT_CONST, FlOAT_CONST, STR_CONST
            } kind;
            long ival; double fval; Temp_label str;
        } CONST;
        struct {T_exp fun; std::vector<T_exp> *args;} CALL;
    };
};

#endif //CP_TREE_H
