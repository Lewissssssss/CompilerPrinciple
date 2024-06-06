/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/guming/compilers24spring/lab1/src/sysy.y"

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

#line 88 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sysy.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_CONST = 3,                  /* INT_CONST  */
  YYSYMBOL_ADD = 4,                        /* ADD  */
  YYSYMBOL_SUB = 5,                        /* SUB  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_NOT = 9,                        /* NOT  */
  YYSYMBOL_LT = 10,                        /* LT  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LE = 12,                        /* LE  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 17,                      /* ";"  */
  YYSYMBOL_COLON = 18,                     /* ":"  */
  YYSYMBOL_COMMA = 19,                     /* ","  */
  YYSYMBOL_LC = 20,                        /* "{"  */
  YYSYMBOL_RC = 21,                        /* "}"  */
  YYSYMBOL_LB = 22,                        /* "["  */
  YYSYMBOL_RB = 23,                        /* "]"  */
  YYSYMBOL_LP = 24,                        /* "("  */
  YYSYMBOL_RP = 25,                        /* ")"  */
  YYSYMBOL_CONST = 26,                     /* CONST  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_ID = 36,                        /* ID  */
  YYSYMBOL_VOID = 37,                      /* VOID  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_CompUnit = 39,                  /* CompUnit  */
  YYSYMBOL_Decl = 40,                      /* Decl  */
  YYSYMBOL_VarDecl = 41,                   /* VarDecl  */
  YYSYMBOL_VerDefGroup = 42,               /* VerDefGroup  */
  YYSYMBOL_VarDef = 43,                    /* VarDef  */
  YYSYMBOL_ConstGroup = 44,                /* ConstGroup  */
  YYSYMBOL_InitVal = 45,                   /* InitVal  */
  YYSYMBOL_FuncDef = 46,                   /* FuncDef  */
  YYSYMBOL_FuncDefPre = 47,                /* FuncDefPre  */
  YYSYMBOL_FuncFParams = 48,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 49,                /* FuncFParam  */
  YYSYMBOL_LC_B = 50,                      /* LC_B  */
  YYSYMBOL_RC_E = 51,                      /* RC_E  */
  YYSYMBOL_Block = 52,                     /* Block  */
  YYSYMBOL_BlockItems = 53,                /* BlockItems  */
  YYSYMBOL_BlockItem = 54,                 /* BlockItem  */
  YYSYMBOL_Stmt = 55,                      /* Stmt  */
  YYSYMBOL_Exp = 56,                       /* Exp  */
  YYSYMBOL_LVal = 57,                      /* LVal  */
  YYSYMBOL_Exps = 58,                      /* Exps  */
  YYSYMBOL_PrimaryExp = 59,                /* PrimaryExp  */
  YYSYMBOL_Number = 60,                    /* Number  */
  YYSYMBOL_UnaryExp = 61,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 62,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 63,               /* FuncRParams  */
  YYSYMBOL_MulExp = 64,                    /* MulExp  */
  YYSYMBOL_AddExp = 65,                    /* AddExp  */
  YYSYMBOL_RelExp = 66,                    /* RelExp  */
  YYSYMBOL_EqExp = 67,                     /* EqExp  */
  YYSYMBOL_LAndExp = 68,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 69                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    57,    58,    59,    61,    63,    66,    67,
      69,   106,   143,   144,   146,   153,   156,   169,   200,   213,
     246,   247,   250,   253,   278,   290,   295,   296,   297,   298,
     301,   301,   303,   310,   311,   312,   313,   314,   315,   316,
     317,   322,   328,   330,   337,   362,   362,   368,   368,   368,
     373,   375,   376,   383,   418,   424,   424,   424,   426,   427,
     430,   431,   438,   442,   447,   448,   449,   451,   452,   453,
     454,   455,   457,   458,   459,   461,   462,   463,   464
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_CONST", "ADD",
  "SUB", "MUL", "DIV", "MOD", "NOT", "LT", "GT", "LE", "GE", "EQ", "NE",
  "ASSIGN", "\";\"", "\":\"", "\",\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\"(\"", "\")\"", "CONST", "IF", "ELSE", "WHILE", "BREAK", "RETURN",
  "CONTINUE", "AND", "OR", "INT", "ID", "VOID", "$accept", "CompUnit",
  "Decl", "VarDecl", "VerDefGroup", "VarDef", "ConstGroup", "InitVal",
  "FuncDef", "FuncDefPre", "FuncFParams", "FuncFParam", "LC_B", "RC_E",
  "Block", "BlockItems", "BlockItem", "Stmt", "Exp", "LVal", "Exps",
  "PrimaryExp", "Number", "UnaryExp", "UnaryOp", "FuncRParams", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,    13,  -117,  -117,    73,   -89,  -117,   132,  -117,
     -19,  -117,  -117,   106,   138,  -117,   114,  -116,   -26,   -15,
    -117,  -117,  -117,   -32,  -117,    20,    -4,   -57,     3,    58,
      59,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    35,     5,    20,     9,    19,    96,     6,     7,
      56,    57,    15,    36,    37,    38,    39,    40,    41,    64,
      73,    43,    44,    45,    46,   106,    47,    48,    49,    50,
      51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* CompUnit: Decl  */
