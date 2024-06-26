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
     INT_CONST = 258,
     ADD = 259,
     SUB = 260,
     MUL = 261,
     DIV = 262,
     MOD = 263,
     NOT = 264,
     LT = 265,
     GT = 266,
     LE = 267,
     GE = 268,
     EQ = 269,
     NE = 270,
     ASSIGN = 271,
     SEMI = 272,
     COLON = 273,
     COMMA = 274,
     LC = 275,
     RC = 276,
     LB = 277,
     RB = 278,
     LP = 279,
     RP = 280,
     CONST = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     BREAK = 285,
     RETURN = 286,
     CONTINUE = 287,
     AND = 288,
     OR = 289,
     INT = 290,
     ID = 291,
     VOID = 292
   };
#endif
/* Tokens.  */
#define INT_CONST 258
#define ADD 259
#define SUB 260
#define MUL 261
#define DIV 262
#define MOD 263
#define NOT 264
#define LT 265
#define GT 266
#define LE 267
#define GE 268
#define EQ 269
#define NE 270
#define ASSIGN 271
#define SEMI 272
#define COLON 273
#define COMMA 274
#define LC 275
#define RC 276
#define LB 277
#define RB 278
#define LP 279
#define RP 280
#define CONST 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define BREAK 285
#define RETURN 286
#define CONTINUE 287
#define AND 288
#define OR 289
#define INT 290
#define ID 291
#define VOID 292




/* Copy the first part of user declarations.  */
#line 1 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"

