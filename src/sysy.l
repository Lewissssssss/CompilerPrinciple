%option noinput
%option nounput
%option noyywrap

%{
#define YYSTYPE Node*
#include <stdio.h>
#include <ast/ast.h>
#include <string>
using namespace std;
#include "sysy.tab.hh"
extern TABLE_LISTS tables;

%}

digit [0-9]
blank [ \t\n]
nondigit [a-zA-Z_]  


%x COMMENT        
%x LINECOMMENT    

%%

<INITIAL>"/*"		{BEGIN COMMENT ;}
<COMMENT>"*/"  {BEGIN INITIAL ;}
<COMMENT>.|\n     {;}

<INITIAL>"//"            {BEGIN LINECOMMENT ;}
<LINECOMMENT>\n {BEGIN INITIAL ;}
<LINECOMMENT>[^\n]*  {;}

{digit}+        { yylval = new Node(string(yytext)); return INT_CONST; }
"+"             { return ADD; }
"-"             { return SUB; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }
"!"             { return NOT; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"="             { return ASSIGN; }
";"             { return SEMI; }
","             { return COMMA; }
":"             { return COLON; }
"("             { return LP;}
")"             {return RP; }
"{"             { return LC;}
"}"             { return RC; }
"["             { return LB; }
"]"             {return RB; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"return"        {  return RETURN; }
"int"           {return INT; }
"const"         { return CONST; }
"void"          { return VOID; }
{nondigit}({nondigit}|{digit})*              { yylval = new Node(string(yytext));  return ID; }
{blank}         {; }

.               { ;}


%%
