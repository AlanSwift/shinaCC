//
// Created by Administrator on 2018/5/25/025.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H

typedef int A_identifier;
typedef int BasicOperator;
typedef int BinaryOperator;
typedef int UnaryOperator;
typedef int AssignOperator;



struct Node_
{
    A_identifier id;
};

typedef struct Node_ *Node;

#endif //COMPILER_CONSTANT_H
