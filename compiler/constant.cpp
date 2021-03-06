#include "constant.h"
#include <map>
using namespace std;
#include "expression.h"

int StrLiteral_::cnt = 1;

map<int,string>map_id2name={
{1,"PointerType_"},
{2,"RecordType_"},
{3,"ArrayType_"},
{4,"FunctionType_"},
{5,"TypedefType_"},
{6,"BuiltinType_"},
{7,"void"},
{8,"char"},
{9,"unsigned char"},
{10,"short"},
{11,"unsigned short"},
{12,"int"},
{13,"unsigned int"},
{14,"long"},
{15,"unsigned long"},
{16,"enum"},
{17,"signed"},
{18,"unsigned"},
{19,"float"},
{20,"double"},
{21,"long double"},
{22,"invalid"},
{100,"ParenExpr_"},
{101,"BinaryOpExpr_"},
{102,"UnaryOpExpr_"},
{103,"ConditionalExpr_"},
{104,"AssignExpr_"},
{105,"CallExpr_"},
{106,"MemberExpr_"},
{107,"ArraySubscriptExpr_"},
{108,"DeclRefExpr_"},
{109,"ImplicitCastExpr_"},
{110,"CStyleCastExpr_"},
{111,"IntLiteral_"},
{112,"CharLiteral_"},
{113,"FloatLiteral_"},
{114,"StrLiteral_"},
{115,"InitListExpr_"},
{200,"VarDecl_"},
{201,"FunctionDecl_"},
{202,"ParmVarDecl_"},
{203,"RecordDecl_"},
{204,"FieldDecl_"},
{205,"TypedefDecl_"},
{300,"BreakStmt_"},
{301,"ContinueStmt_"},
{302,"CompoundStmt_"},
{303,"DoStmt_"},
{304,"WhileStmt_"},
{305,"ForStmt_"},
{306,"GoToStmt_"},
{307,"IfStmt_"},
{308,"LabelStmt_"},
{309,"ReturnStmt_"},
{310,"SwitchStmt_"},
{311,"CaseStmt_"},
{312,"DefaultStmt_"},
{313,"ExprStmt_"},
{314,"DeclStmt_"},
{315,"NullStmt_"},
{396,"~"},
{397,"!"},
{398,"+"},
{399,"-"},
{400,"cast"},
{401,"*"},
{402,"&"},
{403,"++"},
{404,"--"},
{405,"sizeof"},
{406,"*"},
{407,"/"},
{408,"%"},
{409,"+"},
{410,"-"},
{411,"<<"},
{412,">>"},
{413,">"},
{414,"<"},
{415,">="},
{416,"<="},
{417,"=="},
{418,"!="},
{419,"&"},
{420,"|"},
{421,"^"},
{422,"&&"},
{423,"||"},
{424,","},
{430,"="},
{431,"+="},
{432,"-="},
{433,"*="},
{434,"/="},
{435,"%="},
{436,"&="},
{437,"^="},
{438,"|="},
{439,"<<="},
{440,">>="},
};

string id2name(int id)
{
    string ret;
    try{
        ret=map_id2name.at(id);
    }catch(...)
    {
        ret="None";
    }
    return ret;
}

void valueDef_::show()
{
    printf("****** valueDef class ******\n");
    printf("op:%d\n",op);
    printf("dst:\n");
    if (dst)
    {
        printf("%s\n",dst->name.c_str());
    }
    printf("src1:\n");
    if(src1)
    {
        printf("%s\n",src1->name.c_str());

    }
    printf("src2:\n");
    if(src2)
    {
        printf("%s\n",src2->name.c_str());
    }



}