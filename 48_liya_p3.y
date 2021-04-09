%{
#include<stdio.h>
#include <stdlib.h>
%}
%token IF  NUMBER ID RELOP

%%
stmt : if_stmt { printf("Entered if statement is valid\n"); exit(0);}
 ;
if_stmt : IF '(' cond ')' 
 ;
cond : x RELOP x
 ;
x : ID
 | NUMBER
 ;
%%
int yyerror(char *msg)
{
 printf("Entered if statement is invalid\n");
 exit(0);
}
void main ()
{
 printf("Enter the statement: \n");
 yyparse();
 printf("\nValid\n\n");
}