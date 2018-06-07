//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_ALLOCATOR_H
#define CP_ALLOCATOR_H

#include <string>
#include <map>
#include <cstring>
#include <algorithm>

#include "type.h"
#include "constant.h"
#include "translator.h"


typedef int Register;
typedef unsigned long long ULL;
typedef struct Access_ *Access;

extern char *REGS[];
extern char *WREGS[];
extern char *HREGS[];
extern char *BREGS[];
extern char *FP;
extern char *SP;

struct Access_
{
	enum { InReg, InFrame, InGlobal } kind;
	int offset; /*InFrame*/
	Register reg; /*In Reg*/
	std::string global;

	Access_() 
	{
	}

	void putInReg(Register reg)
	{
		kind = InReg;
		this->reg = reg;
	}

	void putInGlobal(std::string global)
	{
		kind = InGlobal;
		this->global = global;
	}

	void putInFrame(int offset)
	{
		kind = InFrame;
		this->offset = offset;
	}
};



class ConflictGraph{
public:
    ConflictGraph(){

    }
    
    vector<pair<Symbol,vector<Symbol>>> analysis(BasicBlock bb);

private:
    enum{MAX=100};

    bool confMap[MAX+10][MAX+10];
    std::map<unsigned long long,int>tempMap;
    unsigned long long id2Pointer[MAX];
    std::map<unsigned long long,std::string>debug;
    pair<int,int>posMark[MAX];

    bool conflict(const pair<int,int>&a,const pair<int,int>&b)
    {
        return !(a.first>b.second||a.second<b.first);
    }

    void clear()
    {
        memset(confMap,0,sizeof(confMap));
        tempMap.clear();
        debug.clear();

    }

    void addEdge(int from,int to)
    {
        assert(from<100);
        assert(to<100);
        confMap[from][to]=true;
        confMap[to][from]=true;
    }

};



class Allocator
{
public:
    Allocator()
    {
        graph=new ConflictGraph();

    }
    
	void allocate(Program program)
	{
		
	}
    void precess(BasicBlock bb);
    

	Access access(Symbol symbol);

    void clearCache()
    {
        cache.clear();
        offset=0;
    }
    


private:
    bool regUsed[100];
    std::map<Symbol,int>regMap;
    vector<Symbol> id2Symbol[100];
    std::map<Symbol,Access>cache;
    int offset=0;

    const int regStart=6;
    const int regEnd=13;
    const int generalCnt=8;

    ConflictGraph *graph;

    std::map<std::string,int>stringMap;
    int stringCnt=0;


    void clear()
    {
        memset(regUsed,0,sizeof(regUsed));
        for(int i=regStart;i<=regEnd;i++)
        {
            id2Symbol[i].clear();
        }
        regMap.clear();

    }
    bool isGeneralUsedUp()
    {
        for(int i=regStart;i<=regEnd;i++)
        {
            if(!regUsed[i])  return false;
        }
        return true;
    }
    int getFirstReg()
    {
        for(int i=regStart;i<=regEnd;i++)
        {
            if(!regUsed[i])  return i;
        }
        assert(0);
    }

};

#endif //CP_FRAME_H