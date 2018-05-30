/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler.y" /* yacc.c:339  */

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
#include <cassert>

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

#line 93 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELLIPSIS 303
#define CASE 304
#define DEFAULT 305
#define IF 306
#define ELSE 307
#define SWITCH 308
#define WHILE 309
#define DO 310
#define FOR 311
#define GOTO 312
#define CONTINUE 313
#define BREAK 314
#define RETURN 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "compiler.y" /* yacc.c:355  */

    struct Expr_ *expr;
    struct Stmt_ *stmt;
    struct Decl_ *decl;
    struct Type_ *type;
    std::list<struct Stmt_ *> *stmtList;
    std::list<struct Decl_ *> *declList;
    std::list<struct Expr_ *> *exprList;
    std::list<std::list<struct Decl_ *> *> *declsList;
    char *sval;
    int operator_;

#line 266 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 283 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    92,    96,   100,   108,   109,   113,   117,
     122,   126,   130,   134,   142,   146,   153,   154,   158,   162,
     166,   170,   176,   177,   178,   179,   180,   181,   185,   186,
     192,   193,   197,   201,   208,   209,   213,   220,   221,   225,
     232,   233,   237,   241,   245,   252,   253,   257,   264,   265,
     272,   273,   280,   281,   288,   289,   296,   297,   304,   305,
     312,   313,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   334,   335,   342,   346,   347,   358,   360,
     363,   366,   370,   371,   377,   382,   390,   394,   404,   405,
     406,   407,   408,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   427,   428,   432,   437,   444,
     450,   455,   464,   469,   508,   543,   569,   572,   575,   578,
     584,   585,   590,   594,   601,   606,   614,   627,   628,   635,
     643,   653,   654,   658,   659,   660,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   676,   680,   681,   685,   688,
     694,   695,   696,   700,   701,   705,   706,   710,   714,   715,
     716,   717,   721,   722,   726,   727,   728,   732,   733,   734,
     738,   739,   743,   744,   748,   749,   750,   751,   752,   753,
     757,   762,   766,   773,   777,   782,   792,   810,   814,   821,
     825,   831,   835,   842,   846,   850,   857,   861,   865,   878,
     894,   899,   903,   907,   911,   918,   927,   939,   943,   955,
     958,   963,   966
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -202

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-202)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     933,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,     6,    11,     1,  -202,    13,  1218,  1218,  1218,  1065,
      77,    15,  -202,     8,  -202,   843,  -202,  -202,   -60,    26,
     -29,  -202,  -202,     1,  -202,   -15,  -202,  1045,  -202,  -202,
    -202,   283,  -202,    13,  -202,  1065,   413,   646,    77,   -20,
    1019,  -202,  -202,    26,    -3,   -18,  -202,  -202,  -202,  -202,
      11,  -202,   547,  -202,  1065,    18,  -202,  -202,   761,   798,
     798,   831,    43,   125,   135,   156,   529,   175,   211,   144,
     169,   140,   634,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,   172,   282,   831,  -202,    68,   134,   257,    34,
     260,   180,   177,   178,   242,    17,  -202,  -202,    20,  -202,
    -202,  -202,   353,   423,  -202,  -202,  -202,  -202,   181,  -202,
    -202,  -202,  -202,    57,   203,   206,  -202,     2,  -202,  -202,
    -202,  -202,   205,  1019,  1019,  1019,   968,  -202,    19,   -13,
     831,    26,  -202,  -202,   547,  -202,  -202,  -202,   529,   634,
    -202,   831,  -202,  -202,   198,   529,   831,   831,   831,   226,
     564,   202,  -202,  -202,  -202,    35,   122,   228,    61,   294,
    -202,  -202,   679,   831,   296,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,   831,  -202,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,  -202,  -202,
     459,  -202,  -202,   888,   716,  -202,    14,  -202,   182,  -202,
    1197,  -202,   307,  -202,   988,  -202,  -202,  -202,  -202,   831,
     251,    55,  -202,  -202,  -202,  -202,  -202,   -11,  -202,   273,
     529,  -202,   133,   153,   154,   284,   564,  -202,  -202,  -202,
     831,  1121,   185,  -202,  -202,  -202,   162,  -202,   186,  -202,
    -202,  -202,  -202,  -202,    68,    68,   134,   134,   257,   257,
     257,   257,    34,    34,   260,   180,   177,   178,   242,   -26,
    -202,  -202,  -202,   285,   286,  -202,   300,   182,  1162,   728,
    -202,  -202,  -202,  -202,  -202,   831,    19,  -202,   493,  -202,
    -202,  -202,   529,   529,   529,   831,   749,  -202,  -202,   831,
    -202,   831,  -202,  -202,  -202,  -202,   287,  -202,   304,  -202,
    -202,  -202,  -202,   308,  -202,  -202,   163,   529,   165,  -202,
    -202,  -202,  -202,   529,   264,  -202,   529,  -202,  -202,  -202
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   109,   104,    88,    89,    90,    91,    92,    94,    95,
      96,    97,   100,   101,    98,    99,   105,   106,    93,   153,
     154,     0,     0,   116,   208,     0,    78,    80,    82,     0,
     108,     0,   102,     0,   103,     0,   205,   207,   169,     0,
       0,   120,   118,   117,    76,     0,    84,    86,    79,    81,
      83,     0,   187,     0,   212,     0,     0,     0,   107,   152,
       0,     1,   206,     0,   172,     0,   170,   110,   121,   119,
       0,    77,     0,   210,     0,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,   191,
     183,     6,    16,    28,     0,    30,    34,    37,    40,    45,
      48,    50,    52,    54,    56,    58,    60,    73,     0,   189,
     174,   175,     0,     0,   176,   177,   178,   179,    86,   188,
     211,   129,   115,   128,     0,   122,   124,     0,     2,   112,
      28,    75,     0,     0,   159,   161,     0,   155,     0,     0,
       0,     0,   167,    85,     0,   145,    87,   209,     0,     0,
      20,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   202,   203,     0,     0,     0,   131,     0,
      12,    13,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    62,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   185,
       0,   184,   190,     0,     0,   126,   133,   127,   134,   113,
       0,   114,     0,   111,     0,   158,   160,   151,   156,     0,
     164,     0,   162,   168,   173,   171,   148,     0,   180,     0,
       0,   182,     0,     0,     0,     0,     0,   200,   204,     5,
       0,     0,   133,   132,    11,     8,     0,    14,     0,    10,
      61,    31,    32,    33,    35,    36,    38,    39,    43,    44,
      41,    42,    46,    47,    49,    51,    53,    55,    57,     0,
      74,   186,   141,     0,     0,   137,     0,   135,     0,     0,
     123,   125,   130,   150,   165,     0,     0,   157,     0,   146,
      21,   181,     0,     0,     0,     0,     0,    29,     9,     0,
       7,     0,   142,   136,   138,   143,     0,   139,     0,   166,
     163,   147,   149,   193,   195,   196,     0,     0,     0,    15,
      59,   144,   140,     0,     0,   198,     0,   194,   197,   199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,  -202,   -42,  -202,   -85,    75,    90,   -53,
      86,   159,   157,   160,   161,   164,  -202,   -50,   -66,  -202,
     -33,   -39,    10,     0,  -202,   301,  -202,   -40,    47,   -21,
     -28,    -2,  -202,   -54,  -202,   142,  -202,   215,  -121,  -201,
    -130,  -202,  -202,  -202,   233,  -141,   -62,  -202,    71,  -202,
     315,   229,   -73,  -202,   158,   187,   279,  -162,  -202,  -202,
    -202,  -202,   370,  -202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   101,   102,   266,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   196,
     118,   142,    52,    53,    45,    46,    26,    27,    28,    29,
      30,    31,    43,   293,   135,   136,   137,   177,   294,   228,
     156,   247,    32,    33,   146,   147,   148,   241,   242,    34,
      65,    66,   119,   120,   121,    55,   123,   124,   125,   126,
     127,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      25,    40,   134,    58,    47,   238,   155,   141,   256,    38,
      24,    59,   227,   169,     1,   140,     1,     1,     1,   197,
     144,    42,     1,    63,   246,   297,    48,    49,    50,    64,
     178,   141,   128,    67,   215,    25,   160,   162,   163,   140,
     217,    69,   164,    16,    17,    24,   205,   206,   151,   128,
     222,    70,   144,   151,   321,   308,   133,   263,   175,   176,
       1,   297,   140,   143,   231,   129,   152,    71,   232,    23,
      41,   243,    22,   309,    22,   223,    22,   224,   150,    23,
      22,    23,   235,   236,   129,   248,   217,    23,   155,    39,
      68,    60,   251,   238,   316,    44,   216,   178,   158,   239,
     141,   217,   218,   144,   144,   144,   144,   145,   140,   207,
     208,   244,   225,   271,   272,   273,   267,   258,   223,   144,
     224,   306,   261,   165,   224,    23,   176,   240,   176,    23,
     270,   226,   129,   252,   253,   254,   198,   307,    56,   145,
      57,   199,   200,   138,    76,    77,    78,   222,    79,    80,
     268,   290,   278,   279,   280,   281,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   317,   262,   311,   332,   179,
     180,   181,   140,   289,   259,   296,   166,    54,   217,   141,
     145,   145,   145,   145,   144,   312,   167,   140,    58,   217,
     304,    92,    40,   201,   202,    73,   145,    93,    94,    95,
      96,    97,    98,   130,   171,   313,   314,   168,   140,   217,
     217,   226,   174,   133,   318,   344,   172,   346,   319,   217,
     133,   217,   157,   182,    74,   183,   170,   184,   122,   333,
     334,   335,   155,   298,   326,   299,   261,   211,   224,   141,
     320,   173,   217,   339,   212,   141,   213,   140,   214,   262,
     328,   133,    72,   140,   345,   229,   329,   203,   204,   233,
     347,   340,   230,   349,   209,   210,   274,   275,   250,   140,
     255,   145,   336,   338,   257,   240,    75,    76,    77,    78,
     260,    79,    80,   276,   277,   282,   283,   264,   133,   269,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     302,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   305,    81,    82,    83,   310,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   315,   348,   322,   323,   341,
      93,    94,    95,    96,    97,    98,    75,    76,    77,    78,
     343,    79,    80,   195,   324,    99,    51,   100,   342,   285,
     284,   153,   301,   286,   249,   287,   234,   330,   149,   288,
     245,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   220,    81,    82,    83,    62,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,   131,     0,     0,     0,
      93,    94,    95,    96,    97,    98,    75,    76,    77,    78,
       0,    79,    80,     0,     0,    99,    51,   219,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    75,    76,    77,    78,     0,    79,    80,     0,
       0,     0,    81,    82,    83,   132,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,     0,
      93,    94,    95,    96,    97,    98,   138,    76,    77,    78,
       0,    79,    80,     0,     0,    99,    51,   221,    81,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    75,    76,    77,    78,     0,    79,    80,     0,
       0,    99,    51,   291,     0,     0,     0,     0,     0,     0,
     138,    76,    77,    78,    92,    79,    80,     0,     0,     0,
      93,    94,    95,    96,    97,    98,     0,   138,    76,    77,
      78,     0,    79,    80,     0,     0,   154,   331,    81,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    99,    51,     0,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
     154,    93,    94,    95,    96,    97,    98,   138,    76,    77,
      78,     0,    79,    80,     0,     0,    99,     0,     0,   138,
      76,    77,    78,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   138,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    92,     0,     0,
     139,     0,     0,    93,    94,    95,    96,    97,    98,   138,
      76,    77,    78,     0,    79,    80,     0,     0,     0,     0,
       0,   138,    76,    77,    78,     0,    79,    80,     0,     0,
      92,   265,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,   138,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,     0,   138,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,    92,     0,     0,
     295,     0,     0,    93,    94,    95,    96,    97,    98,    92,
       0,     0,   327,     0,     0,    93,    94,    95,    96,    97,
      98,   138,    76,    77,    78,     0,    79,    80,     0,     0,
      92,   337,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,   159,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,    98,   138,    76,    77,    78,     0,    79,
      80,     0,     0,    61,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,    93,    94,    95,    96,    97,
      98,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,    92,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    22,     0,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   223,
     292,   224,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     2,     0,     0,     0,
       0,    23,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     2,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,   237,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,   303,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   292,   224,     0,     0,     0,     0,    23,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   325,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   300,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    22,    56,    31,    25,   146,    72,    57,   170,     3,
       0,     3,   133,    86,     3,    57,     3,     3,     3,   104,
      60,    23,     3,    83,   154,   226,    26,    27,    28,     3,
      92,    81,    53,    62,    17,    35,    78,    79,    80,    81,
      66,    43,    81,    42,    43,    35,    12,    13,    66,    70,
     123,    66,    92,    66,    80,    66,    56,   178,    91,    92,
       3,   262,   104,    83,    62,    55,    84,    82,    66,    68,
      23,    84,    61,    84,    61,    61,    61,    63,    81,    68,
      61,    68,   144,   145,    74,   158,    66,    68,   154,    83,
      43,    83,   165,   234,   256,    82,    79,   159,    80,    80,
     150,    66,    82,   143,   144,   145,   146,    60,   150,    75,
      76,   150,   133,   198,   199,   200,   182,    82,    61,   159,
      63,    66,    61,    80,    63,    68,   159,   148,   161,    68,
     196,   133,   122,   166,   167,   168,    68,    82,    61,    92,
      63,    73,    74,     3,     4,     5,     6,   220,     8,     9,
     183,   217,   205,   206,   207,   208,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   224,   260,   178,   250,   308,     7,
       8,     9,   224,   216,    62,   224,    61,    29,    66,   239,
     143,   144,   145,   146,   234,    62,    61,   239,   226,    66,
     239,    61,   223,    69,    70,    47,   159,    67,    68,    69,
      70,    71,    72,    55,     3,    62,    62,    61,   260,    66,
      66,   223,    82,   223,    62,    62,    82,    62,    66,    66,
     230,    66,    74,    61,    47,    63,    61,    65,    51,   312,
     313,   314,   308,    61,   298,    63,    61,    67,    63,   299,
      64,    82,    66,   319,    77,   305,    78,   299,    16,   261,
     299,   261,    81,   305,   337,    62,   305,    10,    11,    64,
     343,   321,    66,   346,    14,    15,   201,   202,    80,   321,
      54,   234,   315,   316,    82,   306,     3,     4,     5,     6,
      62,     8,     9,   203,   204,   209,   210,     3,   298,     3,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       3,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    80,    49,    50,    51,    62,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    61,    82,    62,    62,    62,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      52,     8,     9,    81,    64,    82,    83,    84,    64,   212,
     211,    70,   230,   213,   159,   214,   143,   306,    63,   215,
     151,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   122,    49,    50,    51,    35,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,     3,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    49,    50,    51,    62,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    82,    83,    84,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    61,     8,     9,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    83,    84,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    82,    83,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      83,    67,    68,    69,    70,    71,    72,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    82,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    61,
      -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,     0,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    28,    -1,    -1,    -1,
      -1,    68,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    28,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    84,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    84,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    68,   107,   108,   111,   112,   113,   114,
     115,   116,   127,   128,   134,   146,   147,   148,     3,    83,
     114,   113,   116,   117,    82,   109,   110,   114,   108,   108,
     108,    83,   107,   108,   139,   140,    61,    63,   115,     3,
      83,     0,   147,    83,     3,   135,   136,    62,   113,   116,
      66,    82,    81,   139,   140,     3,     4,     5,     6,     8,
       9,    49,    50,    51,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    67,    68,    69,    70,    71,    72,    82,
      84,    86,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   105,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   114,   107,
     139,     3,    62,   108,   118,   119,   120,   121,     3,    64,
      89,   102,   106,    83,   112,   113,   129,   130,   131,   135,
      81,    66,    84,   110,    83,   103,   125,   139,    80,    61,
      89,    61,    89,    89,   106,    80,    61,    61,    61,   137,
      61,     3,    82,    82,    82,   105,   105,   122,   131,     7,
       8,     9,    61,    63,    65,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    81,   104,    91,    68,    73,
      74,    69,    70,    10,    11,    12,    13,    75,    76,    14,
      15,    67,    77,    78,    16,    17,    79,    66,    82,    84,
     141,    84,   137,    61,    63,   114,   116,   123,   124,    62,
      66,    62,    66,    64,   129,   131,   131,    84,   130,    80,
     114,   132,   133,    84,   106,   136,   125,   126,   137,   122,
      80,   137,   105,   105,   105,    54,   142,    82,    82,    62,
      62,    61,   116,   123,     3,    62,    88,   103,   105,     3,
     103,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    96,    97,    98,    99,   100,   105,
     103,    84,    62,   118,   123,    64,   106,   124,    61,    63,
      48,   120,     3,    84,   106,    80,    66,    82,    66,    84,
      62,   137,    62,    62,    62,    61,   142,    91,    62,    66,
      64,    80,    62,    62,    64,    62,   118,    64,   106,   106,
     133,    84,   125,   137,   137,   137,   105,    62,   105,   103,
     102,    62,    64,    52,    62,   137,    62,   137,    82,   137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   126,   126,
     127,   127,   127,   128,   128,   129,   129,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   134,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     4,     3,     4,     4,     3,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     2,     1,     1,
       3,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     2,     3,     3,     4,     1,     3,     4,     1,     3,
       5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 87 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new DeclRefExpr_(std::string((yyvsp[0].sval)));
	    free((yyvsp[0].sval));
	    rootNode = (Node)(yyval.expr);
	}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)(yyvsp[0].expr);
        rootNode = (Node)(yyval.expr);
	}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)(yyvsp[0].expr);
        rootNode = (Node)(yyval.expr);
    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "compiler.y" /* yacc.c:1646  */
    {
	    ParenExpr p = new ParenExpr_((yyvsp[-1].expr));
	    (yyval.expr) = (Expr)p;
	    rootNode = (Node)(yyval.expr);
	}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); rootNode = (Node)(yyval.expr); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new ArraySubscriptExpr_((yyvsp[-3].expr), (yyvsp[-1].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new CallExpr_((yyvsp[-2].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new CallExpr_((yyvsp[-3].expr), *(yyvsp[-1].exprList));
	    delete (yyvsp[-1].exprList);
        rootNode = (Node)(yyval.expr);
	}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new MemberExpr_((yyvsp[-2].expr), (yyvsp[0].sval), false);
        rootNode = (Node)(yyval.expr);
	}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 126 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new MemberExpr_((yyvsp[-2].expr), (yyvsp[0].sval), true);
        rootNode = (Node)(yyval.expr);
	}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 130 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[-1].expr), OP_UNARY_DOUBLEADD, true);
        rootNode = (Node)(yyval.expr);
	}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[-1].expr), OP_UNARY_DOUBLEMINUS, true);
        rootNode = (Node)(yyval.expr);
	}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 142 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.exprList) = new std::list<Expr>();
	    (yyval.exprList)->push_back((yyvsp[0].expr));
	}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "compiler.y" /* yacc.c:1646  */
    {
	    (yyvsp[-2].exprList)->push_back((yyvsp[0].expr));
	    (yyval.exprList) = (yyvsp[-2].exprList);
	}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[0].expr), OP_UNARY_DOUBLEADD, false);
	    rootNode = (Node)(yyval.expr);
	}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 158 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[0].expr), OP_UNARY_DOUBLEMINUS, false);
	    rootNode = (Node)(yyval.expr);
	}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 162 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[0].expr), (yyvsp[-1].operator_), false);
	    rootNode = (Node)(yyval.expr);
	}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[0].expr), OP_UNARY_SIZEOF, false);
        rootNode = (Node)(yyval.expr);
	}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "compiler.y" /* yacc.c:1646  */
    {

	}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 176 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_UNARY_AND; }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 177 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_UNARY_STAR; }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 178 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_UNARY_POSITIVE; }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 179 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_UNARY_NEGATIVE; }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 180 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_UNARY_NOT; }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 181 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_UNARY_LOGICAL_NOT; }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 185 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 186 "compiler.y" /* yacc.c:1646  */
    {

	}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 192 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 193 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_MULTIPLY, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 197 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_DIV, (yyvsp[0].expr));
	    rootNode = (Node)(yyval.expr);
	}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 201 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_MOD, (yyvsp[0].expr));
	    rootNode = (Node)(yyval.expr);
	}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 208 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 209 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_ADD, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 213 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_MINUS, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 220 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 221 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_SHIFTLEFT, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 225 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_SHIFTRIGHT, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_ST, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 237 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_GT, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 241 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_SE, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 245 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_BE, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 252 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 253 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_EQ, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 257 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_NEQ, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 264 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 265 "compiler.y" /* yacc.c:1646  */
    {
         (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_AND, (yyvsp[0].expr));
         rootNode = (Node)(yyval.expr);
	}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 272 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 273 "compiler.y" /* yacc.c:1646  */
    {
         (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_XOR, (yyvsp[0].expr));
         rootNode = (Node)(yyval.expr);
	}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "compiler.y" /* yacc.c:1646  */
    {
         (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_OR, (yyvsp[0].expr));
         rootNode = (Node)(yyval.expr);
	}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 288 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_LOGICAL_AND, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 296 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 297 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_LOGICAL_OR, (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 304 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 305 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new ConditionalExpr_((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 312 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 313 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr) = (Expr)new AssignExpr_((yyvsp[-2].expr), (yyvsp[-1].operator_), (yyvsp[0].expr));
        rootNode = (Node)(yyval.expr);
	}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 320 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ; }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 321 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_MULTIPLY; }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 322 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_DIV; }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 323 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_MOD; }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 324 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_ADD; }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 325 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_MINUS; }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 326 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_SHIFTLEFT; }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 327 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_SHIFTRIGHT; }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 328 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_AND; }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 329 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_XOR; }
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 330 "compiler.y" /* yacc.c:1646  */
    { (yyval.operator_) = OP_ASSIGN_EQ_OR; }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 334 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 335 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[-2].expr), OP_BINARY_COMMA, (yyvsp[0].expr));
	    rootNode = (Node)(yyval.expr);
	}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 342 "compiler.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);rootNode = (Node)(yyval.expr); }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 348 "compiler.y" /* yacc.c:1646  */
    {
	    for(auto &e:*(yyvsp[-1].declList))
	    {
	        e->add2Tail((yyvsp[-2].type));
	    }
	    (yyval.declList)=(yyvsp[-1].declList);
	}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 358 "compiler.y" /* yacc.c:1646  */
    {
	}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 360 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 363 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.type) = (yyvsp[0].type);
	}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 366 "compiler.y" /* yacc.c:1646  */
    {
        ((BuiltinType)(yyvsp[-1].type))->next = (yyvsp[0].type);
        (yyval.type) = (yyvsp[-1].type);
	}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 371 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.type) = (yyvsp[0].type);
	}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 378 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.declList)=new std::list<Decl>();
        (yyval.declList)->push_back((yyvsp[0].decl));
	}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 383 "compiler.y" /* yacc.c:1646  */
    {
	    (yyvsp[-2].declList)->push_back((yyvsp[0].decl));
	    (yyval.declList)=(yyvsp[-2].declList);
	}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 391 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.decl)=(yyvsp[0].decl);
	}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 395 "compiler.y" /* yacc.c:1646  */
    {
	    if((yyvsp[-2].decl)->id==NODE_DECL_VAR)
	    {
	        ((VarDecl)(yyvsp[-2].decl))->init=(yyvsp[0].expr);
	    }
	}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 412 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_VOID, NULL); }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 413 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_CHAR, NULL); }
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 414 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_SHORT, NULL); }
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 415 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_INT, NULL); }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 416 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_LONG, NULL); }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 417 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_FLOAT, NULL); }
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 418 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_DOUBLE, NULL); }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 419 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_SIGNED, NULL); }
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 420 "compiler.y" /* yacc.c:1646  */
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED, NULL); }
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 421 "compiler.y" /* yacc.c:1646  */
    {}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 422 "compiler.y" /* yacc.c:1646  */
    {}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 423 "compiler.y" /* yacc.c:1646  */
    {}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 433 "compiler.y" /* yacc.c:1646  */
    {
	    (yyvsp[0].decl)->add2Tail((yyvsp[-1].type));
	    (yyval.decl)=(yyvsp[0].decl);
	}
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 438 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.decl)=(yyvsp[0].decl);
	}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 445 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.decl)=new VarDecl_(NULL,NULL);
        (yyval.decl)->name=std::string((yyvsp[0].sval));
        free((yyvsp[0].sval));
	}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 451 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.decl)=(yyvsp[-1].decl);
	}
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 456 "compiler.y" /* yacc.c:1646  */
    {
	    //("&&&&&%d\n",$1->id);
	    //printf("-----%d\n",((VarDecl)$$)->type->id);

	    (yyval.decl)=(yyvsp[-3].decl);
        (yyval.decl)->add2Tail(new ArrayType_(NULL,(yyvsp[-1].expr)));

	}
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 465 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.decl)=(yyvsp[-2].decl);
        (yyval.decl)->add2Tail(new ArrayType_(NULL,NULL));
	}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 470 "compiler.y" /* yacc.c:1646  */
    {
	    if((yyvsp[-3].decl)->id==NODE_DECL_VAR && (yyvsp[-3].decl)->name!="")
	    {
	        if(((VarDecl)(yyvsp[-3].decl))->type==NULL && ((VarDecl)(yyvsp[-3].decl))->init==NULL)
	        {
	            (yyval.decl)=new FunctionDecl_((yyvsp[-3].decl)->name,NULL,*(yyvsp[-1].declList),NULL);
	            delete (yyvsp[-3].decl);
	        }
	        else if(((VarDecl)(yyvsp[-3].decl))->type!=NULL)
	        {
	            list<Type> args;
                for(auto & e:*(yyvsp[-1].declList))
                {
                    printf("******%s******\n",id2name(e->id).c_str());
                    args.push_back(((ParmVarDecl)e)->type);
                    delete e;
                }
                delete (yyvsp[-1].declList);
	            (yyvsp[-3].decl)->add2Tail(new FunctionType_(NULL,args));
	            (yyval.decl)=(yyvsp[-3].decl);
	        }
	        else{
	            assert(0);
	        }
	    }
	    else{
	        list<Type> args;
            for(auto & e:*(yyvsp[-1].declList))
            {
                args.push_back(((ParmVarDecl)e)->type);
                delete e;
            }
            delete (yyvsp[-1].declList);
	        (yyvsp[-3].decl)->add2Tail(new FunctionType_(NULL,args));
	        (yyval.decl)=(yyvsp[-3].decl);
	    }

	}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 509 "compiler.y" /* yacc.c:1646  */
    {
	    if((yyvsp[-3].decl)->id==NODE_DECL_VAR && (yyvsp[-3].decl)->name!="")
        {
            if(((VarDecl)(yyvsp[-3].decl))->type==NULL && ((VarDecl)(yyvsp[-3].decl))->init==NULL)
            {
                (yyval.decl)=new FunctionDecl_((yyvsp[-3].decl)->name,NULL,*(yyvsp[-1].declList),NULL);
                delete (yyvsp[-3].decl);
            }
            else if(((VarDecl)(yyvsp[-3].decl))->type!=NULL)
            {
                list<Type> args;
                for(auto & e:*(yyvsp[-1].declList))
                {
                    args.push_back(((ParmVarDecl)e)->type);
                }
                delete (yyvsp[-1].declList);
                (yyvsp[-3].decl)->add2Tail(new FunctionType_(NULL,args));
                (yyval.decl)=(yyvsp[-3].decl);
            }
            else{
                assert(0);
            }
        }
        else{
            list<Type> args;
            for(auto & e:*(yyvsp[-1].declList))
            {
                args.push_back(((ParmVarDecl)e)->type);
            }
            delete (yyvsp[-1].declList);
            (yyvsp[-3].decl)->add2Tail(new FunctionType_(NULL,args));
            (yyval.decl)=(yyvsp[-3].decl);
        }
	}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 544 "compiler.y" /* yacc.c:1646  */
    {
	    if((yyvsp[-2].decl)->id==NODE_DECL_VAR && (yyvsp[-2].decl)->name!="")
        {
            if(((VarDecl)(yyvsp[-2].decl))->type==NULL && ((VarDecl)(yyvsp[-2].decl))->init==NULL)
            {
                (yyval.decl)=new FunctionDecl_((yyvsp[-2].decl)->name,NULL,NULL);
                delete (yyvsp[-2].decl);
            }
            else if(((VarDecl)(yyvsp[-2].decl))->type!=NULL)
            {
                (yyvsp[-2].decl)->add2Tail(new FunctionType_(NULL));
                (yyval.decl)=(yyvsp[-2].decl);
            }
            else{
                assert(0);
            }
        }
        else{
            (yyvsp[-2].decl)->add2Tail(new FunctionType_(NULL));
            (yyval.decl)=(yyvsp[-2].decl);
        }
	}
