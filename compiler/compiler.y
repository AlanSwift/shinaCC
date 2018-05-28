%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "constant.h"
#include "type.h"
#include "declaration.h"
#include "statement.h"
#include "expression.h"
#include <iostream>
#include <list>

Node rootNode;

extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
extern int yylineno;

extern "C"{
    void yyerror(const char *s);
    extern int yylex(void);
}
%}

%union {
    struct Expr_ *expr;
    struct Stmt_ *stmt;
    struct Decl_ *decl;
    struct Type_ *type;
    std::list<struct Stmt_ *> *stmtList;
    std::list<struct Decl_ *> *declList;
    std::list<std::list<struct Decl_ *> *> *declsList;
    char *sval;
    int operator_;
}

%type <expr> expression primary_expression postfix_expression
assignment_expression unary_expression cast_expression
multiplicative_expression additive_expression shift_expression
relational_expression equality_expression and_expression
exclusive_or_expression inclusive_or_expression
logical_and_expression logical_or_expression conditional_expression
constant_expression argument_expression_list

%type <stmt> statement labeled_statement compound_statement
expression_statement selection_statement iteration_statement
jump_statement

%type <stmtList> statement_list

%type <decl> translation_unit function_definition init_declarator declarator direct_declarator

%type <declList> declaration external_declaration init_declarator_list

%type <declsList> declaration_list

%type <type> declaration_specifiers type_specifier

%type <operator_> unary_operator assignment_operator

%token <sval> IDENTIFIER
%token <expr> CONSTANT STRING_LITERAL
%token SIZEOF
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

/*expression*/

primary_expression
	: IDENTIFIER {
	    $$ = (Expr)new DeclRefExpr_(std::string($1));
	    free($1);
	    rootNode = (Node)$$;
	}
	| CONSTANT {
        $$ = (Expr)$1;
        rootNode = (Node)$$;
	}
	| STRING_LITERAL {
        $$ = (Expr)$1;
        rootNode = (Node)$$;
    }
	| '(' expression ')' {
	    ParenExpr p = new ParenExpr_($2);
	    $$ = (Expr)p;
	    rootNode = (Node)$$;
	}
	;

postfix_expression
	: primary_expression { $$ = $1; rootNode = (Node)$$; }
	| postfix_expression '[' expression ']' {
        $$ = (Expr)new ArraySubscriptExpr_($1, $3);
        rootNode = (Node)$$;
	}
	| postfix_expression '(' ')' {
        $$ = (Expr)new CallExpr_($1);
        rootNode = (Node)$$;
	}
	| postfix_expression '(' argument_expression_list ')' {
        rootNode = (Node)$$;
	}
	| postfix_expression '.' IDENTIFIER {
        $$ = (Expr)new MemberExpr_($1, $3, false);
        rootNode = (Node)$$;
	}
	| postfix_expression PTR_OP IDENTIFIER {
        $$ = (Expr)new MemberExpr_($1, $3, true);
        rootNode = (Node)$$;
	}
	| postfix_expression INC_OP {
        $$ = (Expr)new UnaryOpExpr_($1, OP_UNARY_DOUBLEADD, true);
        rootNode = (Node)$$;
	}
	| postfix_expression DEC_OP {
        $$ = (Expr)new UnaryOpExpr_($1, OP_UNARY_DOUBLEMINUS, true);
        rootNode = (Node)$$;
	}
	;

//OP_BINARY_COMMA
argument_expression_list
	: assignment_expression { $$ = $1;rootNode = (Node)$$; }
	| argument_expression_list ',' assignment_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_COMMA, $3);
	    rootNode = (Node)$$;
	}
	;