#include <stdio.h>
#include <ast/ast.h>
#include <string>
#include <iostream>
using namespace std;
void yyerror(const char *s);
extern int yylex(void);
extern Node root;
extern TABLE_LISTS tables;
map<string,Type> temp_type_map;
vector<int> array_length;
bool is_func = false;
string func_name;
#define YYSTYPE Node*


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 197 "/Users/lyucheng_wu/Desktop/lab3/lab1/build/sysy.tab.cc"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    20,    24,
      25,    30,    33,    34,    39,    41,    44,    49,    55,    60,
      66,    68,    72,    75,    81,    83,    85,    88,    92,    94,
      97,    99,   101,   106,   109,   111,   117,   125,   131,   134,
     137,   140,   144,   146,   148,   151,   152,   157,   161,   163,
     165,   167,   169,   173,   178,   181,   183,   185,   187,   189,
     193,   195,   199,   203,   207,   209,   213,   217,   219,   223,
     227,   231,   235,   237,   241,   245,   247,   251,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    46,    -1,    39,    40,    -1,
      39,    46,    -1,    41,    -1,    35,    43,    42,    17,    -1,
      42,    19,    43,    -1,    -1,    36,    44,    16,    45,    -1,
      36,    44,    -1,    -1,    22,     3,    23,    44,    -1,    56,
      -1,    47,    52,    -1,    35,    36,    24,    25,    -1,    35,
      36,    24,    48,    25,    -1,    37,    36,    24,    25,    -1,
      37,    36,    24,    48,    25,    -1,    49,    -1,    49,    19,
      48,    -1,    35,    36,    -1,    35,    36,    22,    23,    44,
      -1,    20,    -1,    21,    -1,    50,    51,    -1,    50,    53,
      51,    -1,    54,    -1,    53,    54,    -1,    40,    -1,    55,
      -1,    57,    16,    56,    17,    -1,    56,    17,    -1,    52,
      -1,    27,    24,    56,    25,    55,    -1,    27,    24,    56,
      25,    55,    28,    55,    -1,    29,    24,    56,    25,    55,
      -1,    30,    17,    -1,    32,    17,    -1,    31,    17,    -1,
      31,    56,    17,    -1,    69,    -1,    36,    -1,    36,    58,
      -1,    -1,    58,    22,    56,    23,    -1,    24,    56,    25,
      -1,    57,    -1,    60,    -1,     3,    -1,    59,    -1,    36,
      24,    25,    -1,    36,    24,    63,    25,    -1,    62,    61,
      -1,     4,    -1,     5,    -1,     9,    -1,    56,    -1,    56,
      19,    63,    -1,    61,    -1,    64,     6,    61,    -1,    64,
       7,    61,    -1,    64,     8,    61,    -1,    64,    -1,    65,
       4,    64,    -1,    65,     5,    64,    -1,    65,    -1,    66,
      10,    65,    -1,    66,    11,    65,    -1,    66,    12,    65,
      -1,    66,    13,    65,    -1,    66,    -1,    67,    14,    66,
      -1,    67,    15,    66,    -1,    67,    -1,    67,    33,    67,
      -1,    68,    -1,    69,    34,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    58,    59,    61,    63,    66,    67,
      69,   105,   140,   141,   143,   150,   153,   166,   197,   210,
     243,   244,   247,   250,   275,   287,   292,   293,   294,   295,
     298,   298,   300,   307,   308,   309,   310,   311,   312,   313,
     314,   319,   325,   327,   334,   359,   359,   365,   365,   365,
     370,   372,   373,   380,   415,   421,   421,   421,   423,   424,
     427,   428,   435,   439,   444,   445,   446,   448,   449,   450,
     451,   452,   454,   455,   456,   458,   459,   460,   461
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONST", "ADD", "SUB", "MUL", "DIV",
  "MOD", "NOT", "LT", "GT", "LE", "GE", "EQ", "NE", "ASSIGN", "\";\"",
  "\":\"", "\",\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\"(\"", "\")\"",
  "CONST", "IF", "ELSE", "WHILE", "BREAK", "RETURN", "CONTINUE", "AND",
  "OR", "INT", "ID", "VOID", "$accept", "CompUnit", "Decl", "VarDecl",
  "VerDefGroup", "VarDef", "ConstGroup", "InitVal", "FuncDef",
  "FuncDefPre", "FuncFParams", "FuncFParam", "LC_B", "RC_E", "Block",
  "BlockItems", "BlockItem", "Stmt", "Exp", "LVal", "Exps", "PrimaryExp",
  "Number", "UnaryExp", "UnaryOp", "FuncRParams", "MulExp", "AddExp",
  "RelExp", "EqExp", "LAndExp", "LOrExp", 0
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    40,    41,    42,    42,
      43,    43,    44,    44,    45,    46,    47,    47,    47,    47,
      48,    48,    49,    49,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    58,    58,    59,    59,    59,
      60,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     4,     3,     0,
       4,     2,     0,     4,     1,     2,     4,     5,     4,     5,
       1,     3,     2,     5,     1,     1,     2,     3,     1,     2,
       1,     1,     4,     2,     1,     5,     7,     5,     2,     2,
       2,     3,     1,     1,     2,     0,     4,     3,     1,     1,
       1,     1,     3,     4,     2,     1,     1,     1,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     6,     3,     0,    12,     9,
       0,     1,     4,     5,    24,     0,    15,     0,     0,    11,
       0,     0,    50,    55,    56,    57,    25,     0,     0,     0,
       0,     0,     0,     0,    43,    30,    26,    34,     0,    28,
      31,     0,    48,    51,    49,    60,     0,    64,    67,    72,
      75,    77,    42,     0,    16,     0,     0,    20,     0,     7,
       0,    18,     0,     0,    48,     0,     0,    38,    40,     0,
      39,    12,     0,    44,    27,    29,    33,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    22,    17,     0,    10,    14,     8,    19,
      47,     0,     0,    41,    52,    58,     0,     0,     0,    61,
      62,    63,    65,    66,    68,    69,    70,    71,    73,    74,
      76,    78,    13,     0,    21,     0,     0,     0,    53,     0,
      32,    12,    35,    37,    59,    46,    23,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    35,     5,    20,     9,    19,    96,     6,     7,
      56,    57,    15,    36,    37,    38,    39,    40,    41,    64,
      73,    43,    44,    45,    46,   106,    47,    48,    49,    50,
      51,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -117
