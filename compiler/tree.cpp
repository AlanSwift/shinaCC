//
// Created by Administrator on 2018/6/3/003.
//
#include "tree.h"

void T_stm_::buildSEQ(T_stm left, T_stm right)
{
    kind = T_SEQ;
    u.SEQ.left = left;
    u.SEQ.right = right;
}

void T_stm_::buildLABEL(Temp_label label)
{
    kind = T_LABEL;
    u.LABEL = label;
}

void T_stm_::buildJUMP(T_exp exp, std::vector<Temp_label> *jumps)
{
    kind = T_JUMP;
    u.JUMP.exp = exp;
    u.JUMP.jumps = jumps;
}

void T_stm_::buildCJUMP(T_relOp op, T_exp left, T_exp right, Temp_label true_, Temp_label false_)
{
    kind = T_CJUMP;
    u.CJUMP.op = op;
    u.CJUMP.left = left;
    u.CJUMP.right = right;
    u.CJUMP.true_ = true_;
    u.CJUMP.false_ = false_;
}

void T_stm_::buildMOVE(T_exp src, T_exp dest)
{
    kind = T_MOVE;
}

void T_stm_::buildEXP(T_exp exp)
{
    kind = T_EXP;
}


void T_exp_::buildBINOP(T_binOp op, T_exp left, T_exp right)
{
    kind = T_BINOP;
    u.BINOP.op = op;
    u.BINOP.left = left;
    u.BINOP.right = right;
}

void T_exp_::buildUNAOP(T_unaOp op, T_exp operand)
{
    kind = T_UNAOP;
    u.UNAOP.op = op;
    u.UNAOP.operand = operand;
}

void T_exp_::buildMEM(T_exp exp)
{
    kind = T_MEM;
    u.MEM = exp;
}

void T_exp_::buildTEMP(Temp_temp temp)
{
    kind = T_TEMP;
    u.TEMP = temp;
}

void T_exp_::buildESEQ(T_stm stm, T_exp exp)
{
    kind = T_ESEQ;
    u.ESEQ.stm = stm;
    u.ESEQ.exp = exp;
}

void T_exp_::buildNAME(Temp_label label)
{
    kind = T_NAME;
    u.NAME = label;
}

void T_exp_::buildIntCONST(long ival)
{
    kind = T_CONST;
    u.CONST.kind = u.CONST.INT_CONST;
    u.CONST.val.ival = ival;
}

void T_exp_::buildFloatConst(double fval)
{
    kind = T_CONST;
    u.CONST.kind = u.CONST.FlOAT_CONST;
    u.CONST.val.fval = fval;
}

void T_exp_::buildStrConst(Temp_label str)
{
    kind = T_CONST;
    u.CONST.kind = u.CONST.STR_CONST;
    u.CONST.val.str = str;
}

void T_exp_::buildCALL(T_exp fun, std::vector<T_exp> *args)
{
    kind = T_CALL;
    u.CALL.fun = fun;
    u.CALL.args = args;
}
