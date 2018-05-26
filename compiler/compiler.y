%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "constant.h"
#include "type.h"
#include "declaration.h"
#include "statement.h"
#include "expression.h"

Node rootNode;

extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
extern int yylineno;
int yylex(void);
void yyerror(const char*);
%}

%union {
    struct Expr_ *expr;
    struct Stmt_ *stmt;
    struct Decl_ *decl;
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
        
	}
	| postfix_expression '(' argument_expression_list ')' {

	}
	| postfix_expression '.' IDENTIFIER {
        $$ = (Expr)new MemberExpr_($1, $3, false);
	}
	| postfix_expression PTR_OP IDENTIFIER {
        $$ = (Expr)new MemberExpr_($1, $3, true);
	}
	| postfix_expression INC_OP {
        $$ = (Expr)new UnaryOpExpr_($1, OP_UNARY_DOUBLEADD, true);
	}
	| postfix_expression DEC_OP {
        $$ = (Expr)new UnaryOpExpr_($1, OP_UNARY_DOUBLEMINUS, true);
	}
	;

//OP_BINARY_COMMA
argument_expression_list
	: assignment_expression { $$ = $1; }
	| argument_expression_list ',' assignment_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_COMMA, $3);
	}
	;

unary_expression
	: postfix_expression { $$ = $1; }
	| INC_OP unary_expression {
	    $$ = (Expr)new UnaryOpExpr_($2, OP_UNARY_DOUBLEADD, false);
	}
	| DEC_OP unary_expression {
	    $$ = (Expr)new UnaryOpExpr_($2, OP_UNARY_DOUBLEMINUS, false);
	}
	| unary_operator cast_expression {
	    $$ = (Expr)new UnaryOpExpr_($2, $1, false);
	}
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
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
	: unary_expression { $$ = $1; }
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression { $$ = $1; }
	| multiplicative_expression '*' cast_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_MULTIPLY, $3);
	}
	| multiplicative_expression '/' cast_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_DIV, $3);
	}
	| multiplicative_expression '%' cast_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_MOD, $3);
	}
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_ADD, $3);
	}
	| additive_expression '-' multiplicative_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_MINUS, $3);
	}
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_SHIFTLEFT, $3);
	}
	| shift_expression RIGHT_OP additive_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_SHIFTRIGHT, $3);
	}
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_ST, $3);
	}
	| relational_expression '>' shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_GT, $3);
	}
	| relational_expression LE_OP shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_SE, $3);
	}
	| relational_expression GE_OP shift_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_BE, $3);
	}
	;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression EQ_OP relational_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_EQ, $3);
	}
	| equality_expression NE_OP relational_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_NEQ, $3);
	}
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression {
         $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_AND, $3);
	}
	;

exclusive_or_expression
	: and_expression { $$ = $1; }
	| exclusive_or_expression '^' and_expression {
         $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_XOR, $3);
	}
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression {
         $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_OR, $3);
	}
	;

logical_and_expression
	: inclusive_or_expression { $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_LOGICAL_AND, $3);
	}
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression {
        $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_LOGICAL_OR, $3);
	}
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression {
        $$ = (Expr)new ConditionalExpr_($1, $3, $5);
	}
	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression assignment_operator assignment_expression {
        $$ = (Expr)new AssignExpr_($1, $2, $3);
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
	: assignment_expression { $$ = $1; }
	| expression ',' assignment_expression {
	    $$ = (Expr)new BinaryOpExpr_($1, OP_BINARY_COMMA, $3);
	}
	;

constant_expression
	: conditional_expression { $$ = $1; }
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
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
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
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

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
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

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%
void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int argc, char *argv[]) {
    yyparse();
    return 0;
}