unary_expression
	: postfix_expression { $$ = $1; }
	| INC_OP unary_expression {
	    $$ = (Expr)new UnaryOpExpr_($2, OP_UNARY_DOUBLEADD, false);
	    rootNode = (Node)$$;
	}
	| DEC_OP unary_expression {
	    $$ = (Expr)new UnaryOpExpr_($2, OP_UNARY_DOUBLEMINUS, false);
	    rootNode = (Node)$$;
	}
	| unary_operator cast_expression {
	    $$ = (Expr)new UnaryOpExpr_($2, $1, false);
	    rootNode = (Node)$$;
	}
	| SIZEOF unary_expression {
        $$ = (Expr)new UnaryOpExpr_($2, OP_UNARY_SIZEOF, false);
        rootNode = (Node)$$;
	}
	| SIZEOF '(' type_name ')'{

	}
	;

unary_operator
	: '&' { $$ = OP_UNARY_AND; }
	| '*' { $$ = OP_UNARY_STAR; }
	| '+' { $$ = OP_UNARY_POSITIVE; }
	| '-' { $$ = OP_UNARY_NEGATIVE; }
	| '~' { $$ = OP_UNARY_NOT; }
	| '!' { $$ = OP_UNARY_LOGICAL_NOT; }
	;

cast_expression
	: unary_expression { $$ = $1;rootNode = (Node)$$; }
	| '(' type_name ')' cast_expression{

	}
	;

multiplicative_expression
	: cast_expression { $$ = $1;rootNode = (Node)$$; }
	| multiplicative_expression '*' cast_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_MULTIPLY, $3);
        rootNode = (Node)$$;
	}
	| multiplicative_expression '/' cast_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_DIV, $3);
	    rootNode = (Node)$$;
	}
	| multiplicative_expression '%' cast_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_MOD, $3);
	    rootNode = (Node)$$;
	}
	;

additive_expression
	: multiplicative_expression { $$ = $1;rootNode = (Node)$$; }
	| additive_expression '+' multiplicative_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_ADD, $3);
        rootNode = (Node)$$;
	}
	| additive_expression '-' multiplicative_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_MINUS, $3);
        rootNode = (Node)$$;
	}
	;

shift_expression
	: additive_expression { $$ = $1;rootNode = (Node)$$; }
	| shift_expression LEFT_OP additive_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_SHIFTLEFT, $3);
        rootNode = (Node)$$;
	}
	| shift_expression RIGHT_OP additive_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_SHIFTRIGHT, $3);
        rootNode = (Node)$$;
	}
	;

relational_expression
	: shift_expression { $$ = $1;rootNode = (Node)$$; }
	| relational_expression '<' shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_ST, $3);
        rootNode = (Node)$$;
	}
	| relational_expression '>' shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_GT, $3);
        rootNode = (Node)$$;
	}
	| relational_expression LE_OP shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_SE, $3);
        rootNode = (Node)$$;
	}
	| relational_expression GE_OP shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_BE, $3);
        rootNode = (Node)$$;
	}
	;

equality_expression
	: relational_expression { $$ = $1;rootNode = (Node)$$; }
	| equality_expression EQ_OP relational_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_EQ, $3);
        rootNode = (Node)$$;
	}
	| equality_expression NE_OP relational_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_NEQ, $3);
        rootNode = (Node)$$;
	}
	;

and_expression
	: equality_expression { $$ = $1;rootNode = (Node)$$; }
	| and_expression '&' equality_expression {
         $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_AND, $3);
         rootNode = (Node)$$;
	}
	;

exclusive_or_expression
	: and_expression { $$ = $1;rootNode = (Node)$$; }
	| exclusive_or_expression '^' and_expression {
         $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_XOR, $3);
         rootNode = (Node)$$;
	}
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1;rootNode = (Node)$$; }
	| inclusive_or_expression '|' exclusive_or_expression {
         $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_OR, $3);
         rootNode = (Node)$$;
	}
	;

logical_and_expression
	: inclusive_or_expression { $$ = $1;rootNode = (Node)$$; }
	| logical_and_expression AND_OP inclusive_or_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_LOGICAL_AND, $3);
        rootNode = (Node)$$;
	}
	;