static const yytype_int8 yypact[] =
{
       1,   -25,   -12,     6,  -117,  -117,  -117,   -16,    28,  -117,
      30,  -117,  -117,  -117,  -117,    53,  -117,    34,   -13,    15,
      36,   -10,  -117,  -117,  -117,  -117,  -117,    63,    41,    70,
      43,   100,    83,    77,    37,  -117,  -117,  -117,    53,  -117,
    -117,    97,    99,  -117,  -117,  -117,    63,    27,    40,     7,
      -7,  -117,    82,    95,  -117,    84,    94,   102,    63,  -117,
      77,  -117,    98,   101,  -117,    63,    63,  -117,  -117,   108,
    -117,   107,   103,   109,  -117,  -117,  -117,    63,  -117,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,   107,   110,  -117,   105,  -117,  -117,  -117,  -117,
    -117,   112,   113,  -117,  -117,   111,   116,    63,   117,  -117,
    -117,  -117,    27,    27,    40,    40,    40,    40,     7,     7,
      49,  -117,  -117,   119,  -117,    66,    66,    63,  -117,   120,
    -117,   107,   118,  -117,  -117,  -117,  -117,    66,  -117
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,    13,  -117,  -117,    73,   -89,  -117,   132,  -117,
     -19,  -117,  -117,   106,   138,  -117,   114,  -116,   -26,   -15,
    -117,  -117,  -117,   -32,  -117,    20,    -4,   -57,     3,    58,
      59,  -117
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -46
static const yytype_int16 yytable[] =
{
      42,    63,    62,   122,    14,    69,    11,    88,    89,   132,
     133,     8,    54,     4,    78,    61,    12,    84,    85,    86,
      87,   138,    55,    42,    10,    55,    90,   114,   115,   116,
     117,    58,    97,    79,    80,    81,     1,    53,     2,   101,
     102,     1,   136,     2,    82,    83,   105,   109,   110,   111,
      17,   108,    18,    59,    21,    60,    22,    23,    24,   -45,
      67,    72,    25,    88,    89,    65,    22,    23,    24,    22,
      23,    24,    25,    14,    26,    25,   124,    27,   112,   113,
      28,   129,    29,    30,    31,    32,    14,    27,    33,    34,
      27,   118,   119,    28,    66,    29,    30,    31,    32,    34,
      70,   105,    34,    22,    23,    24,    22,    23,    24,    25,
      42,    42,    25,    71,    76,    77,    91,    68,    92,    94,
      93,    95,    42,    99,    27,   103,   100,    27,   104,    17,
     127,   107,   123,    98,   130,    13,    34,   125,   126,    34,
      55,   128,   131,   135,    74,    16,   137,   134,   120,     0,
     121,     0,    75
};

static const yytype_int16 yycheck[] =
{
      15,    27,    21,    92,    20,    31,     0,    14,    15,   125,
     126,    36,    25,     0,    46,    25,     3,    10,    11,    12,
      13,   137,    35,    38,    36,    35,    33,    84,    85,    86,
      87,    16,    58,     6,     7,     8,    35,     3,    37,    65,
      66,    35,   131,    37,     4,     5,    72,    79,    80,    81,
      22,    77,    24,    17,    24,    19,     3,     4,     5,    22,
      17,    24,     9,    14,    15,    24,     3,     4,     5,     3,
       4,     5,     9,    20,    21,     9,    95,    24,    82,    83,
      27,   107,    29,    30,    31,    32,    20,    24,    35,    36,
      24,    88,    89,    27,    24,    29,    30,    31,    32,    36,
      17,   127,    36,     3,     4,     5,     3,     4,     5,     9,
     125,   126,     9,    36,    17,    16,    34,    17,    23,    25,
      36,    19,   137,    25,    24,    17,    25,    24,    25,    22,
      19,    22,    22,    60,    17,     3,    36,    25,    25,    36,
      35,    25,    23,    23,    38,     7,    28,   127,    90,    -1,
      91,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    37,    39,    40,    41,    46,    47,    36,    43,
      36,     0,    40,    46,    20,    50,    52,    22,    24,    44,
      42,    24,     3,     4,     5,     9,    21,    24,    27,    29,
      30,    31,    32,    35,    36,    40,    51,    52,    53,    54,
      55,    56,    57,    59,    60,    61,    62,    64,    65,    66,
      67,    68,    69,     3,    25,    35,    48,    49,    16,    17,
      19,    25,    48,    56,    57,    24,    24,    17,    17,    56,
      17,    36,    24,    58,    51,    54,    17,    16,    61,     6,
       7,     8,     4,     5,    10,    11,    12,    13,    14,    15,
      33,    34,    23,    36,    25,    19,    45,    56,    43,    25,
      25,    56,    56,    17,    25,    56,    63,    22,    56,    61,
      61,    61,    64,    64,    65,    65,    65,    65,    66,    66,
      67,    68,    44,    22,    48,    25,    25,    19,    25,    56,
      17,    23,    55,    55,    63,    23,    44,    28,    55
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
#line 56 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {root.add(*(yyvsp[(1) - (1)])); (yyvsp[(1) - (1)])->print(1);delete (yyvsp[(1) - (1)]) ;;}
    break;

  case 3:
#line 57 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {root.add(*(yyvsp[(1) - (1)])); (yyvsp[(1) - (1)])->print(1);delete (yyvsp[(1) - (1)]) ;;}
    break;

  case 4:
#line 58 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {  root.add(*(yyvsp[(2) - (2)]));(yyvsp[(2) - (2)])->print(1); delete (yyvsp[(2) - (2)]);;}
    break;

  case 5:
#line 59 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { root.add(*(yyvsp[(2) - (2)]));(yyvsp[(2) - (2)])->print(1); delete (yyvsp[(2) - (2)]);;}
    break;

  case 6:
#line 61 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:
#line 63 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(3) - (4)]); (yyval)->add(*(yyvsp[(2) - (4)])); (yyval)->rename("INT VarDecl");
                ;}
    break;

  case 8:
#line 66 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyval)->add(*(yyvsp[(3) - (3)]));delete (yyvsp[(3) - (3)]);;}
    break;

  case 9:
#line 67 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("VerDefGroup"); ;}
    break;

  case 10:
#line 69 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("VerDef");(yyval)->add(*(yyvsp[(1) - (4)]));(yyval)->add(*(yyvsp[(3) - (4)]));
                if(tables.get_var_in_scope((yyvsp[(1) - (4)])->name())==NONE){
                        Type ty;
                        vector<int> array_length;
                        array_length.clear();
                        cout << "VarDef_param: " << (yyvsp[(1) - (4)])->name()<< " " << (yyvsp[(2) - (4)])->children_size() << endl;
                        for(int i=0;i<(yyvsp[(2) - (4)])->children_size();i++)
                                array_length.push_back(atoi((yyvsp[(2) - (4)])->get(i)->name().c_str()));
                                (yyval)->get(0)->array_size = array_length;//.push_back(atoi($2->get(i)->name().c_str()));
                        if((yyvsp[(2) - (4)])->children_size()==0){
                                ty = INT_TY;
                        }else if( (yyvsp[(2) - (4)])->children_size()==1){
                                (yyval)->get(0)->set_type(ARRAY);
                                ty = ARRAY;
                        }
                        else if((yyvsp[(2) - (4)])->children_size()==2){
                                (yyval)->get(0)->set_type(LIST_2);
                                ty = LIST_2;
                        } else if((yyvsp[(2) - (4)])->children_size()==3){
                                (yyval)->get(0)->set_type(LIST_3);
                                ty = LIST_3;
                        } else if((yyvsp[(2) - (4)])->children_size()==4){
                                (yyval)->get(0)->set_type(LIST_4);
                                ty = LIST_4;
                        } else {
                                (yyval)->get(0)->set_type(LIST_5);
                                ty = LIST_5;
                        } 
                        tables.add_var((yyvsp[(1) - (4)])->name(),ty);
                        tables.set_var_array((yyvsp[(1) - (4)])->name(),array_length);
                }
                else
                        {
                        cout << "error: redefined variable: "<< (yyvsp[(1) - (4)])->name() << endl ;return 1;
                        }
        ;}
    break;

  case 11:
#line 105 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("VerDef");(yyval)->add(*(yyvsp[(1) - (2)]));
                if(tables.get_var_in_scope((yyvsp[(1) - (2)])->name())==NONE){
                        Type ty;
                        cout << "VarDef_param: " << (yyvsp[(1) - (2)])->name()<< " " << (yyvsp[(2) - (2)])->children_size() << endl;
                        array_length.clear();
                        for(int i=0;i<(yyvsp[(2) - (2)])->children_size();i++)
                                array_length.push_back(atoi((yyvsp[(2) - (2)])->get(i)->name().c_str()));
                                (yyval)->get(0)->array_size = array_length;//.push_back(atoi($2->get(i)->name().c_str()));
                        if((yyvsp[(2) - (2)])->children_size()==0){
                                ty = INT_TY;
                        }else if( (yyvsp[(2) - (2)])->children_size()==1){
                                (yyval)->get(0)->set_type(ARRAY);
                                ty = ARRAY;}
                        else if((yyvsp[(2) - (2)])->children_size()==2){
                                (yyval)->get(0)->set_type(LIST_2);
                                ty = LIST_2;
                        } else if((yyvsp[(2) - (2)])->children_size()==3){
                                (yyval)->get(0)->set_type(LIST_3);
                                ty = LIST_3;
                        } else if((yyvsp[(2) - (2)])->children_size()==4){
                                (yyval)->get(0)->set_type(LIST_4);
                                ty = LIST_4;
                        } else {
                                
                                ty = LIST_5;
                        }
                        tables.add_var((yyvsp[(1) - (2)])->name(),ty);
                        tables.set_var_array((yyvsp[(1) - (2)])->name(),array_length);

                }
                else{
                        // print_table(tables);

                        cout << "error: redefined variable: "<< (yyvsp[(1) - (2)])->name() << endl ;return 1;}
        ;}
    break;

  case 12:
#line 140 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("ConstGroup");;}
    break;

  case 13:
#line 141 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(4) - (4)]); (yyval)->add(*(yyvsp[(2) - (4)]));;}
    break;

  case 14:
#line 143 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (1)]);
        if((yyvsp[(1) - (1)])->get_type()!=INT_TY){
                cout << "wrong type for Initval" << endl;return 1;
                
        }
        ;}
    break;

  case 15:
#line 150 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (2)]); (yyval)->add(*(yyvsp[(2) - (2)])); ;}
    break;

  case 16:
#line 153 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {printf("FuncDef\n"); (yyval) = new Node("FucDef "+(yyvsp[(2) - (4)])->name() + "INT" );
        if(tables.find_func((yyvsp[(2) - (4)])->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(INT_TY);
                tables.add_func((yyvsp[(2) - (4)])->name(),params);
                is_func = true;
                func_name = (yyvsp[(2) - (4)])->name();
        } 
        ;}
    break;

  case 17:
#line 166 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("FucDef "+(yyvsp[(2) - (5)])->name() +"INT" );(yyval)->add(*(yyvsp[(4) - (5)]));
        if(tables.find_func((yyvsp[(2) - (5)])->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                vector<vector<int>> func_array_length;
                params.push_back(INT_TY);
                for(int i=0;i<(yyvsp[(4) - (5)])->children_size();i++){
                        string name = (yyvsp[(4) - (5)])->get(i)->name();
                        Type ty = temp_type_map[name];
                        params.push_back(ty);
                        Node* ptr = (yyvsp[(4) - (5)])->get(i); //得到funcParam
                        if(ptr->children_size()!=0){ //有constant group，即是数组
                                ptr = ptr->get(0);
                                vector<int> array_length;
                                // array_length.push_back(i);
                                for(int i=0;i<ptr->children_size();i++){
                                     array_length.push_back(atoi(ptr->get(i)->name().c_str()));
                                     (yyval)->get(i)->array_size = array_length;//.push_back(atoi(ptr->get(j)->name().c_str()));
                                }
                                func_array_length.push_back(array_length);
                        }
                }      
                tables.add_func((yyvsp[(2) - (5)])->name(),params);
                tables.set_func_array((yyvsp[(2) - (5)])->name(),func_array_length);
                is_func = true;
                func_name = (yyvsp[(2) - (5)])->name();
        }
        ;}
    break;

  case 18:
#line 197 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("FucDef "+(yyvsp[(2) - (4)])->name() + "VOID" );
        if(tables.find_func((yyvsp[(2) - (4)])->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(VOID_TY);
                tables.add_func((yyvsp[(2) - (4)])->name(),params);
                is_func = true;
                func_name = (yyvsp[(2) - (4)])->name();
        }
        ;}
    break;

  case 19:
#line 210 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("FucDef "+(yyvsp[(2) - (5)])->name() + "VOID" );(yyval)->add(*(yyvsp[(4) - (5)]));
        if(tables.find_func((yyvsp[(2) - (5)])->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                vector<vector<int>> func_array_length;
                params.push_back(VOID_TY);
                for(int i=0;i<(yyvsp[(4) - (5)])->children_size();i++){
                        string name = (yyvsp[(4) - (5)])->get(i)->name();
                        Type ty = temp_type_map[name];
                        params.push_back(ty);
                        Node* ptr = (yyvsp[(4) - (5)])->get(i); //得到funcParam
                        if(ptr->children_size()!=0){ //有constant group，即是数组
                                ptr = ptr->get(0);
                                vector<int> array_length;
                                for(int i=0;i<ptr->children_size();i++){
                                     array_length.push_back(atoi(ptr->get(i)->name().c_str()));
                                     (yyval)->get(i)->array_size.push_back(atoi((yyvsp[(5) - (5)])->get(i)->name().c_str()));
                                }
                                func_array_length.push_back(array_length);
                        }
                }     
                tables.add_func((yyvsp[(2) - (5)])->name(),params);         
                tables.set_func_array((yyvsp[(2) - (5)])->name(),func_array_length);
                is_func = true;
                func_name = (yyvsp[(2) - (5)])->name();
        }
        
        ;}
    break;

  case 20:
