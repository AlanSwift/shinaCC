//
// Created by Alan on 21/05/2018.
//
#include "symbol.h"
#include <string>
using namespace std;

S_symbol_::S_symbol_ (string _name,S_symbol _next):name(_name),next(_next){}


S_symbolList_::S_symbolList_ ():head(nullptr){}

void S_symbolList_::addSym(string name) {
    if(head== nullptr)
    {
        head=(S_symbol)checked_malloc(sizeof(S_symbol_));
        head->name=name;
        head->next= nullptr;
    }
    else{
        S_symbol p=new S_symbol_(name,head);
        head=p;
    }
}

S_symbolList_::~S_symbolList_() {
    S_symbol p;
    while(head)
    {
        p=head->next;
        free(head);
        head=p;
    }
}