#line 2709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 569 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.type) = new PointerType_(NULL);
	}
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 572 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.type) = new PointerType_(NULL);
	}
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 575 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.type) = new PointerType_((yyvsp[0].type));
	}
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 578 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.type) = new PointerType_((yyvsp[0].type));
	}
#line 2741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 591 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.declList)=(yyvsp[0].declList);
	}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 595 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.declList)=(yyvsp[-2].declList);
	}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 602 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.declList)=new list<Decl>();
	    (yyval.declList)->push_back((yyvsp[0].decl));
	}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 607 "compiler.y" /* yacc.c:1646  */
    {
	    (yyvsp[-2].declList)->push_back((yyvsp[0].decl));
	    (yyval.declList)=(yyvsp[-2].declList);
	}
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 615 "compiler.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].decl)->id==NODE_DECL_VAR)
        {
            (yyval.decl)=new ParmVarDecl_((yyvsp[0].decl)->name,((VarDecl)(yyvsp[0].decl))->type);
            delete (yyvsp[0].decl);
            (yyval.decl)->add2Tail((yyvsp[-1].type));
        }
        else{
            printf("%s=======\n",id2name((yyvsp[0].decl)->id).c_str());
            assert(0);//error
        }
	}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 629 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.decl)=new ParmVarDecl_((yyvsp[0].type));
	}
