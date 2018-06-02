//
// Created by Administrator on 2018/5/30/030.
//

#ifndef CP_SYMBOLTABLE_H
#define CP_SYMBOLTABLE_H

#include "constant.h"
#include <string>
#include <list>
#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
#define HASH_TABLE_SZIE 149

template <class T>
class SymbolTable
{
private:
    int size;
    std::list<std::pair<std::string, T>> hashTale[HASH_TABLE_SZIE];
    std::vector<std::vector<std::string>> buffer;
    int bufferSize=0;

    unsigned int hashValue(std::string &str)
    {
        const char *s = str.c_str();
        unsigned int value = 0;
        for(int i = 0; s[i]; i++)
            value = (value * 65599 + s[i]) % HASH_TABLE_SZIE;
        return value;
    }
public:
    SymbolTable():size(0),bufferSize(0){

    }

    bool addSymbol(std::string id, Type type)
    {
        
        unsigned int index = hashValue(id);
        std::pair<std::string, T> p = std::make_pair(id, type);
        hashTale[index].insert(hashTale[index].begin(), p);
        size++;
        if(bufferSize)
        {
            buffer[bufferSize-1].push_back(id);
        }
        
        return true;
    }

    T popSymbol(std::string id) {
        unsigned int index = hashValue(id);
        std::list <std::pair<std::string, T>> &hashItem = hashTale[index];
        auto it = hashItem.begin();
        while (it != hashItem.end()) {
            if (it->first == id) {
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
    void pushEnv()
    {
        buffer.push_back(std::vector<std::string>());
        bufferSize=buffer.size();
    }
    void popEnv()
    {
        assert(bufferSize);
        for(auto &e:buffer[bufferSize-1])
        {
            popSymbol(e);
        }
        buffer.pop_back();
        bufferSize=buffer.size();
    }


};

#endif //CP_SYMBOLTABLE_H
