/****************************************************/
/* File: cminus.l                                   */
/* Lex specification for CMINUS                     */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
char previousToken[MAXTOKENLEN+1];
%}

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+

%%

"if"            {return IF;}
"else"          {return ELSE;}
"while"		{return WHILE;}
"return"        {return RETURN;}
"int"		{return INT;}
"void"		{return VOID;}
"="             {return ASSIGN;}
"=="            {return EQ;}
"!=" 		{return NE;}
"<"             {return LT;}
"<="		{return LE;}
">"		{return GT;}
">="		{return GE;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["		{return LBRACE;}
"]" 		{return RBRACE;}
"{"		{return LCURLY;}
"}"		{return RCURLY;}
";"             {return SEMI;}
","		{return COMMA;}
"/*"		{char c;
			while (1){
				c = input();
				if (c == '\n') lineno++;
				if (c == '\0') break;
				if (c == '*'){
					if (input() == '/') break;		
					else {}
				}
			}
		}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  strcpy(previousToken, tokenString);
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}