#line 56 "/home/guming/compilers24spring/lab1/src/sysy.y"
                {root.add(*yyvsp[0]); yyvsp[0]->print(1);delete yyvsp[0] ;}
#line 1238 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 3: /* CompUnit: FuncDef  */
#line 57 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  {root.add(*yyvsp[0]); yyvsp[0]->print(1);delete yyvsp[0] ;}
#line 1244 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 4: /* CompUnit: CompUnit Decl  */
#line 58 "/home/guming/compilers24spring/lab1/src/sysy.y"
                       {  root.add(*yyvsp[0]);yyvsp[0]->print(1); delete yyvsp[0];}
#line 1250 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 5: /* CompUnit: CompUnit FuncDef  */
#line 59 "/home/guming/compilers24spring/lab1/src/sysy.y"
                          { root.add(*yyvsp[0]);yyvsp[0]->print(1); delete yyvsp[0];}
#line 1256 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 6: /* Decl: VarDecl  */
#line 61 "/home/guming/compilers24spring/lab1/src/sysy.y"
               { yyval = yyvsp[0];}
#line 1262 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 7: /* VarDecl: INT VarDef VerDefGroup ";"  */
#line 63 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                      {yyval = yyvsp[-1]; yyval->add(*yyvsp[-2]); yyval->rename("INT VarDecl");
                }
#line 1269 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 8: /* VerDefGroup: VerDefGroup "," VarDef  */
#line 66 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                       {yyval = yyvsp[-2]; yyval->add(*yyvsp[0]);delete yyvsp[0];}
#line 1275 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 9: /* VerDefGroup: %empty  */
#line 67 "/home/guming/compilers24spring/lab1/src/sysy.y"
              {yyval = new Node("VerDefGroup"); }
#line 1281 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 10: /* VarDef: ID ConstGroup ASSIGN InitVal  */
#line 69 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                      {yyval = new Node("VerDef");yyval->add(*yyvsp[-3]);yyval->add(*yyvsp[-1]);
                if(tables.get_var_in_scope(yyvsp[-3]->name())==NONE){
                        Type ty;
                        vector<int> array_length;
                        array_length.clear();
                        cout << "VarDef_param: " << yyvsp[-3]->name()<< " " << yyvsp[-2]->children_size() << endl;
                        for(int i=0;i<yyvsp[-2]->children_size();i++)
                                array_length.push_back(atoi(yyvsp[-2]->get(i)->name().c_str()));
                                yyval->get(0)->array_size = array_length;//.push_back(atoi($2->get(i)->name().c_str()));
                        if(yyvsp[-2]->children_size()==0){
                                ty = INT_TY;
                                yyval->get(0)->set_type(INT_TY);
                        }else if( yyvsp[-2]->children_size()==1){
                                yyval->get(0)->set_type(ARRAY);
                                ty = ARRAY;
                        }
                        else if(yyvsp[-2]->children_size()==2){
                                yyval->get(0)->set_type(LIST_2);
                                ty = LIST_2;
                        } else if(yyvsp[-2]->children_size()==3){
                                yyval->get(0)->set_type(LIST_3);
                                ty = LIST_3;
                        } else if(yyvsp[-2]->children_size()==4){
                                yyval->get(0)->set_type(LIST_4);
                                ty = LIST_4;
                        } else {
                                yyval->get(0)->set_type(LIST_5);
                                ty = LIST_5;
                        } 
                        tables.add_var(yyvsp[-3]->name(),ty);
                        tables.set_var_array(yyvsp[-3]->name(),array_length);
                }
                else
                        {
                        cout << "error: redefined variable: "<< yyvsp[-3]->name() << endl ;return 1;
                        }
        }
