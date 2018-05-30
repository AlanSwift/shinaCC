//
// Created by Administrator on 2018/5/30/030.
//

#ifndef CP_SYMBOLTABLE_H
#define CP_SYMBOLTABLE_H

#include "constant.h"
#include <string>
#include <list>
#include <iostream>
#define HASH_TABLE_SZIE 149

class SymbolTale
{
private:
    int size;
    std::list<std::pair<std::string, Type>> hashTale[HASH_TABLE_SZIE];

    unsigned int hashValue(std::string &str)
    {
        const char *s = str.c_str();
        unsigned int value = 0;
        for(int i = 0; s[i]; i++)
            value = (value * 65599 + s[i]) % HASH_TABLE_SZIE;
        return value;
    }
public:
    SymbolTale():size(0){}

    bool addSymbol(std::string id, Type type)
    {
        unsigned int index = hashValue(id);
        std::pair<std::string, Type> p = std::make_pair(id, type);
        hashTale[index].insert(hashTale[index].begin(), p);
        size++;
        return true;
    }

    Type popSymbol(std::string id)
    {
        unsigned int index = hashValue(id);
        std::list<std::pair<std::string, Type>> &hashItem = hashTale[index];
        auto it = hashItem.begin();
        while(it != hashItem.end()){
            if(it->first == id){
                Type type = it->second;
                it = hashItem.erase(it);
                size--;
                return type;
            }
            it++;
        }
        return NULL;
    }

    Type lookUp(std::string id)
    {
        unsigned int index = hashValue(id);
        for(auto &p: hashTale[index]){
            if(p.first == id)
                return p.second;
        }
        return NULL;
    }
};

#endif //CP_SYMBOLTABLE_H