logical_or_expression
	: logical_and_expression { $$ = $1;rootNode = (Node)$$; }
	| logical_or_expression OR_OP logical_and_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_LOGICAL_OR, $3);
        rootNode = (Node)$$;
	}
	;

conditional_expression
	: logical_or_expression { $$ = $1;rootNode = (Node)$$; }
	| logical_or_expression '?' expression ':' conditional_expression {
        $$ = (Expr)new ConditionalExpr_($1, $3, $5);
        rootNode = (Node)$$;
	}
	;

assignment_expression
	: conditional_expression { $$ = $1;rootNode = (Node)$$; }
	| unary_expression assignment_operator assignment_expression {
        $$ = (Expr)new AssignExpr_($1, $2, $3);
        rootNode = (Node)$$;
	}
	;

assignment_operator
	: '=' { $$ = OP_ASSIGN_EQ; }
	| MUL_ASSIGN { $$ = OP_ASSIGN_EQ_MULTIPLY; }
	| DIV_ASSIGN { $$ = OP_ASSIGN_EQ_DIV; }
	| MOD_ASSIGN { $$ = OP_ASSIGN_EQ_MOD; }
	| ADD_ASSIGN { $$ = OP_ASSIGN_EQ_ADD; }
	| SUB_ASSIGN { $$ = OP_ASSIGN_EQ_MINUS; }
	| LEFT_ASSIGN { $$ = OP_ASSIGN_EQ_SHIFTLEFT; }
	| RIGHT_ASSIGN { $$ = OP_ASSIGN_EQ_SHIFTRIGHT; }
	| AND_ASSIGN { $$ = OP_ASSIGN_EQ_AND; }
	| XOR_ASSIGN { $$ = OP_ASSIGN_EQ_XOR; }
	| OR_ASSIGN { $$ = OP_ASSIGN_EQ_OR; }
	;

expression
	: assignment_expression { $$ = $1;rootNode = (Node)$$; }
	| expression ',' assignment_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_COMMA, $3);
	    rootNode = (Node)$$;
	}
	;

constant_expression
	: conditional_expression { $$ = $1;rootNode = (Node)$$; }
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier {
	}
	| storage_class_specifier declaration_specifiers {
        $$ = $2;
    }
	| type_specifier {
        $$ = $1;
	}
	| type_specifier declaration_specifiers {
        ((BuiltinType)$1)->next = $2;
        $$ = $1;
	}
	| type_qualifier
	| type_qualifier declaration_specifiers {
	    $$ = $2;
	}
	;

init_declarator_list
	: init_declarator
	{
        $$=new std::list<Decl>();
        $$->push_back($1);
	}
	| init_declarator_list ',' init_declarator
	{
	    $$=$1->push_back($2);
	}
	;

init_declarator
	: declarator
	{
	    $$=$1;
	}
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_VOID, NULL); }
	| CHAR { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_CHAR, NULL); }
	| SHORT { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_SHORT, NULL); }
	| INT { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_INT, NULL); }
	| LONG { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_LONG, NULL); }
	| FLOAT { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_FLOAT, NULL); }
	| DOUBLE { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_DOUBLE, NULL); }
	| SIGNED { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_SIGNED, NULL); }
	| UNSIGNED { $$ = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED, NULL); }
	| struct_or_union_specifier {}
	| enum_specifier {}
	| TYPE_NAME {}
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator

	| direct_declarator
	{
	    $$=$1;
	}
	;