#line 1323 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 11: /* VarDef: ID ConstGroup  */
#line 106 "/home/guming/compilers24spring/lab1/src/sysy.y"
                       {yyval = new Node("VerDef");yyval->add(*yyvsp[-1]);
                if(tables.get_var_in_scope(yyvsp[-1]->name())==NONE){
                        Type ty;
                        cout << "VarDef_param: " << yyvsp[-1]->name()<< " " << yyvsp[0]->children_size() << endl;
                        array_length.clear();
                        for(int i=0;i<yyvsp[0]->children_size();i++)
                                array_length.push_back(atoi(yyvsp[0]->get(i)->name().c_str()));
                                yyval->get(0)->array_size = array_length;//.push_back(atoi($2->get(i)->name().c_str()));
                        if(yyvsp[0]->children_size()==0){
                                ty = INT_TY;
                                yyval->get(0)->set_type(INT_TY);

                        }else if( yyvsp[0]->children_size()==1){
                                yyval->get(0)->set_type(ARRAY);
                                ty = ARRAY;}
                        else if(yyvsp[0]->children_size()==2){
                                yyval->get(0)->set_type(LIST_2);
                                ty = LIST_2;
                        } else if(yyvsp[0]->children_size()==3){
                                yyval->get(0)->set_type(LIST_3);
                                ty = LIST_3;
                        } else if(yyvsp[0]->children_size()==4){
                                yyval->get(0)->set_type(LIST_4);
                                ty = LIST_4;
                        } else {
                                
                                ty = LIST_5;
                        }
                        tables.add_var(yyvsp[-1]->name(),ty);
                        tables.set_var_array(yyvsp[-1]->name(),array_length);

                }
                else{
                        // print_table(tables);

                        cout << "error: redefined variable: "<< yyvsp[-1]->name() << endl ;return 1;}
        }
#line 1365 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 12: /* ConstGroup: %empty  */
#line 143 "/home/guming/compilers24spring/lab1/src/sysy.y"
            {yyval = new Node("ConstGroup");}
#line 1371 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 13: /* ConstGroup: "[" INT_CONST "]" ConstGroup  */
#line 144 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                      {yyval = yyvsp[0]; yyval->add(*yyvsp[-2]);}
#line 1377 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 14: /* InitVal: Exp  */
#line 146 "/home/guming/compilers24spring/lab1/src/sysy.y"
              {yyval = yyvsp[0];
        if(yyvsp[0]->get_type()!=INT_TY){
                cout << "wrong type for Initval" << endl;return 1;
                
        }
        }
#line 1388 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 15: /* FuncDef: FuncDefPre Block  */
#line 153 "/home/guming/compilers24spring/lab1/src/sysy.y"
                           {yyval = yyvsp[-1]; yyval->add(*yyvsp[0]); }
