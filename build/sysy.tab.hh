/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

