%{
#include<stdio.h>
int identifiers=0, keywords=0, rOperators=0, aOperators=0, integers=0, statements=0;
%}

%%

"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do" keywords++;
"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if" keywords++;
"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static" keywords++;
"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" keywords++;

[a-zA-Z_][a-zA-Z0-9_]* identifiers++;

"=="|"!="|">"|"<"|">="|"<=" rOperators++;
"="|"+="|"-="|"*="|"/="|"%="|"<<="|">>="|"&="|"^="|"|=" aOperators++;

[0-9] integers++;
";" statements++;
.


%%





int main()
{
yyin= fopen("cpgm.txt","r");
yylex();
printf("The File contains:");
printf("\n\t%d Statements", statements);
printf("\n\t%d Identifiers",(identifiers-keywords));
printf("\n\t%d Keywords.\n",keywords);
printf("\n\t%d Integers.\n",integers);
printf("\n\t%d Relational Operators.\n",rOperators);
printf("\n\t%d Assignment Operators.\n",aOperators);
return 0;
}
 
int yywrap()
{
return(1);
}