#line 1394 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 16: /* FuncDefPre: INT ID "(" ")"  */
#line 156 "/home/guming/compilers24spring/lab1/src/sysy.y"
                         {printf("FuncDef\n"); yyval = new Node("FucDef "+yyvsp[-2]->name() + "INT" );
        if(tables.find_func(yyvsp[-2]->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(INT_TY);
                tables.add_func(yyvsp[-2]->name(),params);
                is_func = true;
                func_name = yyvsp[-2]->name();
        } 
        }
#line 1412 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 17: /* FuncDefPre: INT ID "(" FuncFParams ")"  */
#line 169 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                  {yyval = new Node("FucDef "+yyvsp[-3]->name() +"INT" );yyval->add(*yyvsp[-1]);
        if(tables.find_func(yyvsp[-3]->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                vector<vector<int>> func_array_length;
                params.push_back(INT_TY);
                for(int i=0;i<yyvsp[-1]->children_size();i++){
                        string name = yyvsp[-1]->get(i)->name();
                        Type ty = temp_type_map[name];
                        params.push_back(ty);
                        Node* ptr = yyvsp[-1]->get(i); //得到funcParam
                        if(ptr->children_size()!=0){ //有constant group，即是数组
                                ptr = ptr->get(0);
                                vector<int> array_length;
                                // array_length.push_back(i);
                                for(int i=0;i<ptr->children_size();i++){
                                     array_length.push_back(atoi(ptr->get(i)->name().c_str()));
                                     yyval->get(i)->array_size = array_length;//.push_back(atoi(ptr->get(j)->name().c_str()));
                                }
                                func_array_length.push_back(array_length);
                        }
                }      
                tables.add_func(yyvsp[-3]->name(),params);
                tables.set_func_array(yyvsp[-3]->name(),func_array_length);
                is_func = true;
                func_name = yyvsp[-3]->name();
        }
        }
#line 1448 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 18: /* FuncDefPre: VOID ID "(" ")"  */
#line 200 "/home/guming/compilers24spring/lab1/src/sysy.y"
                        {yyval = new Node("FucDef "+yyvsp[-2]->name() + "VOID" );
        if(tables.find_func(yyvsp[-2]->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(VOID_TY);
                tables.add_func(yyvsp[-2]->name(),params);
                is_func = true;
                func_name = yyvsp[-2]->name();
        }
        }
#line 1466 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 19: /* FuncDefPre: VOID ID "(" FuncFParams ")"  */
#line 213 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                   {yyval = new Node("FucDef "+yyvsp[-3]->name() + "VOID" );yyval->add(*yyvsp[-1]);
        if(tables.find_func(yyvsp[-3]->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                vector<vector<int>> func_array_length;
                params.push_back(VOID_TY);
                for(int i=0;i<yyvsp[-1]->children_size();i++){
                        string name = yyvsp[-1]->get(i)->name();
                        Type ty = temp_type_map[name];
                        params.push_back(ty);
                        Node* ptr = yyvsp[-1]->get(i); //得到funcParam
                        if(ptr->children_size()!=0){ //有constant group，即是数组
                                ptr = ptr->get(0);
                                vector<int> array_length;
                                for(int i=0;i<ptr->children_size();i++){
                                     array_length.push_back(atoi(ptr->get(i)->name().c_str()));
                                     yyval->get(i)->array_size.push_back(atoi(yyvsp[0]->get(i)->name().c_str()));
                                }
                                func_array_length.push_back(array_length);
                        }
                }     
                tables.add_func(yyvsp[-3]->name(),params);         
                tables.set_func_array(yyvsp[-3]->name(),func_array_length);
                is_func = true;
                func_name = yyvsp[-3]->name();
        }
        
        }
#line 1502 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 20: /* FuncFParams: FuncFParam  */
#line 246 "/home/guming/compilers24spring/lab1/src/sysy.y"
                         { yyval = new Node("FuncFParams"); yyval->add(*yyvsp[0]); }
#line 1508 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 21: /* FuncFParams: FuncFParam "," FuncFParams  */
#line 247 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                         { yyval = yyvsp[0]; yyval->add(*yyvsp[-2]); }
#line 1514 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 22: /* FuncFParam: INT ID  */
#line 250 "/home/guming/compilers24spring/lab1/src/sysy.y"
                    { yyval = new Node(yyvsp[0]->name());  
                temp_type_map[yyvsp[0]->name()] = INT_TY;
        }
#line 1522 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 23: /* FuncFParam: INT ID "[" "]" ConstGroup  */
#line 253 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                 { yyval = new Node(yyvsp[-3]->name()); yyval->add(*yyvsp[0]);
                
                for(int i=0;i<yyvsp[0]->children_size();i++){
                        array_length.push_back(atoi(yyvsp[0]->get(i)->name().c_str()));
                        yyval->get(0)->array_size.push_back(atoi(yyvsp[0]->get(i)->name().c_str()));
                }
                if(yyvsp[0]->children_size()==0){
                        yyval->get(0)->set_type(ARRAY);
                        temp_type_map[yyvsp[-3]->name()] = ARRAY;
                }
                else if(yyvsp[0]->children_size()==1){        
                        yyval->get(0)->set_type(LIST_2);
                        temp_type_map[yyvsp[-3]->name()] = LIST_2;
                }else if(yyvsp[0]->children_size()==2){     
                        yyval->get(0)->set_type(LIST_3);  
                        temp_type_map[yyvsp[-3]->name()] = LIST_3;
                }else if(yyvsp[0]->children_size()==3){ 
                        yyval->get(0)->set_type(LIST_4);       
                        temp_type_map[yyvsp[-3]->name()] = LIST_4;
                }else{
                        yyval->get(0)->set_type(LIST_5);
                        temp_type_map[yyvsp[-3]->name()] = LIST_5;
                }
        }
#line 1551 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 24: /* LC_B: "{"  */
#line 278 "/home/guming/compilers24spring/lab1/src/sysy.y"
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
        }
