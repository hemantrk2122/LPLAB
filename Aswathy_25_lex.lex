%{
#include <stdio.h>
int no_of_stat=0;
int no_of_id=0;
int no_of_ar=0;
int no_of_re=0;
int no_of_key=0;
int no_of_int=0;
%}
digit [0-9]+
key "int"|"float"|"while"|"if"|"printf"|"for"
id [a-zA-Z][a-zA-Z0-9]*
arop "+"|"-"|"*"|"/"|"%"|"++"|"--"
relop "=="|">"|">="|"<="|"!="|"<"
semi ";"[ ]*"\n"	

%%
{digit} { no_of_int++; }
{key} { no_of_key++; }
{id} { no_of_id++; }
{arop} { no_of_ar++; }
{relop} { no_of_re++; }
{semi} { no_of_stat++; }
.
%%
int main()
{
    yyin=fopen("sample.c","r");
    yylex();
    yylex();
    printf("\n no of C statements:- %d",no_of_stat);
    printf("\n no of identifiers:- %d",no_of_id);
    printf("\n no of arithmetic operators :- %d",no_of_ar);
    printf("\n no of relational operators:- %d",no_of_re);
    printf("\n no of keywords:- %d",no_of_key);
    printf("\n no of integers:- %d\n",no_of_int);
}
int yywrap()
{
    return 1;
}

