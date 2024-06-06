/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_GUMING_COMPILERS24SPRING_LAB1_BUILD_SYSY_TAB_HH_INCLUDED
# define YY_YY_HOME_GUMING_COMPILERS24SPRING_LAB1_BUILD_SYSY_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_CONST = 258,               /* INT_CONST  */
    ADD = 259,                     /* ADD  */
    SUB = 260,                     /* SUB  */
    MUL = 261,                     /* MUL  */
    DIV = 262,                     /* DIV  */
    MOD = 263,                     /* MOD  */
    NOT = 264,                     /* NOT  */
    LT = 265,                      /* LT  */
    GT = 266,                      /* GT  */
    LE = 267,                      /* LE  */
    GE = 268,                      /* GE  */
    EQ = 269,                      /* EQ  */
    NE = 270,                      /* NE  */
    ASSIGN = 271,                  /* ASSIGN  */
    SEMI = 272,                    /* ";"  */
    COLON = 273,                   /* ":"  */
    COMMA = 274,                   /* ","  */
    LC = 275,                      /* "{"  */
    RC = 276,                      /* "}"  */
    LB = 277,                      /* "["  */
    RB = 278,                      /* "]"  */
    LP = 279,                      /* "("  */
    RP = 280,                      /* ")"  */
    CONST = 281,                   /* CONST  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    WHILE = 284,                   /* WHILE  */
    BREAK = 285,                   /* BREAK  */
    RETURN = 286,                  /* RETURN  */
    CONTINUE = 287,                /* CONTINUE  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    INT = 290,                     /* INT  */
    ID = 291,                      /* ID  */
    VOID = 292                     /* VOID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_GUMING_COMPILERS24SPRING_LAB1_BUILD_SYSY_TAB_HH_INCLUDED  */
