/****************************************************/
/* File: cminus.y                                     */
/* The CMINUS Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex

%}

%token IF ELSE WHILE RETURN INT VOID END 
%token ID NUM 
%token ASSIGN EQ NE LT LE GT GE PLUS MINUS TIMES OVER LPAREN RPAREN LBRACE RBRACE LCURLY RCURLY SEMI COMMA
%token ERROR 

%% /* Grammar for CMINUS */

program     : declaration_list
                 { savedTree = $1;} 
            ;

declaration_list : declaration_list declaration
			{
				YYSTYPE t = $1;
				if (t != NULL){
					while(t->sibling != NULL)
						t = t->sibling;
					t->sibling = $2;
					$$ = $1; }
				else $$ = $2;
			}
		 | declaration {$$ = $1;}
		;

declaration : var_declaration { $$ = $1; }
	    | fun_declaration { $$ = $1; }		
	    ;
				
var_declaration : type_specifier ID{
				    savedName = copyString(previousToken);
				    savedLineNo = lineno;
				    $$ = newExpNode(VarDeK);
				    $$->attr.name = savedName;
				    $$->lineno = savedLineNo;
				    }
	       	SEMI {	$$ = $3;
			$$->child[0] = $1;
		}
		|type_specifier ID{
				   savedName = copyString(previousToken);
				   savedLineNo = lineno; 
				   $$ = newExpNode(VarDeK);
				   $$->attr.name = savedName;
				   $$->lineno = savedLineNo;
			     	 }
		LBRACE NUM {savedName = copyString(tokenString);
			    $$ = $3; 
			    $$->child[0] = $1;
			    $$->child[1] = newExpNode(ConstK);
			    $$->child[1]->attr.val = atoi(savedName); 
			}RBRACE SEMI{$$ = $3;};

type_specifier : INT {$$ = newExpNode(TypeK);
	       	      $$->attr.type = "int";
	     	} 
		| VOID {$$ = newExpNode(TypeK);
			$$->attr.type = "void";};

fun_declaration : type_specifier ID {
		  savedName = copyString(previousToken);
		  savedLineNo = lineno;
		  $$ = newExpNode(FunDeK);
		  $$->attr.name = savedName;
		  $$->lineno = savedLineNo;
		}
	       	LPAREN params RPAREN compound_stmt
			{	
			  $$ = $3;
			  $$->child[0] = $1;
			  $$->child[1] = $5;
			  $$->child[2] = $7; 		  
			}
		;

params : param_list{$$ = $1; }
       | VOID { $$ = newExpNode(SingleParaK);
		$$->child[0] = newExpNode(TypeK);
		$$->child[0]->attr.type = "void";};

param_list : param_list COMMA param 
		{
		  YYSTYPE t = $1;
		  if (t != NULL){
			while(t->sibling != NULL)
			  t = t->sibling;
			t->sibling = $3;
			$$ = $1; }
		  else $$ = $3;
		}
	| param {$$ = $1; };

param : type_specifier ID {
      			   savedName = copyString(previousToken);
     			   savedLineNo = lineno; 
			   $$ = newExpNode(SingleParaK);
			   $$->child[0] = $1; 
			   $$->attr.name = savedName;
			   $$->lineno = savedLineNo;}
      | type_specifier ID {savedName = copyString(previousToken);
			savedLineNo = lineno;
			$$ = newExpNode(ArrParaK);
			$$->attr.name = savedName;
			$$->lineno = savedLineNo;}
			LBRACE RBRACE{
			$$ = $3;
			$$->child[0] = $1;
			$$->attr.name = savedName;
			$$->lineno = savedLineNo;}
			;

compound_stmt : LCURLY local_declarations statement_list RCURLY 
		{
		 $$ = newStmtNode(CompoundK);
		 $$->child[0] = $2;
		 $$->child[1] = $3;
		};

local_declarations : local_declarations var_declaration
			{
			  YYSTYPE t = $1;
			  if(t != NULL){
				while(t->sibling != NULL)
				  t = t->sibling;
			  	t->sibling = $2;
			 	 $$ = $1; }
			  else $$ = $2; 
			}
		| {$$= NULL;};