#line 1568 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 25: /* RC_E: "}"  */
#line 290 "/home/guming/compilers24spring/lab1/src/sysy.y"
          {
                // print_table(tables);
                tables.END_SCOPE();
        }
#line 1577 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 26: /* Block: LC_B RC_E  */
#line 295 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  { yyval = new Node("Block"); }
#line 1583 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 27: /* Block: LC_B BlockItems RC_E  */
#line 296 "/home/guming/compilers24spring/lab1/src/sysy.y"
                               { yyval = yyvsp[-1]; yyval->rename("Block");}
#line 1589 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 28: /* BlockItems: BlockItem  */
#line 297 "/home/guming/compilers24spring/lab1/src/sysy.y"
                      { yyval = new Node("BlockItems"); yyval->add(*yyvsp[0]); }
#line 1595 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 29: /* BlockItems: BlockItems BlockItem  */
#line 298 "/home/guming/compilers24spring/lab1/src/sysy.y"
                              { yyval = yyvsp[-1]; yyval->add(*yyvsp[0]); 
        }
#line 1602 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 30: /* BlockItem: Decl  */
#line 301 "/home/guming/compilers24spring/lab1/src/sysy.y"
                 {yyval=yyvsp[0]; }
#line 1608 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 31: /* BlockItem: Stmt  */
#line 301 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                {yyval=yyvsp[0];}
#line 1614 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 32: /* Stmt: LVal ASSIGN Exp ";"  */
#line 303 "/home/guming/compilers24spring/lab1/src/sysy.y"
                            {yyval = new Node("AssignStmt"); yyval->add(*yyvsp[-3]); yyval->add(*yyvsp[-1]);
                // print_table(tables);
                cout <<"ASSIGN: "  << yyvsp[-3]->get_type() << " " << yyvsp[-1]->get_type() << endl;
                if(yyvsp[-3]->get_type()!=INT_TY || yyvsp[-1]->get_type()!=INT_TY){
                        cout << "wrong type for AssignStmt" << endl;return 1;
                }
        }
#line 1626 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 33: /* Stmt: Exp ";"  */
#line 310 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  { yyval = new Node("ExpStmt"); yyval->add(*yyvsp[-1]);  }
#line 1632 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 34: /* Stmt: Block  */
#line 311 "/home/guming/compilers24spring/lab1/src/sysy.y"
               {yyval=yyvsp[0];}
#line 1638 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 35: /* Stmt: IF "(" Exp ")" Stmt  */
#line 312 "/home/guming/compilers24spring/lab1/src/sysy.y"
                            { yyval = new Node("IfStmt"); yyval->add(*yyvsp[-2]); yyval->add(*yyvsp[0]); delete yyvsp[-2]; delete yyvsp[0]; }
#line 1644 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 36: /* Stmt: IF "(" Exp ")" Stmt ELSE Stmt  */
#line 313 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                      { yyval = new Node("IfElseStmt"); yyval->add(*yyvsp[-4]); yyval->add(*yyvsp[-2]); yyval->add(*yyvsp[0]); }
#line 1650 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 37: /* Stmt: WHILE "(" Exp ")" Stmt  */
#line 314 "/home/guming/compilers24spring/lab1/src/sysy.y"
                               { yyval = new Node("WhileStmt"); yyval->add(*yyvsp[-2]); yyval->add(*yyvsp[0]);  }
