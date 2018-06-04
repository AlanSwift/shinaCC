//
// Created by Administrator on 2018/6/4/004.
//

#include "translator.h"

void Program_::appendInst(IrInst e)
{
    if(currentBlock)
        currentBlock->insts.push_back(e);
}

BasicBlock Program_::createBasicBlock()
{
    BasicBlock bb = new BasicBlock_();
    memset(bb, 0, sizeof(BasicBlock_));
    return bb;
}

void Program_::startBasicBlock(BasicBlock bb)
{
    if(currentBlock)
        bblocks.push_back(currentBlock);
    currentBlock = bb;
}

Program Translator_::translate(TranslationUnitDecl start)
{
    for(auto &decl: start->declarations){
        if(decl->id == NODE_DECL_VAR){
            VarDecl decl1 = (VarDecl)decl;
            //TODO: varDecl
        }
        else if(decl->id == NODE_DECL_FUNCTION){
            FunctionDecl decl1 = (FunctionDecl)decl;
            if(!decl1->stmt){
                //TODO: funcDecl
            }
        }
    }
    return NULL;
}

Symbol Translator_::translateFunctionCall(CallExpr expr)
{

}

Symbol Translator_::translateBinaryExpr(BinaryOpExpr expr)
{
    if(expr->operator_ == OP_BINARY_COMMA)
        return translateCommaExpr(expr);
}

Symbol Translator_::translateUnaryExpr(UnaryOpExpr expr)
{
    if(expr->operator_ == OP_UNARY_DOUBLEADD || expr->operator_ == OP_UNARY_DOUBLEMINUS)
        return translateIncrement(expr);

}

Symbol Translator_::translateIncrement(UnaryOpExpr expr)
{

}

Symbol Translator_::translateConditionalExpr(ConditionalExpr expr)
{

}

Symbol Translator_::translateAssignmentExpr(AssignExpr expr)
{

}

Symbol Translator_::translateCommaExpr(BinaryOpExpr expr)
{

}


Symbol Translator_::translateCastExpr(Expr expr)
{

}

Symbol Translator_::translatePrimaryExpr(Expr expr) //id, str, int, float, parentheses
{

}

Symbol Translator_::translateArrayIndex(ArraySubscriptExpr expr)
{

}

void Translator_::translateExprStmt(ExprStmt stmt)
{
    assert(stmt->expr);
    translateExpression(stmt->expr);
}

void Translator_::translateLabelStmt(LabelStmt stmt)
{
    //TODO: create basic block for label
    if(stmt->label){
        if(stmt->label->respBB)
            stmt->label->respBB = program->createBasicBlock();
        program->startBasicBlock(stmt->label->respBB);
    }
    translateStatement(stmt->stmt);
}

void Translator_::translateCaseStmt(CaseStmt stmt)
{
    //TODO:
    translateStatement(stmt->stmt);
}

void Translator_::translateDefaultStmt(DefaultStmt stmt)
{
    //TODO:
}

void Translator_::translateIfStmt(IfStmt stmt)
{
    BasicBlock nextBB, trueBB, falseBB;
    nextBB = program->createBasicBlock();
    trueBB = program->createBasicBlock();
    if(stmt->else_ == NULL){
        translateBranch(notExpr(stmt->condition), nextBB, trueBB);
        program->startBasicBlock(trueBB);
        translateStatement(stmt->if_);
    }
    else{
        falseBB = program->createBasicBlock();
    }
}

void Translator_::translateWhileStmt(WhileStmt stmt)
{

}

void Translator_::translateDoStmt(DoStmt stmt)
{

}

void Translator_::translateForStmt(ForStmt stmt)
{

}

void Translator_::translateGotoStmt(GoToStmt stmt)
{

}

void Translator_::translateBreakStmt(BreakStmt stmt)
{

}

void Translator_::translateContinueStmt(ContinueStmt stmt)
{

}

void Translator_::translateReturnStmt(ReturnStmt stmt)
{

}

void Translator_::translateCompoundStmt(CompoundStmt stmt)
{

}

void Translator_::translateSwitchStmt(SwitchStmt stmt)
{

}

void Translator_::translateBranch(Expr expr, BasicBlock trueBlock, BasicBlock falseBlock)
{

}

