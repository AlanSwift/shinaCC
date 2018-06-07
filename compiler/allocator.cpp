#include "allocator.h"
char *REGS[] = {  "rax", "rcx", "rdx", "rbx", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15" }; //64bit
char *WREGS[] = { "eax", "ecx", "edx", "ebx", "esi", "edi", "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d" }; //32bit
char *HREGS[] = { "ax", "cx", "dx", "bx", "si", "di", "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w" }; //16bit
char *BREGS[] = { "al", "cl", "dl", "bl", "sil", "sil", "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b" }; //8bit
char *FP = "rbp";
char *SP = "rsp";


void Allocator::precess(BasicBlock bb)
{
    printf("==start=======\n");
    clear();
    vector<pair<Symbol,vector<Symbol>>>ans=graph->analysis(bb);
    for(auto &i:ans)
    {
        if(isGeneralUsedUp())
        {
            bool spill=true;
            for(int j=regStart;j<=regEnd;j++)
            {
                bool ok=true;
                for(int k=0;k<i.second.size();k++)
                {
                    for(int l=0;l<id2Symbol[j].size();l++)
                    {
                        if(i.second[k]==id2Symbol[j][l])
                        {
                            ok=false;break;
                        }
                    }
                    if(!ok) break;
                    
                }
                if(ok)
                {
                    regMap[i.first]=j;
                    id2Symbol[j].push_back(i.first);
                    break;

                }
                else{
                    regMap[i.first]=-1;//spill
                    
                }
            }
        }
        else{
            regMap[i.first]=getFirstReg();
            regUsed[regMap[i.first]]=true;
            id2Symbol[regMap[i.first]].push_back(i.first);
        }
    }
    printf("################### basic block: %s\n",bb->symbol->name.c_str());
    for(auto &i:regMap)
    {
        printf("%s  %d\n",i.first->name.c_str(),i.second);
    }
    printf("---------\n");


}

Access Allocator::access(Symbol symbol)
{

    assert(symbol!=NULL);
    if(cache.find(symbol)!=cache.end())
    {
        return cache[symbol];
    }
    if(symbol->kind==SK_Function)
    {
        FunctionSymbol funsym=dynamic_cast<FunctionSymbol>(symbol);
        std::string ret="."+funsym->name+"(%rip)";
        Access retAccess=new Access_();
        retAccess->kind=Access_::InGlobal;
        retAccess->global=ret;
        cache[symbol]=retAccess;
        return retAccess;
    }
    else if(symbol->kind==SK_Variable)
    {
        VariableSymbol sym=dynamic_cast<VariableSymbol>(symbol);
        int _offset=-sizeOf(sym->type)-this->offset;
        
        Access ret=new Access_();
        ret->kind=Access_::InFrame;
        ret->offset=_offset;
        cache[symbol]=ret;
        return ret;
    }
    else if(symbol->kind==SK_String)
    {
        std::string str=std::string(reinterpret_cast<char*>(symbol->valueUnion.p));
        int cnt;
        if(stringMap.count(str)==0)
        {
            stringMap[str]=stringCnt++;
            //TODO
        }
        else{
            //TODO
        }
        cnt=stringMap[str];
        std::string retStr = std::string(".LC")+std::to_string(cnt)+"(%rip)";
        Access ret=new Access_();
        ret->global=retStr;
        ret->kind=Access_::InGlobal;
        cache[symbol]=ret;
        return ret;
    }
    else if(symbol->kind==SK_Temp)
    {
        if(regMap.find(symbol)==regMap.end())
        {
            cout<<symbol->name<<endl;

            cerr<<"reg error...."<<endl;
            for(auto &i:regMap)
            {
                printf("%s  %d\n",i.first->name.c_str(),i.second);
            }
            assert(0);
        }
        int retReg=regMap[symbol];
        if(retReg<0)
        {
            //spill
            int offset=sizeOf(symbol->type);
            Access ret=new Access_();
            ret->kind= Access_::InFrame;
            ret->offset=offset;
            cache[symbol]=ret;
            return ret;
        }
        else{
            int regPosition=retReg;
            Access ret=new Access_();
            ret->kind=Access_::InReg;
            ret->reg=regPosition;
            cache[symbol]=ret;
            return ret;
        }

        
    }

}
vector<pair<Symbol,vector<Symbol>>> ConflictGraph::analysis(BasicBlock bb)
{
    
    clear();
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
                        tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
                        tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(SRC1)]=SRC1->name.c_str();
                    }
                }
                if(SRC2->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC2))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC2);
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
                        tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
                        tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
                        tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
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
                if(SRC1->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
                        tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(SRC1)]=DST->name.c_str();
                    }
                }
                if(SRC2->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC2))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC2);
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
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
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
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

                if(DST && DST->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
                        tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                    }
                }
                break;
            case CALL:{

            }
                break;
            default:
                //fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
                if(DST->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(DST))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(DST);
                        tempMap[reinterpret_cast<unsigned long long>(DST)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(DST)]=DST->name.c_str();
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    if(tempMap.count(reinterpret_cast<unsigned long long>(SRC1))==0)
                    {
                        id2Pointer[cnt]=reinterpret_cast<unsigned long long>(SRC1);
                        tempMap[reinterpret_cast<unsigned long long>(SRC1)]=cnt++;
                        debug[reinterpret_cast<unsigned long long>(SRC1)]=DST->name.c_str();
                    }
                }
                break;
        }
    }

    vector<unsigned long long>ans;
    unsigned long long from;
    unsigned long long to;
    int lines=0;
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
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    ULL addr=(ULL)SRC1;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].second=lines;
                    }
                }
                if(SRC2->kind==SK_Temp)
                {
                    ULL addr=(ULL)SRC2;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].second=lines;
                    }
                }

                

                break;
            case INC:
            case DEC:
                //fprintf(stdout, "%s%s", opCodeNames[op], DST->name.c_str());
                if(DST->kind==SK_Temp)
                {
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
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
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    ULL addr=(ULL)SRC1;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].second=lines;
                    }
                }


                break;
            case MOV:
                //fprintf(stdout, "****%s = %s\n", DST->name.c_str(), SRC1->name.c_str());
                if(DST->kind==SK_Temp)
                {
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    ULL addr=(ULL)SRC1;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].second=lines;
                    }
                }



                
                break;
            case IMOV:
                //fprintf(stdout, "*%s = %s", DST->name.c_str(), SRC1->name.c_str());
                if(DST->kind==SK_Temp)
                {
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    ULL addr=(ULL)SRC1;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].second=lines;
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


                break;
            case JZ:
                //fprintf(stdout, "if (! %s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());


                break;
            case JNZ:
                //fprintf(stdout, "if (%s) goto %s", SRC1->name.c_str(), ((BasicBlock)DST)->symbol->name.c_str());


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
                if(DST->kind==SK_Temp)
                {
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
                    }
                }
                break;
            case CALL:{

            }
                break;
            default:
                //fprintf(stdout, "%s = %s%s", DST->name.c_str(), opCodeNames[op], SRC1->name.c_str());
                if(DST->kind==SK_Temp)
                {
                    ULL addr=(ULL)DST;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].first=lines;
                    }
                }
                if(SRC1->kind==SK_Temp)
                {
                    ULL addr=(ULL)SRC1;
                    if(tempMap.count(addr)!=0)
                    {
                        int which=tempMap[addr];
                        posMark[which].second=lines;
                    }
                }


                break;
        }
        lines++;

    }
    // for(int i=0;i<cnt;i++)
    // {
    //     printf("^^ %d: %d %d\n",i,posMark[i].first,posMark[i].second);
        
    // }
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(i==j)    break;
            if(conflict(posMark[i],posMark[j]))
            {
                addEdge(i,j);
            }

        }
    }

    vector<pair<Symbol,vector<Symbol>>> ret;
    for(int i=0;i<cnt;i++)
    {
        pair<Symbol,vector<Symbol>> t;
        t.first=(Symbol)id2Pointer[i];

        for(int j=0;j<cnt;j++)
        {
            if(confMap[i][j])
            {
                t.second.push_back(
                    (Symbol)(id2Pointer[j])
                );
            }
        }
        ret.push_back(t);
    }
    return ret;
}