#line 1656 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 38: /* Stmt: BREAK ";"  */
#line 315 "/home/guming/compilers24spring/lab1/src/sysy.y"
                     {yyval = new Node("BreakStmt");}
#line 1662 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 39: /* Stmt: CONTINUE ";"  */
#line 316 "/home/guming/compilers24spring/lab1/src/sysy.y"
                        {yyval = new Node("ContinueStmt");}
#line 1668 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 40: /* Stmt: RETURN ";"  */
#line 317 "/home/guming/compilers24spring/lab1/src/sysy.y"
                      {yyval = new Node("ReturnStmt");
                if(tables.get_return_type()!=VOID_TY){
                        cout << "wrong return type" << endl;return 1;
                }
        }
#line 1678 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 41: /* Stmt: RETURN Exp ";"  */
#line 322 "/home/guming/compilers24spring/lab1/src/sysy.y"
                         {yyval= new Node("ReturenStmt"); yyval->add(*yyvsp[-1]);
                if(tables.get_return_type()!=INT_TY || yyvsp[-1]->get_type()!=INT_TY){
                        cout << "wrong return type" << endl;return 1;
                }
        }
#line 1688 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 42: /* Exp: LOrExp  */
#line 328 "/home/guming/compilers24spring/lab1/src/sysy.y"
             {yyval = yyvsp[0];}
#line 1694 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 43: /* LVal: ID  */
#line 330 "/home/guming/compilers24spring/lab1/src/sysy.y"
          {yyval = new Node("LVal" + yyvsp[0]->name()); yyval->set_type(tables.get_var(yyvsp[0]->name()));
        cout <<"HERE: " << yyvsp[0]->name() << " " << yyval -> get_type() <<endl; 
        yyval->set_id(yyvsp[0]->name());
        if(!tables.find_var(yyvsp[0]->name())){
                cout << "undefined variable: " << yyvsp[0]->name() << endl;return 1;
        }
        }
#line 1706 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 44: /* LVal: ID Exps  */
#line 337 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  {yyval = yyvsp[0];yyval->rename("LVal" + yyvsp[-1]->name()) ;
        Type ty;
        yyval->set_id(yyvsp[-1]->name());
        if(yyvsp[0]->children_size()==tables.get_var(yyvsp[-1]->name())-2) //magic number : 判断是否是数组最后一维
                ty = INT_TY;
        else if(yyvsp[0]->children_size()==tables.get_var(yyvsp[-1]->name())-3)
                ty = ARRAY;
        else if(yyvsp[0]->children_size()==tables.get_var(yyvsp[-1]->name())-4)
                ty = LIST_2;
        else if(yyvsp[0]->children_size()==tables.get_var(yyvsp[-1]->name())-5)
                ty = LIST_3;
        else if(yyvsp[0]->children_size()==tables.get_var(yyvsp[-1]->name())-6)
                ty = LIST_4;
        else if(yyvsp[0]->children_size()==tables.get_var(yyvsp[-1]->name())-7)
                ty = LIST_5;
        else{
                cout << "undefined variable: " << yyvsp[-1]->name() << endl;return 1;
        }

        cout << "ty: " << yyvsp[-1]->name() << " " << ty << endl;
        yyval->set_type(ty);
        if(!tables.find_var(yyvsp[-1]->name())){
                cout << "undefined variable: " << yyvsp[-1]->name() << endl;return 1;
        }
        }
#line 1736 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 45: /* Exps: %empty  */
#line 362 "/home/guming/compilers24spring/lab1/src/sysy.y"
       {yyval = new Node("Exps");}
#line 1742 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 46: /* Exps: Exps "[" Exp "]"  */
#line 362 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                               {yyval = yyvsp[-3];yyval->add(*yyvsp[-1]); 
        if(yyvsp[-1]->get_type()!=INT_TY){
                cout << "wrong type for Exps" << endl;return 1;
        }
        }
#line 1752 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 47: /* PrimaryExp: "(" Exp ")"  */
#line 368 "/home/guming/compilers24spring/lab1/src/sysy.y"
                       {yyval = yyvsp[-1];}
