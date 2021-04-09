%{
	#include<stdio.h>
	int lvowel=0,uvowel=0,lc=0,uc=0,w1v=1,temp=0;
%}

%%
[aeiou] lvowel++;
[a-z] lc++;
[AEIOU] uvowel++;
[A-Z] uc++;
[" "] {if (temp<(lvowel+uvowel)) w1v++; temp = (lvowel+uvowel);}

%%

int yywrap(){
	return 1;

}

int main(){
	yyin=fopen("sample.txt","r");
	yylex();
	printf("The number of vowels is %d\n, number of lowercase is %d\n, number of Uppercase is %d\n, the number of words with atleast 1 vowel is%d\n",lvowel+uvowel,lc+lvowel,uc+uvowel,w1v);
	return 0;
}