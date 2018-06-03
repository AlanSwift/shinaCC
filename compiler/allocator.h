//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_FRAME_H
#define CP_FRAME_H

#include <string>
#include "type.h"

typedef unsigned int Register_;
typedef Register_ *Register;

struct Access
{
    enum { InReg, InFrame } kind;
    union {
        int offset; /*InFrame*/
        Register reg; /*In Reg*/
    }u;

    Access(Register reg){
        kind = InReg;
        u.reg = reg;
    }

    Access(int offset){
        kind = InFrame;
        u.offset = offset;
    }
};


struct Temp_label_
{
    std::string id;
};

struct Temp_temp_
{

};

typedef struct Temp_label_ *Temp_label;
typedef struct Temp_temp_ *Temp_temp;

class Allocator
{
public:
    bool allocateLocal(std::string id, Type type, bool escape = false); /*local variables, in stack, registers*/
    bool allocateGlobal(std::string id, Type type); /*global variables, function, in data, text segment*/
    bool allocateLabel(std::string label);
    bool allocateTemp(std::string id);
};

#endif //CP_FRAME_H