#line 243 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("FuncFParams"); (yyval)->add(*(yyvsp[(1) - (1)])); ;}
    break;

  case 21:
#line 244 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = (yyvsp[(3) - (3)]); (yyval)->add(*(yyvsp[(1) - (3)])); ;}
    break;

  case 22:
#line 247 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node((yyvsp[(2) - (2)])->name());  
                temp_type_map[(yyvsp[(2) - (2)])->name()] = INT_TY;
        ;}
    break;

  case 23:
#line 250 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node((yyvsp[(2) - (5)])->name()); (yyval)->add(*(yyvsp[(5) - (5)]));
                
                for(int i=0;i<(yyvsp[(5) - (5)])->children_size();i++){
                        array_length.push_back(atoi((yyvsp[(5) - (5)])->get(i)->name().c_str()));
                        (yyval)->get(0)->array_size.push_back(atoi((yyvsp[(5) - (5)])->get(i)->name().c_str()));
                }
                if((yyvsp[(5) - (5)])->children_size()==0){
                        (yyval)->get(0)->set_type(ARRAY);
                        temp_type_map[(yyvsp[(2) - (5)])->name()] = ARRAY;
                }
                else if((yyvsp[(5) - (5)])->children_size()==1){        
                        (yyval)->get(0)->set_type(LIST_2);
                        temp_type_map[(yyvsp[(2) - (5)])->name()] = LIST_2;
                }else if((yyvsp[(5) - (5)])->children_size()==2){     
                        (yyval)->get(0)->set_type(LIST_3);  
                        temp_type_map[(yyvsp[(2) - (5)])->name()] = LIST_3;
                }else if((yyvsp[(5) - (5)])->children_size()==3){ 
                        (yyval)->get(0)->set_type(LIST_4);       
                        temp_type_map[(yyvsp[(2) - (5)])->name()] = LIST_4;
                }else{
                        (yyval)->get(0)->set_type(LIST_5);
                        temp_type_map[(yyvsp[(2) - (5)])->name()] = LIST_5;
                }
        ;}
    break;

  case 24:
#line 275 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {tables.BEGIN_SCOPE(); 
                for(auto &[j,k]:temp_type_map){
                        tables.add_var(j,k);
                }
                temp_type_map.clear();  
                if(is_func){
                        is_func = false;
                        Type ty = tables.get_func(func_name)[0];
                        tables.set_return_type(ty);
                        func_name = "";
                }
        ;}
    break;

  case 25:
#line 287 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {
                // print_table(tables);
                tables.END_SCOPE();
        ;}
    break;

  case 26:
#line 292 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("Block"); ;}
    break;

  case 27:
#line 293 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval)->rename("Block");;}
    break;

  case 28:
#line 294 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("BlockItems"); (yyval)->add(*(yyvsp[(1) - (1)])); ;}
    break;

  case 29:
#line 295 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = (yyvsp[(1) - (2)]); (yyval)->add(*(yyvsp[(2) - (2)])); 
        ;}
    break;

  case 30:
#line 298 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]); ;}
    break;

  case 31:
#line 298 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 32:
#line 300 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("AssignStmt"); (yyval)->add(*(yyvsp[(1) - (4)])); (yyval)->add(*(yyvsp[(3) - (4)]));
                // print_table(tables);
                cout <<"ASSIGN: "  << (yyvsp[(1) - (4)])->get_type() << " " << (yyvsp[(3) - (4)])->get_type() << endl;
                if((yyvsp[(1) - (4)])->get_type()!=INT_TY || (yyvsp[(3) - (4)])->get_type()!=INT_TY){
                        cout << "wrong type for AssignStmt" << endl;return 1;
                }
        ;}
    break;

  case 33:
#line 307 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("ExpStmt"); (yyval)->add(*(yyvsp[(1) - (2)]));  ;}
    break;

  case 34:
#line 308 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 35:
#line 309 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("IfStmt"); (yyval)->add(*(yyvsp[(3) - (5)])); (yyval)->add(*(yyvsp[(5) - (5)])); delete (yyvsp[(3) - (5)]); delete (yyvsp[(5) - (5)]); ;}
    break;

  case 36:
#line 310 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("IfElseStmt"); (yyval)->add(*(yyvsp[(3) - (7)])); (yyval)->add(*(yyvsp[(5) - (7)])); (yyval)->add(*(yyvsp[(7) - (7)])); ;}
    break;

  case 37:
#line 311 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("WhileStmt"); (yyval)->add(*(yyvsp[(3) - (5)])); (yyval)->add(*(yyvsp[(5) - (5)]));  ;}
    break;

  case 38:
#line 312 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("BreakStmt");;}
    break;

  case 39:
#line 313 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("ContinueStmt");;}
    break;

  case 40:
#line 314 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("ReturnStmt");
                if(tables.get_return_type()!=VOID_TY){
                        cout << "wrong return type" << endl;return 1;
                }
        ;}
    break;

  case 41:
#line 319 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)= new Node("ReturenStmt"); (yyval)->add(*(yyvsp[(2) - (3)]));
                if(tables.get_return_type()!=INT_TY || (yyvsp[(2) - (3)])->get_type()!=INT_TY){
                        cout << "wrong return type" << endl;return 1;
                }
        ;}
    break;

  case 42:
#line 325 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 43:
#line 327 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("LVal" + (yyvsp[(1) - (1)])->name()); (yyval)->set_type(tables.get_var((yyvsp[(1) - (1)])->name()));
        cout <<"HERE: " << (yyvsp[(1) - (1)])->name() << " " << (yyval) -> get_type() <<endl; 
        (yyval)->set_id((yyvsp[(1) - (1)])->name());
        if(!tables.find_var((yyvsp[(1) - (1)])->name())){
                cout << "undefined variable: " << (yyvsp[(1) - (1)])->name() << endl;return 1;
        }
        ;}
    break;

  case 44:
#line 334 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(2) - (2)]);(yyval)->rename("LVal" + (yyvsp[(1) - (2)])->name()) ;
        Type ty;
        (yyval)->set_id((yyvsp[(1) - (2)])->name());
        if((yyvsp[(2) - (2)])->children_size()==tables.get_var((yyvsp[(1) - (2)])->name())-2) //magic number : 判断是否是数组最后一维
                ty = INT_TY;
        else if((yyvsp[(2) - (2)])->children_size()==tables.get_var((yyvsp[(1) - (2)])->name())-3)
                ty = ARRAY;
        else if((yyvsp[(2) - (2)])->children_size()==tables.get_var((yyvsp[(1) - (2)])->name())-4)
                ty = LIST_2;
        else if((yyvsp[(2) - (2)])->children_size()==tables.get_var((yyvsp[(1) - (2)])->name())-5)
                ty = LIST_3;
        else if((yyvsp[(2) - (2)])->children_size()==tables.get_var((yyvsp[(1) - (2)])->name())-6)
                ty = LIST_4;
        else if((yyvsp[(2) - (2)])->children_size()==tables.get_var((yyvsp[(1) - (2)])->name())-7)
                ty = LIST_5;
        else{
                cout << "undefined variable: " << (yyvsp[(1) - (2)])->name() << endl;return 1;
        }

        cout << "ty: " << (yyvsp[(1) - (2)])->name() << " " << ty << endl;
        (yyval)->set_type(ty);
        if(!tables.find_var((yyvsp[(1) - (2)])->name())){
                cout << "undefined variable: " << (yyvsp[(1) - (2)])->name() << endl;return 1;
        }
        ;}
    break;

  case 45:
#line 359 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = new Node("Exps");;}
    break;

  case 46:
#line 359 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (4)]);(yyval)->add(*(yyvsp[(3) - (4)])); 
        if((yyvsp[(3) - (4)])->get_type()!=INT_TY){
                cout << "wrong type for Exps" << endl;return 1;
        }
        ;}
    break;

  case 47:
#line 365 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 48:
#line 365 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 49:
#line 365 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (1)]);

                (yyval)->set_type(INT_TY);
        ;}
    break;

  case 50:
#line 370 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 51:
#line 372 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 52:
#line 373 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (3)]);
                if(!tables.find_func((yyvsp[(1) - (3)])->name())){
                        cout << "undefined function" << endl;return 1;
                }
                Type ty = tables.get_func((yyvsp[(1) - (3)])->name())[0];
                (yyval)->set_type(ty);
        ;}
    break;

  case 53:
