#include "constant.h"
#include <map>
using namespace std;

map<int,string>map_id2name={
{1,"PointerType_"},
{2,"RecordType_"},
{3,"ArrayType_"},
{4,"FunctionType_"},
{5,"TypedefType_"},
{6,"BuiltinType_"},
{7,"BuiltinType_VOID"},
{8,"BuiltinType_CHAR"},
{9,"BuiltinType_UNSIGNED_CHAR"},
{10,"BuiltinType_SHORT"},
{11,"BuiltinType_UNSIGNED_SHORT"},
{12,"BuiltinType_INT"},
{13,"BuiltinType_UNSIGNED_INT"},
{14,"BuiltinType_LONG"},
{15,"BuiltinType_UNSIGNED_LONG"},
{16,"BuiltinType_ENUM"},
{17,"BuiltinType_SIGNED"},
{18,"BuiltinType_UNSIGNED"},
{19,"BuiltinType_FLOAT"},
{20,"BuiltinType_DOUBLE"},
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
{315,"NullStmt_"}
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