statement_list : statement_list statement 
		{
		  YYSTYPE t = $1;
		  if(t != NULL){
			while(t->sibling != NULL)
			  t = t->sibling;
			t->sibling = $2;
			$$ = $1; }
		  else $$ = $2;
		}
		| {$$ = NULL;};

statement : expression_stmt {$$ = $1; }
	  | compound_stmt {$$ = $1; }
	  | selection_stmt {$$ = $1; }
	  | iteration_stmt {$$ = $1; }
	  | return_stmt {$$ = $1; };

expression_stmt : expression SEMI {$$ = $1; } | SEMI {};

selection_stmt : IF LPAREN expression RPAREN statement {
	       		$$ = newStmtNode(IfK);
			$$->child[0] = $3;
			$$->child[1] = $5;}
	       	| IF LPAREN expression RPAREN statement ELSE statement {
			$$ = newStmtNode(IfThenK);
			$$->child[0] = $3;
			$$->child[1] = $5;
			$$->child[2] = $7;
		};

iteration_stmt : WHILE LPAREN expression RPAREN statement {
	       		$$ = newStmtNode(IterK);
			$$->child[0] = $3;
			$$->child[1] = $5;};

return_stmt : RETURN SEMI {}	
	    | RETURN expression SEMI {
		$$ = newStmtNode(ReturnK);
		$$->child[0] = $2;};

expression : var ASSIGN expression {
	   $$ = newStmtNode(AssignK);
	   $$->child[0] = $1;
	   $$->child[1] = $3;
	   $$->attr.op = ASSIGN; }
	   | simple_expression {$$ = $1;};

var : ID {
    	savedName = copyString(previousToken);
	savedLineNo = lineno;
	$$ = newExpNode(IdK);
	$$->lineno = savedLineNo;
	$$->attr.name = savedName;
}
    | ID{savedName = copyString(previousToken);
	savedLineNo = lineno;
	$$ = newExpNode(IdK);
	$$->attr.name = savedName;
	$$->lineno = savedLineNo;
	} LBRACE expression RBRACE {
	$$ = $2;
	$$->child[0] = $4;} ;

simple_expression : additive_expression LE additive_expression {
		  	$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = LE;
		  }
		  | additive_expression LT additive_expression {
			$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = LT;
		  }
		  | additive_expression GT additive_expression {
		  	$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = GT;
		  }
		  | additive_expression GE additive_expression {
			$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = GE;
		  }
		  | additive_expression NE additive_expression {
		  	$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = NE;
		  }
		  | additive_expression EQ additive_expression {
			$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = EQ;
		  }
		  | additive_expression {$$ = $1;};

additive_expression : additive_expression PLUS term{
		    	$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = PLUS;}
		    | additive_expression MINUS term{
		    	$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = MINUS;}
		    | term{$$ = $1;};


term : term TIMES factor{
			$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = TIMES;}
     | term OVER factor{
		    	$$ = newExpNode(OpK);
			$$->child[0] = $1;
			$$->child[1] = $3;
			$$->attr.op = OVER;}
     | factor{$$ = $1;};

factor : LPAREN expression RPAREN {$$ = $2;}
       | var {$$ = $1;}
       | call {$$ = $1;}
       | NUM {
		$$ = newExpNode(ConstK);
		$$->attr.val = atoi(tokenString);
	};

call : ID {savedName = copyString(previousToken);
     	  savedLineNo = lineno;
	  $$ = newExpNode(CallK);
	  $$->attr.name = savedName;
	  $$->lineno = savedLineNo;}
     	LPAREN args RPAREN{
     	$$ = $2;
	$$->child[0] = $4;
     };

args : arg_list{ $$ = $1; }
     | {$$ = NULL;} ;

arg_list : arg_list COMMA expression {
	 	YYSTYPE t = $1;
		if(t!=NULL){
		  while(t->sibling != NULL)
			t = t->sibling;
		  t->sibling = $3;
		  $$ = $1;}
		else $$ = $3; 
	 }
	 | expression {$$ = $1; };
                 
%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the CMINUS scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

