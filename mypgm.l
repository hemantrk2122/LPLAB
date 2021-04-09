%{
#include<stdio.h>
int kw=0,i=0,ao=0,ro=0,ig=0,stmt=0;
%}

%%
"printf"|"scanf"|"int"|"main" kw++;
[a-zA-Z_][a-zA-Z0-9_]* i++;
"=="|"!="|">"|"<"|">="|"<=" ro++;
"="|"+="|"-="|"*="|"/="|"%="|"<<="|">>="|"&="|"^="|"|=" ao++;
";" stmt++;
[0-9] ig++;
.
%%
int yywrap(){
	return(1);
}
int main(){
	yyin=fopen("cpgm.txt","r");
	yylex();
	printf("\nNumber of KeyWord is %d\n",kw);
	printf("Number of identifier is %d\n",i-kw);
	printf("Number of assignment Operator is %d\n",ao);
	printf("Number of Relational Operator is %d\n",ro);
	printf("Number of Integers is %d\n",ig);
	printf("Number of statement is %d\n",stmt);
}
