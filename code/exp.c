enum A_operator {
    A_plus, A_minus, A_mul, A_div, A_mod,
    A_lt, A_le, A_gt, A_ge,
    A_positive, A_negative,
    A_xor, A_or, A_and, A_not,
    A_logical_and, A_logical_not, A_logical_or,
    A_assign, A_mul_assign, A_div_assign, A_mod_assign,
    A_and_assign, A_xor_assign, A_or_assign, A_plus_assign, A_minus_assign
};


struct A_type_;
struct A_var_;
struct A_exp_;
struct A_expList_;
struct A_field_;
struct A_fieldList_;

typedef struct A_type_ *A_type;
typedef struct A_var_ *A_var;
typedef struct A_exp_ *A_exp;
typedef struct A_expList_ *A_expList;
typedef struct A_field_ *A_field;
typedef struct A_fieldList_ *A_fieldList;
typedef struct A_dec_ *A_dec;
typedef struct A_decList_ *A_decList;

struct A_expList_ {A_exp head; A_expList tail;};
struct A_fieldList_ {A_field head; A_fieldList tail;};
struct A_decList_ {A_dec head; A_decList tail;};

typedef int A_pos;

struct A_field_
{
    S_symbol type;
    S_symbol name;
};

struct A_type_
{

};


struct A_var_
{
    enum {
        A_simpleVar, A_structUnionVar, A_pointerVar, A_arrayVar,
        A_enumVar, A_funcVar
    } kind;
    union {
        S_symbol simple;
        S_symbol funcName;
        struct {} pointer;
        struct { A_var var; A_exp offset; } array;
        struct { A_var var; S_symbol member; } structUnion;
    } u;
};

struct A_exp_
{
    enum {
        A_varExp, A_castExp, A_callExp, A_commaExp,
        A_binaryOpExp, A_unaryOpExp, A_condExp, A_assignExp,
        A_intExp, A_floatExp, A_nilExp
    } kind;
    union {
        A_var var;
        long ival;
        double fval;
        struct { S_symbol function; A_expList args;} call;
        A_expList comma;
        struct { A_exp left, right; A_operator operator_;} binaryOp;
        struct { A_exp exp; A_operator operator_;} unaryOp;
        struct { A_exp condition; A_exp true_, false_;} cond;
        struct { A_var var; A_exp exp; } assign;
        struct { S_symbol type; A_exp exp; } cast;
    } u;
};


A_exp A_VarExp(A_pos pos, A_var var);
A_exp A_CastExp(A_pos pos, S_symbol type, A_exp exp);
A_exp A_CallExp(A_pos pos, S_symbol function, A_expList args);
A_exp A_CommaExp(A_pos pos, A_expList);
A_exp A_BinaryOpExp(A_pos pos, A_operator op, A_exp left, A_exp right);
A_exp A_UnaryOpExp(A_pos pos, A_operator opt, A_exp opr);
A_exp A_CondOpExp(A_pos pos, A_exp true_, A_exp false_);
A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp);
A_exp A_IntExp(A_pos pos, long ival);
A_exp A_FloatExp(A_pos pos, double fval);
A_exp A_NilExp(A_pos pos);