direct_declarator
	: IDENTIFIER
	{
        $$=new Decl();
        $$->name=std::string($1);
        free($1);
	}
	| '(' declarator ')'
	{
        $$=$2;
	}

	| direct_declarator '[' constant_expression ']'
	{
	    $$=new VarDecl_();
	    $$->name=$1->name;
	    delete $1;
	    $$->type=new ArrayType_(NULL,$3);
	}
	| direct_declarator '[' ']'
	{
	    $$=new VarDecl_();
	    $$->name=$1->name;
	    delete $1;
	    $$->type=new ArrayType_(NULL,NULL);
	}
	| direct_declarator '(' parameter_type_list ')'
	{
	    $$=new FunctionDecl_($1->name,NULL,$3,NULL);
	}
	| direct_declarator '(' identifier_list ')'
	{
	    $$=new FunctionDecl_($1->name,NULL,$3,NULL);
	}
	| direct_declarator '(' ')'
	{
	    $$=new FunctionDecl_($1->name,NULL,$3,NULL);
	}
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
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

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
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

statement
	: labeled_statement { $$ = $1; rootNode = (Node)$$; }
	| compound_statement { $$ = $1; rootNode = (Node)$$; }
	| expression_statement { $$ = $1; rootNode = (Node)$$; }
	| selection_statement { $$ = $1; rootNode = (Node)$$; }
	| iteration_statement { $$ = $1; rootNode = (Node)$$; }
	| jump_statement { $$ = $1; rootNode = (Node)$$; }
	;

labeled_statement
	: IDENTIFIER ':' statement {
	    $$ = (Stmt)new LabelStmt_(std::string($1), $3);
	    free($1);
	    rootNode = (Node)$$;
	}
	| CASE constant_expression ':' statement {
        $$ = (Stmt)new CaseStmt_($2, $4);
        rootNode = (Node)$$;
	}
	| DEFAULT ':' statement {
	    $$ = (Stmt)new DefaultStmt_($3);
	    rootNode = (Node)$$;
	}
	;

compound_statement
	: '{' '}' {
	    $$ = (Stmt)new CompoundStmt_();
	    rootNode = (Node)$$;
	}
	| '{' statement_list '}' {
        $$ = (Stmt)new CompoundStmt_(*$2);
        rootNode = (Node)$$;
        delete $2;
	}
	| '{' declaration_list '}' {
        $$ = (Stmt)new CompoundStmt_();
        std::list<std::list<struct Decl_ *> *>::iterator it;
        for(it = $2->begin(); it != $2->end(); it++){
            Stmt varDecl = (Stmt)new DeclStmt_(*(*it));
            ((CompoundStmt)$$)->addStatement(varDecl);
        }
        delete $2;
        rootNode = (Node)$$;
	}
	| '{' declaration_list statement_list '}' {
	    $$ = (Stmt)new CompoundStmt_();
        std::list<std::list<struct Decl_ *> *>::iterator it;
        for(it = $2->begin(); it != $2->end(); it++){
            Stmt varDecl = (Stmt)new DeclStmt_(*(*it));
            ((CompoundStmt)$$)->addStatement(varDecl);
        }
        delete $2;
        std::list<struct Stmt_ *>::iterator it2;
        for(it2 = $3->begin(); it2 != $3->end(); it2++){
            ((CompoundStmt)$$)->addStatement((*it2));
        }
        delete $3;
        rootNode = (Node)$$;
	}
	;

declaration_list
	: declaration {
	    $$ = new std::list<std::list<struct Decl_ *>*>;
	    $$->push_back($1);
	}
	| declaration_list declaration {
	    $1->push_back($2);
	    $$ = $1;
	}
	;

statement_list
	: statement {
	    $$ = new std::list<Stmt>;
	    $$->push_back($1);
	}
	| statement_list statement {
	    $$->push_back($2);
	}
	;

expression_statement
	: ';' {
	    $$ = (Stmt)new NullStmt_();
        rootNode = (Node)$$;
	}
	| expression ';' {
	    $$ = (Stmt)new ExprStmt_($1);
	    rootNode = (Node)$$;
	}
	;

