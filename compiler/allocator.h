//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_FRAME_H
#define CP_FRAME_H

#include <string>
#include "type.h"


class Allocator
{
public:
    bool allocateLocal(std::string id, Type type, bool escape = false); /*local variables*/
    bool allocateGlobal(std::string id, Type type); /*global variables, function*/
};

#endif //CP_FRAME_H