#line 380 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(1) - (4)]);(yyval)->add(*(yyvsp[(3) - (4)]));
                if(!tables.find_func((yyvsp[(1) - (4)])->name())){
                        cout << "undefined function" << endl;return 1;
                }
                vector<Type> params = tables.get_func((yyvsp[(1) - (4)])->name());
                if(params.size()-1!=(yyvsp[(3) - (4)])->children_size()){
                        cout << "wrong number of parameters" << endl;return 1;
                }


                cout << "Here" << endl;
                for(int i=0;i<(yyvsp[(3) - (4)])->children_size();i++){
                        if(params[i+1]!=(yyvsp[(3) - (4)])->get(i)->get_type()){
                                cout << "Param check " << i+1 << " " << params[i+1] << " " << (yyvsp[(3) - (4)])->get(i)->get_type() << endl;
                                cout << "wrong type of parameters" << endl;return 1;
                        }else{
                                cout << "CHECK DIM_1: " << params[i+1] << " " << (yyvsp[(3) - (4)])->get(i)->get_type() << endl;
                                if(params[i+1] >= 4){
                                        cout << "HERE" << endl;
                                        vector<int> array_length = tables.get_func_array((yyvsp[(1) - (4)])->name())[i];
                                        string id = (yyvsp[(3) - (4)])->get(i)->get_id();
                                        vector<int> array_length2 = tables.get_var_array(id);
                                        for(int j=0;j<array_length.size();j++){
                                                cout << "CHECK DIM: " << array_length[j] << " " << array_length2[j] << endl;
                                                if(array_length[j]!=array_length2[j]){
                                                        cout << "wrong type of parameters" << endl;return 1;
                                                }
                                        }

                                }
                        }
                }
                Type ty = params[0];
                (yyval)->set_type(ty);
        ;}
    break;

  case 54:
#line 415 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval) = (yyvsp[(2) - (2)]);(yyval)->add(*(yyvsp[(1) - (2)]));
                if((yyvsp[(2) - (2)])->get_type()!=INT_TY){
                        cout << "wrong type for UnaryExp" << endl;return 1;
                }
        ;}
    break;

  case 55:
#line 421 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("ADD"); ;}
    break;

  case 56:
#line 421 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("SUB") ;;}
    break;

  case 57:
#line 421 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("NOT") ;;}
    break;

  case 58:
#line 423 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    { (yyval) = new Node("FuncRParams"); (yyval)->add(*(yyvsp[(1) - (1)]));(yyval)->set_type((yyvsp[(1) - (1)])->get_type()); delete (yyvsp[(1) - (1)]);;}
    break;

  case 59:
#line 424 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)= (yyvsp[(3) - (3)]); (yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->rename("FuncRParams");;}
    break;

  case 60:
#line 427 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 61:
#line 428 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("MUL");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); 
        if((yyvsp[(3) - (3)])->get_type()!=INT_TY)
               {
                cout << "wrong type for MulExp" << endl;return 1;}
                
        (yyval)->set_type(INT_TY);
        ;}
    break;

  case 62:
#line 435 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("DIV");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)]));
        if((yyvsp[(3) - (3)])->get_type()!=INT_TY)
               { cout << "wrong type for MulExp" << endl;return 1;}
         (yyval)->set_type(INT_TY);;}
    break;

  case 63:
#line 439 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("MOD");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)]));
        if((yyvsp[(3) - (3)])->get_type()!=INT_TY)
               { cout << "wrong type for MulExp" << endl;return 1;}
         (yyval)->set_type(INT_TY);;}
    break;

  case 64:
#line 444 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 65:
#line 445 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("ADD");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 66:
#line 446 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("SUB");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 67:
#line 448 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 68:
#line 449 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("LT");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 69:
#line 450 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("GT");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 70:
#line 451 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("LE");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 71:
#line 452 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("GE");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 72:
#line 454 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 73:
#line 455 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("EQ");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 74:
#line 456 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("NE");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY);;}
    break;

  case 75:
#line 458 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 76:
#line 459 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("AND");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)])); (yyval)->set_type(INT_TY); ;}
    break;

  case 77:
#line 460 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 78:
#line 461 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"
    {(yyval)=new Node("OR");(yyval)->add(*(yyvsp[(1) - (3)]));(yyval)->add(*(yyvsp[(3) - (3)]));(yyval)->set_type(INT_TY);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2210 "/Users/lyucheng_wu/Desktop/lab3/lab1/build/sysy.tab.cc"
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


#line 463 "/Users/lyucheng_wu/Desktop/lab3/lab1/src/sysy.y"


void yyerror(const char *s) {
    printf("error: %s\n", s);
}
