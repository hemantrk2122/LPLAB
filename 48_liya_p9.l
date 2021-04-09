%{ 
#include<stdio.h> 
#include<string.h> 
char line[10]; 

%} 
TEXT [A-Za-z]
%% 
[0-9] {;}
[\t\n] {;}
{TEXT}+ {strcpy(line,yytext);fprintf(yyout,"%s",line);}



%% 


int yywrap() 
{ 
	return 1; 
} 


int main() 
{ 
	
	 
	yyin=fopen("input.txt","r"); 
	yyout=fopen("output.txt","w"); 
	yylex(); 
} 