#line 2800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 636 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.declList)=new list<Decl>();
	    auto p = new Decl_();
	    p->name=string((yyvsp[0].sval));
	    free((yyvsp[0].sval));
	    (yyval.declList)->push_back(p);
	}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 644 "compiler.y" /* yacc.c:1646  */
    {
	    auto p=new Decl_();
	    p->name=string((yyvsp[0].sval));
	    (yyvsp[-2].declList)->push_back(p);
	    (yyval.declList)=(yyvsp[-2].declList);
	}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 677 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.expr)=(yyvsp[0].expr);
	}
#line 2831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 686 "compiler.y" /* yacc.c:1646  */
    {
	}
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 689 "compiler.y" /* yacc.c:1646  */
    {
	}
#line 2845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 748 "compiler.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); rootNode = (Node)(yyval.stmt); }
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 749 "compiler.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); rootNode = (Node)(yyval.stmt); }
#line 2857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 750 "compiler.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); rootNode = (Node)(yyval.stmt); }
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 751 "compiler.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); rootNode = (Node)(yyval.stmt); }
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 752 "compiler.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); rootNode = (Node)(yyval.stmt); }
#line 2875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 753 "compiler.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); rootNode = (Node)(yyval.stmt); }
#line 2881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 757 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new LabelStmt_(std::string((yyvsp[-2].sval)), (yyvsp[0].stmt));
	    free((yyvsp[-2].sval));
	    rootNode = (Node)(yyval.stmt);
	}
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 762 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new CaseStmt_((yyvsp[-2].expr), (yyvsp[0].stmt));
        rootNode = (Node)(yyval.stmt);
	}
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 766 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new DefaultStmt_((yyvsp[0].stmt));
	    rootNode = (Node)(yyval.stmt);
	}
