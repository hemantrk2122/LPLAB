%{
	#include<stdio.h>
	int ch=0,l=1,w=0;
%}

%%
[\n] l++;
[" "] w++;
[^\n\t] ch++;
%%
int yywrap(){
	return 1;
}

int main(){
	yyin=fopen("sample.txt","r");
	yylex();
	printf("The number of character is %d\nand lines is %d\n and words is %d\n ",ch,(l),(l+w));
	return 0;

}