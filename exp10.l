%{
#include<stdio.h>
int pf=0,sf=0;
%}

%%
"printf" {pf++;fprintf(yyout,"%s","writef");}
"scanf" {sf++;fprintf(yyout,"%s","readf");}
. {fprintf(yyout,"%s",yytext);}
%%


int yywrap()
{
    return 1;
}


int main()
{
    yyin = fopen("input.c","r");
    yyout = fopen("output.c","w");
    yylex();
    remove("input.c");
    rename("output.c","input.c");
    printf("No of 'printf' statements : %d\n",pf);
    printf("No of 'scanf' statements : %d\n",sf);
}