selection_statement
	: IF '(' expression ')' statement {
	    $$ = (Stmt)new IfStmt_($3, $5, NULL);
        rootNode = (Node)$$;
	}
	| IF '(' expression ')' statement ELSE statement {
        $$ = (Stmt)new IfStmt_($3, $5, $7);
        rootNode = (Node)$$;
	}
	| SWITCH '(' expression ')' statement {
        $$ = (Stmt)new SwitchStmt_($3, $5);
        rootNode = (Node)$$;
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement {
        $$ = (Stmt)new WhileStmt_($5, $3);
        rootNode = (Node)$$;
	}
	| DO statement WHILE '(' expression ')' ';' {
	    $$ = (Stmt)new DoStmt_($2, $5);
        rootNode = (Node)$$;
	}
	| FOR '(' expression_statement expression_statement ')' statement {
        Expr expr1, expr2;
        if($3->id == NODE_STM_NULL)
            expr1 = NULL;
        else
            expr1 = ((ExprStmt)$3)->expr;
        if($4->id == NODE_STM_NULL)
            expr2 = NULL;
        else
            expr2 = ((ExprStmt)$4)->expr;
        $$ = (Stmt)new ForStmt_(expr1, expr2, NULL, $6);
        rootNode = (Node)$$;
	}
	| FOR '(' expression_statement expression_statement expression ')' statement {
        Expr expr1, expr2;
        if($3->id == NODE_STM_NULL)
            expr1 = NULL;
        else
            expr1 = ((ExprStmt)$3)->expr;
        if($4->id == NODE_STM_NULL)
            expr2 = NULL;
        else
            expr2 = ((ExprStmt)$4)->expr;
        $$ = (Stmt)new ForStmt_(expr1, expr2, $5, $7);
        rootNode = (Node)$$;
	}
	;

jump_statement
	: GOTO IDENTIFIER ';' {
        $$ = (Stmt)new GoToStmt_(std::string($2));
        rootNode = (Node)$$;
        free($2);
	}
	| CONTINUE ';' {
        $$ = (Stmt)new ContinueStmt_();
        rootNode = (Node)$$;
	}
	| BREAK ';'{
        $$ = (Stmt)new BreakStmt_();
        rootNode = (Node)$$;
	}
	| RETURN ';'{
        $$ = (Stmt)new ReturnStmt_(NULL);
        rootNode = (Node)$$;
	}
	| RETURN expression ';'{
        $$ = (Stmt)new ReturnStmt_($2);
        rootNode = (Node)$$;
	}
	;

translation_unit
	: external_declaration {
	    $$ = (Decl)new TranslationUnitDecl_();
	    std::list<Decl>::iterator it;
        for(it = $1->begin(); it != $1->end(); it++){
            ((TranslationUnitDecl)$$)->addDeclaration(*it);
        }
        delete $1;
	    rootNode = (Node)$$;
	}
	| translation_unit external_declaration {
	    std::list<Decl>::iterator it;
	    for(it = $2->begin(); it != $2->end(); it++){
            ((TranslationUnitDecl)$1)->addDeclaration(*it);
        }
        delete $2;
	    $$ = (TranslationUnitDecl)$1;
	    rootNode = (Node)$$;
	}
	;

external_declaration
	: function_definition {
        $$ = new std::list<Decl>();
        $$->push_back($1);
     }
	| declaration {
	    $$ = new std::list<Decl>();
        std::list<Decl>::iterator it;
        for(it = $1->begin(); it != $1->end(); it++){
            $$->push_back(*it);
        }
        delete $1;

	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
        //$$ = (Decl)new FunctionDecl_($1, $4);
	}
	| declaration_specifiers declarator compound_statement {

	}
	| declarator declaration_list compound_statement {

	}
	| declarator compound_statement {

	}
	;

%%

void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int argc, char *argv[]) {
    yyparse();
    std::cout << std::endl << "-------------------------------------------------------" << std::endl;
    rootNode->show();
    return 0;
}