#line 2909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 773 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new CompoundStmt_();
	    rootNode = (Node)(yyval.stmt);
	}
#line 2918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 777 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new CompoundStmt_(*(yyvsp[-1].stmtList));
        rootNode = (Node)(yyval.stmt);
        delete (yyvsp[-1].stmtList);
	}
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 782 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new CompoundStmt_();
        std::list<std::list<struct Decl_ *> *>::iterator it;
        for(it = (yyvsp[-1].declsList)->begin(); it != (yyvsp[-1].declsList)->end(); it++){
            Stmt varDecl = (Stmt)new DeclStmt_(*(*it));
            ((CompoundStmt)(yyval.stmt))->addStatement(varDecl);
        }
        delete (yyvsp[-1].declsList);
        rootNode = (Node)(yyval.stmt);
	}
#line 2943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 792 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new CompoundStmt_();
        std::list<std::list<struct Decl_ *> *>::iterator it;
        for(it = (yyvsp[-2].declsList)->begin(); it != (yyvsp[-2].declsList)->end(); it++){
            Stmt varDecl = (Stmt)new DeclStmt_(*(*it));
            ((CompoundStmt)(yyval.stmt))->addStatement(varDecl);
        }
        delete (yyvsp[-2].declsList);
        std::list<struct Stmt_ *>::iterator it2;
        for(it2 = (yyvsp[-1].stmtList)->begin(); it2 != (yyvsp[-1].stmtList)->end(); it2++){
            ((CompoundStmt)(yyval.stmt))->addStatement((*it2));
        }
        delete (yyvsp[-1].stmtList);
        rootNode = (Node)(yyval.stmt);
	}
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 810 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.declsList) = new std::list<std::list<struct Decl_ *>*>();
	    (yyval.declsList)->push_back((yyvsp[0].declList));
	}
