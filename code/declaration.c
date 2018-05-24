struct A_pointer_
{
	
};

struct A_declarator_
{
	A_pointer pointer;
	S_symbol identifier;
	
};

struct A_initDeclarator_
{
	
};

struct A_declaration_
{
	enum{
		A_funcDec,A_declaration;
	}kind;

	union
	{
		struct 
		{
			A_type typeList
			A_declarator declarator;
			A_declarationList decList;
			A_statement body;

		}func;	
		struct
		{
			A_type typeList;
			vector<A_initDeclarator> initDeclaratorList;
		}dec;
	}u;

};

A_declaration A_FuncDec(A_pos pos,A_type returnList, A_declarator funcname, vector<A_declaration> args,A_statement body);
A_declaration A_Declaration(A_pos pos,vector<A_type> type, vector<A_initDeclarator> initBody);