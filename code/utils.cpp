//
// Created by Alan on 21/05/2018.
//
#include "utils.h"
#include <iostream>
using namespace std;
void* checked_malloc(size_t size)
{
    void * p=malloc(size);
    if(!p)
    {
        cerr<<"Fatal error: out of memory"<<endl;
        exit(1);
    }
    return p;
}