#line 2972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 814 "compiler.y" /* yacc.c:1646  */
    {
	    (yyvsp[-1].declsList)->push_back((yyvsp[0].declList));
	    (yyval.declsList) = (yyvsp[-1].declsList);
	}
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 821 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmtList) = new std::list<Stmt>;
	    (yyval.stmtList)->push_back((yyvsp[0].stmt));
	}
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 825 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmtList)->push_back((yyvsp[0].stmt));
	}
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 831 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new NullStmt_();
        rootNode = (Node)(yyval.stmt);
	}
#line 3007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 835 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new ExprStmt_((yyvsp[-1].expr));
	    rootNode = (Node)(yyval.stmt);
	}
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 842 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new IfStmt_((yyvsp[-2].expr), (yyvsp[0].stmt), NULL);
        rootNode = (Node)(yyval.stmt);
	}
#line 3025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 846 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new IfStmt_((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
        rootNode = (Node)(yyval.stmt);
	}
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 850 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new SwitchStmt_((yyvsp[-2].expr), (yyvsp[0].stmt));
        rootNode = (Node)(yyval.stmt);
	}
#line 3043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 857 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new WhileStmt_((yyvsp[0].stmt), (yyvsp[-2].expr));
        rootNode = (Node)(yyval.stmt);
	}
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 861 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.stmt) = (Stmt)new DoStmt_((yyvsp[-5].stmt), (yyvsp[-2].expr));
        rootNode = (Node)(yyval.stmt);
	}