#line 1758 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 48: /* PrimaryExp: LVal  */
#line 368 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                        {yyval = yyvsp[0]; }
#line 1764 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 49: /* PrimaryExp: Number  */
#line 368 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                                           {yyval = yyvsp[0];

                yyval->set_type(INT_TY);
        }
#line 1773 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 50: /* Number: INT_CONST  */
#line 373 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  {yyval = yyvsp[0];}
#line 1779 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 51: /* UnaryExp: PrimaryExp  */
#line 375 "/home/guming/compilers24spring/lab1/src/sysy.y"
                      {yyval = yyvsp[0];}
#line 1785 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 52: /* UnaryExp: ID "(" ")"  */
#line 376 "/home/guming/compilers24spring/lab1/src/sysy.y"
                   {yyval = yyvsp[-2];
                if(!tables.find_func(yyvsp[-2]->name())){
                        cout << "undefined function" << endl;return 1;
                }
                Type ty = tables.get_func(yyvsp[-2]->name())[0];
                yyval->set_type(ty);
        }
#line 1797 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 53: /* UnaryExp: ID "(" FuncRParams ")"  */
#line 383 "/home/guming/compilers24spring/lab1/src/sysy.y"
                               {yyval = yyvsp[-3];yyval->add(*yyvsp[-1]);
                if(!tables.find_func(yyvsp[-3]->name())){
                        cout << "undefined function" << endl;return 1;
                }
                vector<Type> params = tables.get_func(yyvsp[-3]->name());
                if(params.size()-1!=yyvsp[-1]->children_size()){
                        cout << "wrong number of parameters" << endl;return 1;
                }


                cout << "Here" << endl;
                for(int i=0;i<yyvsp[-1]->children_size();i++){
                        if(params[i+1]!=yyvsp[-1]->get(i)->get_type()){
                                cout << "Param check " << i+1 << " " << params[i+1] << " " << yyvsp[-1]->get(i)->get_type() << endl;
                                cout << "wrong type of parameters" << endl;return 1;
                        }else{
                                cout << "CHECK DIM_1: " << params[i+1] << " " << yyvsp[-1]->get(i)->get_type() << endl;
                                if(params[i+1] >= 4){
                                        cout << "HERE" << endl;
                                        vector<int> array_length = tables.get_func_array(yyvsp[-3]->name())[i];
                                        string id = yyvsp[-1]->get(i)->get_id();
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
                yyval->set_type(ty);
        }
#line 1837 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 54: /* UnaryExp: UnaryOp UnaryExp  */
#line 418 "/home/guming/compilers24spring/lab1/src/sysy.y"
                          {yyval = yyvsp[0];yyval->add(*yyvsp[-1]);
                if(yyvsp[0]->get_type()!=INT_TY){
                        cout << "wrong type for UnaryExp" << endl;return 1;
                }
        }
#line 1847 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 55: /* UnaryOp: ADD  */
#line 424 "/home/guming/compilers24spring/lab1/src/sysy.y"
              { yyval = new Node("ADD"); }
#line 1853 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 56: /* UnaryOp: SUB  */
#line 424 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                             { yyval = new Node("SUB") ;}
#line 1859 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 57: /* UnaryOp: NOT  */
#line 424 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                                                           { yyval = new Node("NOT") ;}
#line 1865 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 58: /* FuncRParams: Exp  */
#line 426 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  { yyval = new Node("FuncRParams"); yyval->add(*yyvsp[0]);yyval->set_type(yyvsp[0]->get_type()); delete yyvsp[0];}
#line 1871 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 59: /* FuncRParams: Exp "," FuncRParams  */
#line 427 "/home/guming/compilers24spring/lab1/src/sysy.y"
                                    {yyval= yyvsp[0]; yyval->add(*yyvsp[-2]);yyval->rename("FuncRParams");}
#line 1877 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 60: /* MulExp: UnaryExp  */
#line 430 "/home/guming/compilers24spring/lab1/src/sysy.y"
                  {yyval=yyvsp[0];}
#line 1883 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 61: /* MulExp: MulExp MUL UnaryExp  */
#line 431 "/home/guming/compilers24spring/lab1/src/sysy.y"
                              {yyval=new Node("MUL");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); 
        if(yyvsp[0]->get_type()!=INT_TY)
               {
                cout << "wrong type for MulExp" << endl;return 1;}
                
        yyval->set_type(INT_TY);
        }
#line 1895 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 62: /* MulExp: MulExp DIV UnaryExp  */
#line 438 "/home/guming/compilers24spring/lab1/src/sysy.y"
                               {yyval=new Node("DIV");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]);
        if(yyvsp[0]->get_type()!=INT_TY)
               { cout << "wrong type for MulExp" << endl;return 1;}
         yyval->set_type(INT_TY);}
