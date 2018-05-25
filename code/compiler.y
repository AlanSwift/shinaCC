%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
extern int yylineno;

int yylex(void);
void yyerror(const char*);

%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'    {$$=A_declaration A_Declaration(0,$1, NULL);}
	| declaration_specifiers init_declarator_list ';'   {$$=A_declaration A_Declaration(0,$1, $2);}
	;

declaration_specifiers
	: storage_class_specifier   {$$=A_DecSpeciferList(0,NULL,DS_storage_class_specifier,$1);}
	| storage_class_specifier declaration_specifiers    {$$=A_DecSpeciferList(0,$1,DS_storage_class_specifier,$2);}
	| type_specifier    {$$=A_DecSpeciferList(0,NULL,DS_type_specifier,$1);}
	| type_specifier declaration_specifiers {$$=A_DecSpeciferList(0,$1,DS_type_specifier,$2);}
	| type_qualifier    {$$=A_DecSpeciferList(0,NULL,DS_type_qualifier,$1);}
	| type_qualifier declaration_specifiers {$$=A_DecSpeciferList(0,$1,DS_type_qualifier,$2);}
	;

init_declarator_list
	: init_declarator   {$$=A_InitDeclaratorList(0,NULL,$1);}
	| init_declarator_list ',' init_declarator  {$$=A_InitDeclaratorList(0,$1,$2);}
	;

init_declarator
	: declarator    {$$=A_InitDeclarator(0,$1, NULL);}
	| declarator '=' initializer    {$$=A_InitDeclarator(0,$1, $2);}
	;

storage_class_specifier
	: TYPEDEF   {$$=SC_TYPEDEF;}
	| EXTERN    {$$=SC_EXTERN;}
	| STATIC    {$$=SC_STATIC;}
	| AUTO      {$$=SC_AUTO;}
	| REGISTER  {$$=SC_REGISTER;}
	;

type_specifier
	: VOID      {$$=TS_VOID;}
	| CHAR      {$$=TS_CHAR;}
	| SHORT     {$$=TS_SHORT;}
	| INT       {$$=TS_INT;}
	| LONG      {$$=TS_LONG;}
	| FLOAT     {$$=TS_FLOAT;}
	| DOUBLE    {$$=TS_DOUBLE;}
	| SIGNED    {$$=TS_SIGNED;}
	| UNSIGNED  {$$=TS_UNSIGNED;}
	| struct_or_union_specifier {$$=$1;}
	| enum_specifier    {$$=TS_ENUM;}
	| TYPE_NAME         {$$=TS_TYPENAME;}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT    {$$=TS_STRUCT;}
	| UNION     {$$=TS_UNION}
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST {$$=TQ_CONST;}
	| VOLATILE  {$$=TQ_VOLATILE;}
	;

declarator
	: pointer direct_declarator     {$$=A_Declarator(0,$1,$2);}
	| direct_declarator {$$=A_Declarator(0,NULL,$2);}
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'   {$$=A_Pointer(0, NULL,NULL);}
	| '*' type_qualifier_list   {$$=A_Pointer(0, $1,NULL);}
	| '*' pointer   {$$=A_Pointer(0, NULL,$1);}
	| '*' type_qualifier_list pointer   {$$=A_Pointer(0, $1,$2);}
	;

type_qualifier_list
	: type_qualifier    {$$=A_TypequalifierList(0,NULL,$1);}
	| type_qualifier_list type_qualifier    {$$=A_TypequalifierList(0,$1,$2);}
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement     {$$=$1;}
	| compound_statement    {$$=$1;}
	| expression_statement  {$$=$1;}
	| selection_statement   {$$=$1;}
	| iteration_statement   {$$=$1;}
	| jump_statement        {$$=$1;}
	;

labeled_statement
	: IDENTIFIER ':' statement                  {$$=A_IdentifierLabeledStatement(0, S_symbol($1), $3);}
	| CASE constant_expression ':' statement    {$$=A_CaseLabeledStatement(0, $2, $4);}
	| DEFAULT ':' statement                     {$$=A_DefaultLabeledStatement(0, $3);}
	;

compound_statement
	: '{' '}'                                   {$$=A_StmList(0,NULL,NULL);}
	| '{' statement_list '}'                    {$$=$2;}
	| '{' declaration_list '}'                  {$$=$2;}
	| '{' declaration_list statement_list '}'   {$$=A_statement A_CompdStatement(A_pos pos, $2,$3);}
	;

declaration_list
	: declaration       {$$=A_DeclarationList(0,NULL,$1);}
	| declaration_list declaration  {$$=A_DeclarationList(0,$1,$2);}
	;

statement_list
	: statement                 {$$=A_StmList(0,NULL,$1);}
	| statement_list statement  {$$=A_StmList(0,$1,$2);}
	;

expression_statement
	: ';'               {$$=A_ExpStatement(0,NULL);}
	| expression ';'    {$$=A_ExpStatement(0,$1);}
	;

selection_statement
	: IF '(' expression ')' statement                   {$$=A_IfSelectStatement(0, $3, $5,NULL);}
	| IF '(' expression ')' statement ELSE statement    {$$=A_IfSelectStatement(0, $3, $5,$7);}
	| SWITCH '(' expression ')' statement               {$$=A_SwitchSelectStatement(0, $3, $5);}
	;

iteration_statement
	: WHILE '(' expression ')' statement    {$$=A_WhileSelectStatement(0,$3, $5);}
	| DO statement WHILE '(' expression ')' ';'     {$$=A_DoWhileSelectStatement(0, $2, $4);}
	| FOR '(' expression_statement expression_statement ')' statement   {$$=A_ForSelectStatement(0,$3, $4, NULL,$6);}
	| FOR '(' expression_statement expression_statement expression ')' statement    {$$=A_ForSelectStatement(0,$3, $4, $5,$7);}
	;

jump_statement
	: GOTO IDENTIFIER ';'   {$$=A_JumpStatement(0,S_symbol($1),S_symbol($2), NULL);}
	| CONTINUE ';'  {$$=A_JumpStatement(0,S_symbol($1),NULL, NULL);}
	| BREAK ';' {$$=A_JumpStatement(0,S_symbol($1),NULL, NULL);}
	| RETURN ';'    {$$=A_JumpStatement(0,S_symbol($1),NULL, NULL);}
	| RETURN expression ';' {$$=A_JumpStatement(0,S_symbol($1),NULL, $1);}
	;

translation_unit
	: external_declaration  {$$=A_DecList(0,NULL,$1);}
	| translation_unit external_declaration {$$=A_DecList(0,$1,$2);}
	;

external_declaration
	: function_definition   {$$=$1;}
	| declaration           {$$=$1;}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement     {$$=A_FuncDec(0,$1, $2, $3,$4);}
	| declaration_specifiers declarator compound_statement  {$$=A_FuncDec(0,$1, $2, NULL,$3);}
	| declarator declaration_list compound_statement    {$$=A_FuncDec(0,NULL, $1, $2,$3);}
	| declarator compound_statement     {$$=A_FuncDec(0,NULL, $1, NULL,$2);}
	;

%%


void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}