#line 3061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 865 "compiler.y" /* yacc.c:1646  */
    {
        Expr expr1, expr2;
        if((yyvsp[-3].stmt)->id == NODE_STM_NULL)
            expr1 = NULL;
        else
            expr1 = ((ExprStmt)(yyvsp[-3].stmt))->expr;
        if((yyvsp[-2].stmt)->id == NODE_STM_NULL)
            expr2 = NULL;
        else
            expr2 = ((ExprStmt)(yyvsp[-2].stmt))->expr;
        (yyval.stmt) = (Stmt)new ForStmt_(expr1, expr2, NULL, (yyvsp[0].stmt));
        rootNode = (Node)(yyval.stmt);
	}
#line 3079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 878 "compiler.y" /* yacc.c:1646  */
    {
        Expr expr1, expr2;
        if((yyvsp[-4].stmt)->id == NODE_STM_NULL)
            expr1 = NULL;
        else
            expr1 = ((ExprStmt)(yyvsp[-4].stmt))->expr;
        if((yyvsp[-3].stmt)->id == NODE_STM_NULL)
            expr2 = NULL;
        else
            expr2 = ((ExprStmt)(yyvsp[-3].stmt))->expr;
        (yyval.stmt) = (Stmt)new ForStmt_(expr1, expr2, (yyvsp[-2].expr), (yyvsp[0].stmt));
        rootNode = (Node)(yyval.stmt);
	}
