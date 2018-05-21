//
// Created by Alan on 21/05/2018.
//

#ifndef CODE_SYMBOL_H
#define CODE_SYMBOL_H

#include <string>
#include "utils.h"

using namespace std;

struct S_symbol_;
typedef S_symbol_* S_symbol;
class S_symbolList_;
typedef S_symbolList_* S_symbolList;


struct S_symbol_
{
    S_symbol_ (string _name,S_symbol _next);
    string name;
    S_symbol next;
};

class S_symbolList_{
public:
    S_symbolList_ ();
    ~S_symbolList_();
    void addSym(string name);

private:
    S_symbol head;
};

#endif //CODE_SYMBOL_H
