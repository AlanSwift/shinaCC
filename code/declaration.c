#include "absyn.h"


struct A_identifier_list_
{
    S_symbol identifier;
    A_identifier_list next;
};

struct A_parameter_declaration_
{
    enum{
        A_hasDeclarator,A_hasAbstract_declarator,A_Nop
    }kind;
    A_declare declaration_specifiers;
    union
    {
        A_declare declarator;
        A_declare abstract_declarator;
    }u;
};
struct A_parameter_list_
{
    enum{
        A_hasELLIPSIS,A_noELLIPSIS
    };
    A_parameter_declaration content;
    A_parameter_list next;
    S_symbol ELLIPSIS;
};


struct A_declare_
{
	enum{
		A_funcDec,A_declaration,A_initDec,A_dector,A_ptr,A_direct_declarator,
        A_declaration_specifiers,A_abstract_declarator,A_direct_abstract_declarator
	}kind;

	union
	{
		struct 
		{
			A_type typeList;
			A_declare declarator;
			A_declareList decList;
			A_statement body;
		}func;	
		struct
		{
			A_type typeList;
            A_declareList declist;
		}declaration;
        struct
        {
            A_declare declarator;
            A_initializer initializer;
        }init_declarator;
        struct
        {
            A_declare ptr;
            A_declare direct_declarator;
        }declarator;
        struct
        {
            S_symbol identifier;
            bool hasParentheses;//小括号
            bool hasBracke;//中括号
            A_declare before;
            A_exp constExp;
            A_parameter_list lst;



        }direct_declarator;
        struct
        {
            E_declaration_specifier type;
            E_storage_class_specifier contentSC;
            E_type_specifier contentTS;
            E_type_qualifier contentTQ;
            A_declare next;
        }declaration_specifiers;
        struct
        {
            A_declare ptr;
            A_declare direct_abstract_declarator;
        }abstract_declarator;
        struct
        {

        }direct_abstract_declarator;

	}u;

};

struct A_declarationlist_
{
    A_declare dec;
    A_declarationlist next;
};

A_declare A_FuncDec(A_pos pos,A_type returnList, A_declare funcname, A_declarationlist args,A_statement body);
A_declare A_Declaration(A_pos pos,A_typelist lst, A_declarationlist initBody);
A_declarelist A_DeclarationList(A_pos,A_declarationlist lst,A_declare dec);
