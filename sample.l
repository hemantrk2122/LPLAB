%{
#include<stdio.h>

int i=0;
%}

%% 
([a-zA-Z0-9])*  {i++;} 
%% 
  

int yywrap()
{
return 1;
}

int main()
{

yylex();
printf("Number of characters: %d",i);
return 0;
}