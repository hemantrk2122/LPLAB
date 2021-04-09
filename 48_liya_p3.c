//1*2*3*
#include<stdio.h>
void main()
{
	int dfa=0,i=0;
	char ch[20];
	int transition[4][3]={1,2,3,1,2,3,-1,2,3,-1,-1,3};
	printf("Enter the string");
	scanf("%s",ch);
	while(ch[i]!='\0')
	{
		if(ch[i]!='1'&& ch[i]!='2'&& ch[i]!='3')
		{
			dfa = -1;
			break;
		}

		dfa=transition[dfa][ch[i]-'1'];
		i++;
		if(dfa == -1)
		{
			break;
		}
		//printf("%d\n",dfa );
	}
	//printf("%d\n",dfa );
	if(dfa == 1 || dfa == 2 || dfa == 3)
	{
		printf("String Accepted\n");
	}
	else
	{
		printf("String Rejected\n");
	}
}