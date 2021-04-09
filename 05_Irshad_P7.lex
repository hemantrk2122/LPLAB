%{
#include<stdio.h>

int c=0,w=0,l=0;
%}

%%
[\n] ++l;
[" "] w++;
[^\n\t] c++;
%%

int yywrap()
{
return 1;
}

int main()
{
yyin = fopen("input.txt", "r");
yylex();
printf("Number of characters: %d\nNumber of Words: %d\nNumber of lines: %d\n",c,(w+1),(l-1));
return 0;
}
