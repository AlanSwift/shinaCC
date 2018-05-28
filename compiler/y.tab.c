/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "compiler.y"
{
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
/* Line 193 of yacc.c.  */
#line 254 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 267 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   251,   253,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   298,   300,
     302,   306,   311,   315,   320,   325,   329,   331,   334,   337,
     341,   343,   346,   348,   352,   354,   358,   361,   364,   366,
     368,   372,   374,   377,   379,   381,   384,   388,   391,   395,
     399,   404,   407,   411,   415,   420,   422,   426,   431,   433,
     437,   443,   448,   451,   453,   455,   457,   460,   464,   467,
     469,   472,   474,   476,   480,   482,   485,   489,   494,   500,
     503,   505,   509,   511,   515,   517,   519,   521,   523,   525,
     527,   531,   536,   540,   543,   547,   551,   556,   558,   561,
     563,   566,   568,   571,   577,   585,   591,   597,   605,   612,
     620,   624,   627,   630,   633,   637,   639,   642,   644,   646,
     651,   655,   659
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     146,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    61,
     105,    62,    -1,    86,    -1,    87,    63,   105,    64,    -1,
      87,    61,    62,    -1,    87,    61,    88,    62,    -1,    87,
      65,     3,    -1,    87,     7,     3,    -1,    87,     8,    -1,
      87,     9,    -1,   103,    -1,    88,    66,   103,    -1,    87,
      -1,     8,    89,    -1,     9,    89,    -1,    90,    91,    -1,
       6,    89,    -1,     6,    61,   122,    62,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,    61,   122,    62,    91,    -1,    91,    -1,    92,
      68,    91,    -1,    92,    73,    91,    -1,    92,    74,    91,
      -1,    92,    -1,    93,    69,    92,    -1,    93,    70,    92,
      -1,    93,    -1,    94,    10,    93,    -1,    94,    11,    93,
      -1,    94,    -1,    95,    75,    94,    -1,    95,    76,    94,
      -1,    95,    12,    94,    -1,    95,    13,    94,    -1,    95,
      -1,    96,    14,    95,    -1,    96,    15,    95,    -1,    96,
      -1,    97,    67,    96,    -1,    97,    -1,    98,    77,    97,
      -1,    98,    -1,    99,    78,    98,    -1,    99,    -1,   100,
      16,    99,    -1,   100,    -1,   101,    17,   100,    -1,   101,
      -1,   101,    79,   105,    80,   102,    -1,   102,    -1,    89,
     104,   103,    -1,    81,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,   103,    -1,   105,    66,   103,
      -1,   102,    -1,   108,    82,    -1,   108,   109,    82,    -1,
     111,    -1,   111,   108,    -1,   112,    -1,   112,   108,    -1,
     113,    -1,   113,   108,    -1,   110,    -1,   109,    66,   110,
      -1,   114,    -1,   114,    81,   125,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    44,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    40,    -1,    41,
      -1,    38,    -1,    39,    -1,   127,    -1,   134,    -1,    28,
      -1,    42,    -1,    43,    -1,   116,   115,    -1,   115,    -1,
       3,    -1,    61,   114,    62,    -1,   115,    63,   106,    64,
      -1,   115,    63,    64,    -1,   115,    61,   118,    62,    -1,
     115,    61,   121,    62,    -1,   115,    61,    62,    -1,    68,
      -1,    68,   117,    -1,    68,   116,    -1,    68,   117,   116,
      -1,   113,    -1,   117,   113,    -1,   119,    -1,   119,    66,
      48,    -1,   120,    -1,   119,    66,   120,    -1,   108,   114,
      -1,   108,   123,    -1,   108,    -1,     3,    -1,   121,    66,
       3,    -1,   131,    -1,   131,   123,    -1,   116,    -1,   124,
      -1,   116,   124,    -1,    61,   123,    62,    -1,    63,    64,
      -1,    63,   106,    64,    -1,   124,    63,    64,    -1,   124,
      63,   106,    64,    -1,    61,    62,    -1,    61,   118,    62,
      -1,   124,    61,    62,    -1,   124,    61,   118,    62,    -1,
     103,    -1,    83,   126,    84,    -1,    83,   126,    66,    84,
      -1,   125,    -1,   126,    66,   125,    -1,   128,     3,    83,
     129,    84,    -1,   128,    83,   129,    84,    -1,   128,     3,
      -1,    45,    -1,    46,    -1,   130,    -1,   129,   130,    -1,
     131,   132,    82,    -1,   112,   131,    -1,   112,    -1,   113,
     131,    -1,   113,    -1,   133,    -1,   132,    66,   133,    -1,
     114,    -1,    80,   106,    -1,   114,    80,   106,    -1,    47,
      83,   135,    84,    -1,    47,     3,    83,   135,    84,    -1,
      47,     3,    -1,   136,    -1,   135,    66,   136,    -1,     3,
      -1,     3,    81,   106,    -1,   138,    -1,   139,    -1,   142,
      -1,   143,    -1,   144,    -1,   145,    -1,     3,    80,   137,
      -1,    49,   106,    80,   137,    -1,    50,    80,   137,    -1,
      83,    84,    -1,    83,   141,    84,    -1,    83,   140,    84,
      -1,    83,   140,   141,    84,    -1,   107,    -1,   140,   107,
      -1,   137,    -1,   141,   137,    -1,    82,    -1,   105,    82,
      -1,    51,    61,   105,    62,   137,    -1,    51,    61,   105,
      62,   137,    52,   137,    -1,    53,    61,   105,    62,   137,
      -1,    54,    61,   105,    62,   137,    -1,    55,   137,    54,
      61,   105,    62,    82,    -1,    56,    61,   142,   142,    62,
     137,    -1,    56,    61,   142,   142,   105,    62,   137,    -1,
      57,     3,    82,    -1,    58,    82,    -1,    59,    82,    -1,
      60,    82,    -1,    60,   105,    82,    -1,   147,    -1,   146,
     147,    -1,   148,    -1,   107,    -1,   108,   114,   140,   139,
      -1,   108,   114,   139,    -1,   114,   140,   139,    -1,   114,
     139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    88,    92,    96,   104,   105,   109,   113,
     116,   120,   124,   128,   136,   137,   144,   145,   149,   153,
     157,   161,   167,   168,   169,   170,   171,   172,   176,   177,
     183,   184,   188,   192,   199,   200,   204,   211,   212,   216,
     223,   224,   228,   232,   236,   243,   244,   248,   255,   256,
     263,   264,   271,   272,   279,   280,   287,   288,   295,   296,
     303,   304,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   325,   326,   333,   337,   338,   345,   347,
     350,   353,   357,   358,   364,   369,   377,   381,   385,   386,
     387,   388,   389,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   408,   409,   413,   415,   422,
     428,   433,   440,   447,   451,   455,   462,   463,   464,   465,
     469,   470,   475,   479,   486,   491,   499,   500,   501,   508,
     516,   526,   527,   531,   532,   533,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   549,   550,   551,   555,   556,
     560,   561,   562,   566,   567,   571,   572,   576,   580,   581,
     582,   583,   587,   588,   592,   593,   594,   598,   599,   600,
     604,   605,   609,   610,   614,   615,   616,   617,   618,   619,
     623,   628,   632,   639,   643,   648,   658,   676,   680,   687,
     691,   697,   701,   708,   712,   716,   723,   727,   731,   744,
     760,   765,   769,   773,   777,   784,   793,   805,   809,   821,
     824,   827,   830
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "translation_unit", "external_declaration", "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -202
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

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 83 "compiler.y"
    {
	    (yyval.expr) = (Expr)new DeclRefExpr_(std::string((yyvsp[(1) - (1)].sval)));
	    free((yyvsp[(1) - (1)].sval));
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 3:
#line 88 "compiler.y"
    {
        (yyval.expr) = (Expr)(yyvsp[(1) - (1)].expr);
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 4:
#line 92 "compiler.y"
    {
        (yyval.expr) = (Expr)(yyvsp[(1) - (1)].expr);
        rootNode = (Node)(yyval.expr);
    }
    break;

  case 5:
#line 96 "compiler.y"
    {
	    ParenExpr p = new ParenExpr_((yyvsp[(2) - (3)].expr));
	    (yyval.expr) = (Expr)p;
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 6:
#line 104 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); rootNode = (Node)(yyval.expr); }
    break;

  case 7:
#line 105 "compiler.y"
    {
        (yyval.expr) = (Expr)new ArraySubscriptExpr_((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 8:
#line 109 "compiler.y"
    {
        (yyval.expr) = (Expr)new CallExpr_((yyvsp[(1) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 9:
#line 113 "compiler.y"
    {
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 10:
#line 116 "compiler.y"
    {
        (yyval.expr) = (Expr)new MemberExpr_((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].sval), false);
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 11:
#line 120 "compiler.y"
    {
        (yyval.expr) = (Expr)new MemberExpr_((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].sval), true);
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 12:
#line 124 "compiler.y"
    {
        (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[(1) - (2)].expr), OP_UNARY_DOUBLEADD, true);
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 13:
#line 128 "compiler.y"
    {
        (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[(1) - (2)].expr), OP_UNARY_DOUBLEMINUS, true);
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 14:
#line 136 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 15:
#line 137 "compiler.y"
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_COMMA, (yyvsp[(3) - (3)].expr));
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 16:
#line 144 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 17:
#line 145 "compiler.y"
    {
	    (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[(2) - (2)].expr), OP_UNARY_DOUBLEADD, false);
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 18:
#line 149 "compiler.y"
    {
	    (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[(2) - (2)].expr), OP_UNARY_DOUBLEMINUS, false);
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 19:
#line 153 "compiler.y"
    {
	    (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].operator_), false);
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 20:
#line 157 "compiler.y"
    {
        (yyval.expr) = (Expr)new UnaryOpExpr_((yyvsp[(2) - (2)].expr), OP_UNARY_SIZEOF, false);
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 21:
#line 161 "compiler.y"
    {

	}
    break;

  case 22:
#line 167 "compiler.y"
    { (yyval.operator_) = OP_UNARY_AND; }
    break;

  case 23:
#line 168 "compiler.y"
    { (yyval.operator_) = OP_UNARY_STAR; }
    break;

  case 24:
#line 169 "compiler.y"
    { (yyval.operator_) = OP_UNARY_POSITIVE; }
    break;

  case 25:
#line 170 "compiler.y"
    { (yyval.operator_) = OP_UNARY_NEGATIVE; }
    break;

  case 26:
#line 171 "compiler.y"
    { (yyval.operator_) = OP_UNARY_NOT; }
    break;

  case 27:
#line 172 "compiler.y"
    { (yyval.operator_) = OP_UNARY_LOGICAL_NOT; }
    break;

  case 28:
#line 176 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 29:
#line 177 "compiler.y"
    {

	}
    break;

  case 30:
#line 183 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 31:
#line 184 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_MULTIPLY, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 32:
#line 188 "compiler.y"
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_DIV, (yyvsp[(3) - (3)].expr));
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 33:
#line 192 "compiler.y"
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_MOD, (yyvsp[(3) - (3)].expr));
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 34:
#line 199 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 35:
#line 200 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_ADD, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 36:
#line 204 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_MINUS, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 37:
#line 211 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 38:
#line 212 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_SHIFTLEFT, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 39:
#line 216 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_SHIFTRIGHT, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 40:
#line 223 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 41:
#line 224 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_ST, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 42:
#line 228 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_GT, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 43:
#line 232 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_SE, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 44:
#line 236 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_BE, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 45:
#line 243 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 46:
#line 244 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_EQ, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 47:
#line 248 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_NEQ, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 48:
#line 255 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 49:
#line 256 "compiler.y"
    {
         (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_AND, (yyvsp[(3) - (3)].expr));
         rootNode = (Node)(yyval.expr);
	}
    break;

  case 50:
#line 263 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 51:
#line 264 "compiler.y"
    {
         (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_XOR, (yyvsp[(3) - (3)].expr));
         rootNode = (Node)(yyval.expr);
	}
    break;

  case 52:
#line 271 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 53:
#line 272 "compiler.y"
    {
         (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_OR, (yyvsp[(3) - (3)].expr));
         rootNode = (Node)(yyval.expr);
	}
    break;

  case 54:
#line 279 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 55:
#line 280 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_LOGICAL_AND, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 56:
#line 287 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 57:
#line 288 "compiler.y"
    {
        (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_LOGICAL_OR, (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 58:
#line 295 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 59:
#line 296 "compiler.y"
    {
        (yyval.expr) = (Expr)new ConditionalExpr_((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 60:
#line 303 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 61:
#line 304 "compiler.y"
    {
        (yyval.expr) = (Expr)new AssignExpr_((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].operator_), (yyvsp[(3) - (3)].expr));
        rootNode = (Node)(yyval.expr);
	}
    break;

  case 62:
#line 311 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ; }
    break;

  case 63:
#line 312 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_MULTIPLY; }
    break;

  case 64:
#line 313 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_DIV; }
    break;

  case 65:
#line 314 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_MOD; }
    break;

  case 66:
#line 315 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_ADD; }
    break;

  case 67:
#line 316 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_MINUS; }
    break;

  case 68:
#line 317 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_SHIFTLEFT; }
    break;

  case 69:
#line 318 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_SHIFTRIGHT; }
    break;

  case 70:
#line 319 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_AND; }
    break;

  case 71:
#line 320 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_XOR; }
    break;

  case 72:
#line 321 "compiler.y"
    { (yyval.operator_) = OP_ASSIGN_EQ_OR; }
    break;

  case 73:
#line 325 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 74:
#line 326 "compiler.y"
    {
	    (yyval.expr) = (Expr)new BinaryOpExpr_((yyvsp[(1) - (3)].expr), OP_BINARY_COMMA, (yyvsp[(3) - (3)].expr));
	    rootNode = (Node)(yyval.expr);
	}
    break;

  case 75:
#line 333 "compiler.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);rootNode = (Node)(yyval.expr); }
    break;

  case 77:
#line 339 "compiler.y"
    {
	    (yyval.declList)=(yyvsp[(2) - (3)].declList);
	}
    break;

  case 78:
#line 345 "compiler.y"
    {
	}
    break;

  case 79:
#line 347 "compiler.y"
    {
        (yyval.type) = (yyvsp[(2) - (2)].type);
    }
    break;

  case 80:
#line 350 "compiler.y"
    {
        (yyval.type) = (yyvsp[(1) - (1)].type);
	}
    break;

  case 81:
#line 353 "compiler.y"
    {
        ((BuiltinType)(yyvsp[(1) - (2)].type))->next = (yyvsp[(2) - (2)].type);
        (yyval.type) = (yyvsp[(1) - (2)].type);
	}
    break;

  case 83:
#line 358 "compiler.y"
    {
	    (yyval.type) = (yyvsp[(2) - (2)].type);
	}
    break;

  case 84:
#line 365 "compiler.y"
    {
        (yyval.declList)=new std::list<Decl>();
        (yyval.declList)->push_back((yyvsp[(1) - (1)].decl));
	}
    break;

  case 85:
#line 370 "compiler.y"
    {
	    (yyvsp[(1) - (3)].declList)->push_back((yyvsp[(3) - (3)].decl));
	    (yyval.declList)=(yyvsp[(1) - (3)].declList);
	}
    break;

  case 86:
#line 378 "compiler.y"
    {
	    (yyval.decl)=(yyvsp[(1) - (1)].decl);
	}
    break;

  case 93:
#line 393 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_VOID, NULL); }
    break;

  case 94:
#line 394 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_CHAR, NULL); }
    break;

  case 95:
#line 395 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_SHORT, NULL); }
    break;

  case 96:
#line 396 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_INT, NULL); }
    break;

  case 97:
#line 397 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_LONG, NULL); }
    break;

  case 98:
#line 398 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_FLOAT, NULL); }
    break;

  case 99:
#line 399 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_DOUBLE, NULL); }
    break;

  case 100:
#line 400 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_SIGNED, NULL); }
    break;

  case 101:
#line 401 "compiler.y"
    { (yyval.type) = (Type)new BuiltinType_(CONST_TYPE_BUILTIN_UNSIGNED, NULL); }
    break;

  case 102:
#line 402 "compiler.y"
    {}
    break;

  case 103:
#line 403 "compiler.y"
    {}
    break;

  case 104:
#line 404 "compiler.y"
    {}
    break;

  case 108:
#line 416 "compiler.y"
    {
	    (yyval.decl)=(yyvsp[(1) - (1)].decl);
	}
    break;

  case 109:
#line 423 "compiler.y"
    {
        (yyval.decl)=new Decl_();
        (yyval.decl)->name=std::string((yyvsp[(1) - (1)].sval));
        free((yyvsp[(1) - (1)].sval));
	}
    break;

  case 110:
#line 429 "compiler.y"
    {
        (yyval.decl)=(yyvsp[(2) - (3)].decl);
	}
    break;

  case 111:
#line 434 "compiler.y"
    {
	    (yyval.decl)=new VarDecl_();
	    (yyval.decl)->name=(yyvsp[(1) - (4)].decl)->name;
	    delete (yyvsp[(1) - (4)].decl);
	    ((VarDecl)(yyval.decl))->type=new ArrayType_(NULL,(yyvsp[(3) - (4)].expr));
	}
    break;

  case 112:
#line 441 "compiler.y"
    {
	    (yyval.decl)=new VarDecl_();
	    (yyval.decl)->name=(yyvsp[(1) - (3)].decl)->name;
	    delete (yyvsp[(1) - (3)].decl);
	    ((VarDecl)(yyval.decl))->type=new ArrayType_(NULL,NULL);
	}
    break;

  case 113:
#line 448 "compiler.y"
    {
	    (yyval.decl)=new FunctionDecl_((yyvsp[(1) - (4)].decl)->name,NULL,*(yyvsp[(3) - (4)].declList),NULL);
	}
    break;

  case 114:
#line 452 "compiler.y"
    {
	    (yyval.decl)=new FunctionDecl_((yyvsp[(1) - (4)].decl)->name,NULL,*(yyvsp[(3) - (4)].declList),NULL);
	}
    break;

  case 115:
#line 456 "compiler.y"
    {
	    (yyval.decl)=new FunctionDecl_((yyvsp[(1) - (3)].decl)->name,NULL,NULL);
	}
    break;

  case 122:
#line 476 "compiler.y"
    {
	    (yyval.declList)=(yyvsp[(1) - (1)].declList);
	}
    break;

  case 123:
#line 480 "compiler.y"
    {
	    (yyval.declList)=(yyvsp[(1) - (3)].declList);
	}
    break;

  case 124:
#line 487 "compiler.y"
    {
	    (yyval.declList)=new list<Decl>();
	    (yyval.declList)->push_back((yyvsp[(1) - (1)].decl));
	}
    break;

  case 125:
#line 492 "compiler.y"
    {
	    (yyvsp[(1) - (3)].declList)->push_back((yyvsp[(3) - (3)].decl));
	    (yyval.declList)=(yyvsp[(1) - (3)].declList);
	}
    break;

  case 128:
#line 502 "compiler.y"
    {
	    (yyval.decl)=new ParmVarDecl_((yyvsp[(1) - (1)].type));
	}
    break;

  case 129:
#line 509 "compiler.y"
    {
	    (yyval.declList)=new list<Decl>();
	    auto p = new Decl_();
	    p->name=string((yyvsp[(1) - (1)].sval));
	    free((yyvsp[(1) - (1)].sval));
	    (yyval.declList)->push_back(p);
	}
    break;

  case 130:
#line 517 "compiler.y"
    {
	    auto p=new Decl_();
	    p->name=string((yyvsp[(3) - (3)].sval));
	    (yyvsp[(1) - (3)].declList)->push_back(p);
	    (yyval.declList)=(yyvsp[(1) - (3)].declList);
	}
    break;

  case 174:
#line 614 "compiler.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); rootNode = (Node)(yyval.stmt); }
    break;

  case 175:
#line 615 "compiler.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); rootNode = (Node)(yyval.stmt); }
    break;

  case 176:
#line 616 "compiler.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); rootNode = (Node)(yyval.stmt); }
    break;

  case 177:
#line 617 "compiler.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); rootNode = (Node)(yyval.stmt); }
    break;

  case 178:
#line 618 "compiler.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); rootNode = (Node)(yyval.stmt); }
    break;

  case 179:
#line 619 "compiler.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); rootNode = (Node)(yyval.stmt); }
    break;

  case 180:
#line 623 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new LabelStmt_(std::string((yyvsp[(1) - (3)].sval)), (yyvsp[(3) - (3)].stmt));
	    free((yyvsp[(1) - (3)].sval));
	    rootNode = (Node)(yyval.stmt);
	}
    break;

  case 181:
#line 628 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new CaseStmt_((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].stmt));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 182:
#line 632 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new DefaultStmt_((yyvsp[(3) - (3)].stmt));
	    rootNode = (Node)(yyval.stmt);
	}
    break;

  case 183:
#line 639 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new CompoundStmt_();
	    rootNode = (Node)(yyval.stmt);
	}
    break;

  case 184:
#line 643 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new CompoundStmt_(*(yyvsp[(2) - (3)].stmtList));
        rootNode = (Node)(yyval.stmt);
        delete (yyvsp[(2) - (3)].stmtList);
	}
    break;

  case 185:
#line 648 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new CompoundStmt_();
        std::list<std::list<struct Decl_ *> *>::iterator it;
        for(it = (yyvsp[(2) - (3)].declsList)->begin(); it != (yyvsp[(2) - (3)].declsList)->end(); it++){
            Stmt varDecl = (Stmt)new DeclStmt_(*(*it));
            ((CompoundStmt)(yyval.stmt))->addStatement(varDecl);
        }
        delete (yyvsp[(2) - (3)].declsList);
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 186:
#line 658 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new CompoundStmt_();
        std::list<std::list<struct Decl_ *> *>::iterator it;
        for(it = (yyvsp[(2) - (4)].declsList)->begin(); it != (yyvsp[(2) - (4)].declsList)->end(); it++){
            Stmt varDecl = (Stmt)new DeclStmt_(*(*it));
            ((CompoundStmt)(yyval.stmt))->addStatement(varDecl);
        }
        delete (yyvsp[(2) - (4)].declsList);
        std::list<struct Stmt_ *>::iterator it2;
        for(it2 = (yyvsp[(3) - (4)].stmtList)->begin(); it2 != (yyvsp[(3) - (4)].stmtList)->end(); it2++){
            ((CompoundStmt)(yyval.stmt))->addStatement((*it2));
        }
        delete (yyvsp[(3) - (4)].stmtList);
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 187:
#line 676 "compiler.y"
    {
	    (yyval.declsList) = new std::list<std::list<struct Decl_ *>*>();
	    (yyval.declsList)->push_back((yyvsp[(1) - (1)].declList));
	}
    break;

  case 188:
#line 680 "compiler.y"
    {
	    (yyvsp[(1) - (2)].declsList)->push_back((yyvsp[(2) - (2)].declList));
	    (yyval.declsList) = (yyvsp[(1) - (2)].declsList);
	}
    break;

  case 189:
#line 687 "compiler.y"
    {
	    (yyval.stmtList) = new std::list<Stmt>;
	    (yyval.stmtList)->push_back((yyvsp[(1) - (1)].stmt));
	}
    break;

  case 190:
#line 691 "compiler.y"
    {
	    (yyval.stmtList)->push_back((yyvsp[(2) - (2)].stmt));
	}
    break;

  case 191:
#line 697 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new NullStmt_();
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 192:
#line 701 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new ExprStmt_((yyvsp[(1) - (2)].expr));
	    rootNode = (Node)(yyval.stmt);
	}
    break;

  case 193:
#line 708 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new IfStmt_((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL);
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 194:
#line 712 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new IfStmt_((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 195:
#line 716 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new SwitchStmt_((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 196:
#line 723 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new WhileStmt_((yyvsp[(5) - (5)].stmt), (yyvsp[(3) - (5)].expr));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 197:
#line 727 "compiler.y"
    {
	    (yyval.stmt) = (Stmt)new DoStmt_((yyvsp[(2) - (7)].stmt), (yyvsp[(5) - (7)].expr));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 198:
#line 731 "compiler.y"
    {
        Expr expr1, expr2;
        if((yyvsp[(3) - (6)].stmt)->id == NODE_STM_NULL)
            expr1 = NULL;
        else
            expr1 = ((ExprStmt)(yyvsp[(3) - (6)].stmt))->expr;
        if((yyvsp[(4) - (6)].stmt)->id == NODE_STM_NULL)
            expr2 = NULL;
        else
            expr2 = ((ExprStmt)(yyvsp[(4) - (6)].stmt))->expr;
        (yyval.stmt) = (Stmt)new ForStmt_(expr1, expr2, NULL, (yyvsp[(6) - (6)].stmt));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 199:
#line 744 "compiler.y"
    {
        Expr expr1, expr2;
        if((yyvsp[(3) - (7)].stmt)->id == NODE_STM_NULL)
            expr1 = NULL;
        else
            expr1 = ((ExprStmt)(yyvsp[(3) - (7)].stmt))->expr;
        if((yyvsp[(4) - (7)].stmt)->id == NODE_STM_NULL)
            expr2 = NULL;
        else
            expr2 = ((ExprStmt)(yyvsp[(4) - (7)].stmt))->expr;
        (yyval.stmt) = (Stmt)new ForStmt_(expr1, expr2, (yyvsp[(5) - (7)].expr), (yyvsp[(7) - (7)].stmt));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 200:
#line 760 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new GoToStmt_(std::string((yyvsp[(2) - (3)].sval)));
        rootNode = (Node)(yyval.stmt);
        free((yyvsp[(2) - (3)].sval));
	}
    break;

  case 201:
#line 765 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new ContinueStmt_();
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 202:
#line 769 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new BreakStmt_();
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 203:
#line 773 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new ReturnStmt_(NULL);
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 204:
#line 777 "compiler.y"
    {
        (yyval.stmt) = (Stmt)new ReturnStmt_((yyvsp[(2) - (3)].expr));
        rootNode = (Node)(yyval.stmt);
	}
    break;

  case 205:
#line 784 "compiler.y"
    {
	    (yyval.decl) = (Decl)new TranslationUnitDecl_();
	    std::list<Decl>::iterator it;
        for(it = (yyvsp[(1) - (1)].declList)->begin(); it != (yyvsp[(1) - (1)].declList)->end(); it++){
            ((TranslationUnitDecl)(yyval.decl))->addDeclaration(*it);
        }
        delete (yyvsp[(1) - (1)].declList);
	    rootNode = (Node)(yyval.decl);
	}
    break;

  case 206:
#line 793 "compiler.y"
    {
	    std::list<Decl>::iterator it;
	    for(it = (yyvsp[(2) - (2)].declList)->begin(); it != (yyvsp[(2) - (2)].declList)->end(); it++){
            ((TranslationUnitDecl)(yyvsp[(1) - (2)].decl))->addDeclaration(*it);
        }
        delete (yyvsp[(2) - (2)].declList);
	    (yyval.decl) = (TranslationUnitDecl)(yyvsp[(1) - (2)].decl);
	    rootNode = (Node)(yyval.decl);
	}
    break;

  case 207:
#line 805 "compiler.y"
    {
        (yyval.declList) = new std::list<Decl>();
        (yyval.declList)->push_back((yyvsp[(1) - (1)].decl));
     }
    break;

  case 208:
#line 809 "compiler.y"
    {
	    (yyval.declList) = new std::list<Decl>();
        std::list<Decl>::iterator it;
        for(it = (yyvsp[(1) - (1)].declList)->begin(); it != (yyvsp[(1) - (1)].declList)->end(); it++){
            (yyval.declList)->push_back(*it);
        }
        delete (yyvsp[(1) - (1)].declList);

	}
    break;

  case 209:
#line 821 "compiler.y"
    {
        //$$ = (Decl)new FunctionDecl_($1, $4);
	}
    break;

  case 210:
#line 824 "compiler.y"
    {

	}
    break;

  case 211:
#line 827 "compiler.y"
    {

	}
    break;

  case 212:
#line 830 "compiler.y"
    {

	}
    break;


/* Line 1267 of yacc.c.  */
#line 3083 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 835 "compiler.y"


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


