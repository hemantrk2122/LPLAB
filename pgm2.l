%{
#include<stdio.h>
#include<string.h>
%}


%%
aa(a|b)*bb {printf("String Accepted\n");return 0;}
(0|1)*000(0|1)* { printf("String Accepted\n");return 0;}
.+ {printf("String Rejected\n");return 0;}

 

%%

int yywrap(void){} 

int main()
{
	printf("Enter the string");
	yylex();
	return 0;
	
}