%{
#include<stdio.h>

int ch=0,word=0,line=0;
%}

%%
[\n] ++line;
[" "] word++;
[^\n\t] ch++;
%%

int yywrap()
{
return 1;
}

int main()
{
yyin = fopen("sample.txt", "r");
yylex();
printf("Number of characters: %d\nNumber of Words: %d\nNumber of lines: %d\n",ch,(word+line),(line));
return 0;
}
