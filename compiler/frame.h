//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_FRAME_H
#define CP_FRAME_H

#include <string>
#include "type.h"


class Frame
{
public:
    bool allocate(std::string id, Type type, bool escape = false);
};

#endif //CP_FRAME_H
