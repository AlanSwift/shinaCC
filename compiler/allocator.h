//
// Created by Administrator on 2018/6/1/001.
//

#ifndef CP_ALLOCATOR_H
#define CP_ALLOCATOR_H

#include <string>
#include <map>
#include <cstring>

#include "type.h"
#include "constant.h"
#include "translator.h"


typedef int Register;
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
    
    void analysis(BasicBlock bb)
    {
        
        clear();

        map<unsigned long long,int>tempMap;
        map<unsigned long long,std::string>debug;

        int cnt=0;

        for(auto &inst:bb->insts)
        {

            switch (inst->opcode) {
                case BOR:
                case BXOR:
                case BAND:
                case LSH:
                case RSH:
                case ADD:
                case SUB:
                case MUL:
                case DIV:
                case MOD:
                    //fprintf(stdout, "%s = %s %s %s", DST->name.c_str(), SRC1->name.c_str(), opCodeNames[op], SRC2->name.c_str());
                    if(DST->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=SRC1->name.c_str();
                        }
                    }
                    if(SRC2->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC2))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC2)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC2)]=SRC2->name.c_str();
                        }
                    }



                    break;
                case INC:
                case DEC:
                    //fprintf(stdout, "%s%s", opCodeNames[op], DST->name.c_str());
                    if(DST->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    break;
                case BCOM:
                case NEG:
                case ADDR:
                case DEREF:
                    //fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
                    if(DST->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    break;
                case MOV:
                    //fprintf(stdout, "%s = %s", DST->name.c_str(), SRC1->name.c_str());
                    if(DST->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=SRC1->name.c_str();
                        }
                    }
  
                    
                    break;
                case IMOV:
                    //fprintf(stdout, "*%s = %s", DST->name.c_str(), SRC1->name.c_str());
                    if(DST->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=SRC1->name.c_str();
                        }
                    }


                    break;
                case JE:
                case JNE:
                case JG:
                case JL:
                case JGE:
                case JLE:
                    //fprintf(stdout, "if (%s %s %s) goto %s", SRC1->name.c_str(), opCodeNames[op],
                    //    SRC2->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());
                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=DST->name.c_str();
                        }
                    }
                    if(SRC2->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC2))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC2)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC2)]=SRC2->name.c_str();
                        }
                    }
                    break;
                case JZ:
                    //fprintf(stdout, "if (! %s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());

                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=SRC1->name.c_str();
                        }
                    }

                    break;
                case JNZ:
                    //fprintf(stdout, "if (%s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());

                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=SRC1->name.c_str();
                        }
                    }

                    break;
                case JMP:

                    assert(((BasicBlock)DST));
                    assert(((BasicBlock)DST)->symbol);
                    //fprintf(stdout, "goto %s", ((BasicBlock)DST)->symbol->name.c_str());
                    
                    break;
                case RET:
                    //if(DST == NULL)
                    //    fprintf(stdout, "return", DST->name.c_str());
                    //fprintf(stdout, "return %s", DST->name.c_str());
                    break;
                case CALL:{
                    // vector<pair<Symbol, Type> > * args = (vector<pair<Symbol, Type> > *)SRC2;
                    // int i;

                    // if (DST != NULL)
                    //     fprintf(stdout, "%s = ", DST->name.c_str());
                    // fprintf(stdout, "%s(", SRC1->name.c_str());
                    // for (auto &arg: *args) {
                    //     fprintf(stdout, "%s, ", arg.first->name.c_str());
                    // }
                    // fprintf(stdout, ")");
                }
                    break;
                default:
                    //fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
                    if(DST->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                        }
                    }
                    if(SRC1->kind==SK_Temp)
                    {
                        if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                        {
                            tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                            debug[reinterpret_cast<unsigned long long>(SRC1)]=DST->name.c_str();
                        }
                    }
                    break;
                }

        

	
        }
        printf("Block %s:\n",bb->symbol->name.c_str());
        for(auto &i:debug)
        {
            printf("%s ",i.second.c_str());
        }
        puts("");
    }

private:
    enum{MAX=100};


    struct Edge
    {  
        int to;  
        int next;  
    };  
    Edge e[MAX];
    int pre[MAX];
    int cnt;

    void clear()
    {

        memset(pre,-1,sizeof(pre));
        cnt=0;
    }

    void addEdge(int from,int to)
    {
        e[cnt].to=to;
        e[cnt].next=pre[from];
        pre[from]=cnt;
        cnt++;
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
    void precess(BasicBlock bb)
    {
        graph->analysis(bb);
    }

	Access access(Symbol symbol);
    


private:
    bool regUsed[100];
    const int regStart=6;
    const int regEnd=13;
    const int generalCnt=8;

    ConflictGraph *graph;

    std::map<std::string,int>stringMap;
    int stringCnt=0;


    void clear()
    {
        memset(regUsed,0,sizeof(regUsed));
    }
    bool isGeneralUsedUp()
    {
        for(int i=regStart;i<=regEnd;i++)
        {
            if(regUsed[i])  return true;
        }
        return false;
    }
    int getFirstReg()
    {
        for(int i=regStart;i<=regEnd;i++)
        {
            if(regUsed[i])  return i;
        }
        assert(0);
    }

};

#endif //CP_FRAME_H