#line 1904 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 63: /* MulExp: MulExp MOD UnaryExp  */
#line 442 "/home/guming/compilers24spring/lab1/src/sysy.y"
                               {yyval=new Node("MOD");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]);
        if(yyvsp[0]->get_type()!=INT_TY)
               { cout << "wrong type for MulExp" << endl;return 1;}
         yyval->set_type(INT_TY);}
#line 1913 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 64: /* AddExp: MulExp  */
#line 447 "/home/guming/compilers24spring/lab1/src/sysy.y"
               {yyval=yyvsp[0];}
#line 1919 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 65: /* AddExp: AddExp ADD MulExp  */
#line 448 "/home/guming/compilers24spring/lab1/src/sysy.y"
                            {yyval=new Node("ADD");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1925 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 66: /* AddExp: AddExp SUB MulExp  */
#line 449 "/home/guming/compilers24spring/lab1/src/sysy.y"
                            {yyval=new Node("SUB");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1931 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 67: /* RelExp: AddExp  */
#line 451 "/home/guming/compilers24spring/lab1/src/sysy.y"
                {yyval=yyvsp[0];}
#line 1937 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 68: /* RelExp: RelExp LT AddExp  */
#line 452 "/home/guming/compilers24spring/lab1/src/sysy.y"
                           {yyval=new Node("LT");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1943 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 69: /* RelExp: RelExp GT AddExp  */
#line 453 "/home/guming/compilers24spring/lab1/src/sysy.y"
                           {yyval=new Node("GT");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1949 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 70: /* RelExp: RelExp LE AddExp  */
#line 454 "/home/guming/compilers24spring/lab1/src/sysy.y"
                           {yyval=new Node("LE");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1955 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 71: /* RelExp: RelExp GE AddExp  */
#line 455 "/home/guming/compilers24spring/lab1/src/sysy.y"
                           {yyval=new Node("GE");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1961 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 72: /* EqExp: RelExp  */
#line 457 "/home/guming/compilers24spring/lab1/src/sysy.y"
               {yyval=yyvsp[0];}
#line 1967 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 73: /* EqExp: EqExp EQ RelExp  */
#line 458 "/home/guming/compilers24spring/lab1/src/sysy.y"
                          {yyval=new Node("EQ");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1973 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 74: /* EqExp: EqExp NE RelExp  */
#line 459 "/home/guming/compilers24spring/lab1/src/sysy.y"
                          {yyval=new Node("NE");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY);}
#line 1979 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 75: /* LAndExp: EqExp  */
#line 461 "/home/guming/compilers24spring/lab1/src/sysy.y"
                {yyval=yyvsp[0];}
#line 1985 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 76: /* LAndExp: EqExp AND EqExp  */
#line 462 "/home/guming/compilers24spring/lab1/src/sysy.y"
                      {yyval=new Node("AND");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]); yyval->set_type(INT_TY); }
#line 1991 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 77: /* LOrExp: LAndExp  */
#line 463 "/home/guming/compilers24spring/lab1/src/sysy.y"
                 {yyval=yyvsp[0];}
#line 1997 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;

  case 78: /* LOrExp: LOrExp OR LAndExp  */
#line 464 "/home/guming/compilers24spring/lab1/src/sysy.y"
                        {yyval=new Node("OR");yyval->add(*yyvsp[-2]);yyval->add(*yyvsp[0]);yyval->set_type(INT_TY);}
#line 2003 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"
    break;


#line 2007 "/home/guming/compilers24spring/lab1/build/sysy.tab.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 466 "/home/guming/compilers24spring/lab1/src/sysy.y"


void yyerror(const char *s) {
    printf("error: %s\n", s);
}