Expr Translator_::notExpr(Expr expr)
{
    if(expr->id == NODE_EXP_BINARY){
        BinaryOpExpr expr1 = (BinaryOpExpr)expr;
        switch (expr1->operator_){
            case OP_BINARY_LOGICAL_AND:
                expr1->operator_ = OP_BINARY_LOGICAL_OR;
                expr1->left = notExpr(expr1->left);
                expr1->right = notExpr(expr1->right);
                return expr;
            case OP_BINARY_LOGICAL_OR:
                expr1->operator_ = OP_BINARY_LOGICAL_AND;
                expr1->left = notExpr(expr1->left);
                expr1->right = notExpr(expr1->right);
                return expr;
            case OP_BINARY_BE: // >=
                expr1->operator_ = OP_BINARY_ST;
                return expr;
            case OP_BINARY_ST: // <
                expr1->operator_ = OP_BINARY_BE;
                return expr;
            case OP_BINARY_GT: // >
                expr1->operator_ = OP_BINARY_SE;
                return expr;
            case OP_BINARY_SE: // <=
                expr1->operator_ = OP_BINARY_GT;
                return expr;
            case OP_BINARY_EQ:
                expr1->operator_ = OP_BINARY_NEQ;
                return expr;
            case OP_BINARY_NEQ:
                expr1->operator_ = OP_BINARY_EQ;
                return expr;
            default: break;
        }
    }
    else if(expr->id == NODE_EXP_UNARY){
        UnaryOpExpr expr1 = (UnaryOpExpr)expr;
        if(expr1->operator_ == OP_UNARY_LOGICAL_NOT)
            return expr1->expr;
    }
    UnaryOpExpr expr2 = new UnaryOpExpr_(expr, OP_UNARY_LOGICAL_NOT, false);
    return expr2;
}


void Translator_::translateStatement(Stmt stmt)
{
    switch (stmt->id){
        case NODE_STM_COMPOUND:
            translateCompoundStmt((CompoundStmt)stmt);
            break;
        case NODE_STM_EXPR:
            translateExprStmt((ExprStmt)stmt);
            break;
        case NODE_STM_DECL:
            //TODO
            break;
        case NODE_STM_SWITCH:
            translateSwitchStmt((SwitchStmt)stmt);
            break;
        case NODE_STM_CASE:
            translateCaseStmt((CaseStmt)stmt);
            break;
        case NODE_STM_DEFAULT:
            translateDefaultStmt((DefaultStmt)stmt);
            break;
        case NODE_STM_RETURN:
            translateReturnStmt((ReturnStmt)stmt);
            break;
        case NODE_STM_IF:
            translateIfStmt((IfStmt)stmt);
            break;
        case NODE_STM_WHILE:
            translateWhileStmt((WhileStmt)stmt);
            break;
        case NODE_STM_DO:
            translateDoStmt((DoStmt)stmt);
            break;
        case NODE_STM_FOR:
            translateForStmt((ForStmt)stmt);
            break;
        case NODE_STM_LABEL:
            translateLabelStmt((LabelStmt)stmt);
            break;
        case NODE_STM_CONTINUE:
            translateContinueStmt((ContinueStmt)stmt);
            break;
        case NODE_STM_BREAK:
            translateBreakStmt((BreakStmt)stmt);
            break;
        case NODE_STM_NULL:
            break;
        case NODE_STM_GOTO:
            translateGotoStmt((GoToStmt)stmt);
            break;
        default:
            break;
    }
}

Symbol Translator_::translateExpression(Expr expr)
{
    switch (expr->id){
        case NODE_EXP_PAREN:
            return translateExpression(((ParenExpr)expr)->expr);
        case NODE_EXP_INTLITERAL:
        case NODE_EXP_FLOATLITERAL: case NODE_EXP_STRLITERAL:
        case NODE_EXP_DECLREF: case NODE_EXP_CHARLITERAL:
            return translatePrimaryExpr(expr);
        case NODE_EXP_BINARY:
            return translateBinaryExpr((BinaryOpExpr)expr);
        case NODE_EXP_UNARY:
            return translateUnaryExpr((UnaryOpExpr)expr);
        case NODE_EXP_CONDITIONAL:
            return translateConditionalExpr((ConditionalExpr)expr);
        case NODE_EXP_ASSIGN:
            return translateAssignmentExpr((AssignExpr)expr);
        case NODE_EXP_CALL:
            return translateFunctionCall((CallExpr)expr);
        case NODE_EXP_ARRAYSUBSCRIPT:
            return translateArrayIndex((ArraySubscriptExpr)expr);
        case NODE_EXP_IMPLICITCAST: case NODE_EXP_CSTYLECAST:
            return translateCastExpr(expr);
        default:
            return NULL;
    }
}