#line 3097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 894 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new GoToStmt_(std::string((yyvsp[-1].sval)));
        rootNode = (Node)(yyval.stmt);
        free((yyvsp[-1].sval));
	}
#line 3107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 899 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new ContinueStmt_();
        rootNode = (Node)(yyval.stmt);
	}
#line 3116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 903 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new BreakStmt_();
        rootNode = (Node)(yyval.stmt);
	}
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 907 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new ReturnStmt_(NULL);
        rootNode = (Node)(yyval.stmt);
	}
#line 3134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 911 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.stmt) = (Stmt)new ReturnStmt_((yyvsp[-1].expr));
        rootNode = (Node)(yyval.stmt);
	}
#line 3143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 918 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.decl) = (Decl)new TranslationUnitDecl_();
	    std::list<Decl>::iterator it;
        for(it = (yyvsp[0].declList)->begin(); it != (yyvsp[0].declList)->end(); it++){
            ((TranslationUnitDecl)(yyval.decl))->addDeclaration(*it);
        }
        delete (yyvsp[0].declList);
	    rootNode = (Node)(yyval.decl);
	}
#line 3157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 927 "compiler.y" /* yacc.c:1646  */
    {
	    std::list<Decl>::iterator it;
	    for(it = (yyvsp[0].declList)->begin(); it != (yyvsp[0].declList)->end(); it++){
            ((TranslationUnitDecl)(yyvsp[-1].decl))->addDeclaration(*it);
        }
        delete (yyvsp[0].declList);
	    (yyval.decl) = (TranslationUnitDecl)(yyvsp[-1].decl);
	    rootNode = (Node)(yyval.decl);
	}
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 939 "compiler.y" /* yacc.c:1646  */
    {
        (yyval.declList) = new std::list<Decl>();
        (yyval.declList)->push_back((yyvsp[0].decl));
     }
#line 3180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 943 "compiler.y" /* yacc.c:1646  */
    {
	    (yyval.declList) = new std::list<Decl>();
        std::list<Decl>::iterator it;
        for(it = (yyvsp[0].declList)->begin(); it != (yyvsp[0].declList)->end(); it++){
            (yyval.declList)->push_back(*it);
        }
        delete (yyvsp[0].declList);

	}
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 955 "compiler.y" /* yacc.c:1646  */
    {
        assert(0);
	}
#line 3202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 958 "compiler.y" /* yacc.c:1646  */
    {
	    (yyvsp[-1].decl)->add2Tail((yyvsp[-2].type));
        ((FunctionDecl)(yyvsp[-1].decl))->stmt=(yyvsp[0].stmt);
        (yyval.decl)=(yyvsp[-1].decl);
	}
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 963 "compiler.y" /* yacc.c:1646  */
    {
        assert(0);
	}
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 966 "compiler.y" /* yacc.c:1646  */
    {
        ((FunctionDecl)(yyvsp[-1].decl))->stmt=(yyvsp[0].stmt);
        (yyval.decl)=(yyvsp[-1].decl);
	}
#line 3229 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3233 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 972 "compiler.y" /* yacc.c:1906  */


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

