//
// Created by Administrator on 2018/5/30/030.
//

#ifndef CP_SYMBOLTABLE_H
#define CP_SYMBOLTABLE_H

#include "constant.h"
#include <string>

class SymbolTale
{
public:
    bool addSymbol(std::string id, Type type);
    Type lookUp(std::string id);
};

#endif //CP_SYMBOLTABLE_H
