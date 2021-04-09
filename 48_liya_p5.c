//Strings ending with 00
#include<stdio.h>
#include<string.h>
int dfa=0;
void state0(char a)
{
	if(a=='0')
	{
		dfa=1;
	}
	else if(a=='1')
	{
		dfa=0;
	}
	else
	{
		dfa=-1;
	}
}
void state1(char a)
{
	if(a=='0')
	{
		dfa=2;
	}
	else if(a=='1')
	{
		dfa=0;
	}
	else
	{
		dfa=-1;
	}
}
void state2(char a)
{
	if(a=='0')
	{
		dfa=2;
	}
	else if(a=='1')
	{
		dfa=0;
	}
	else
	{
		dfa=-1;
	}
}

int isacceptance(char ch[])
{
	int len,i;
	len=strlen(ch);
	for(i=0;i<len-2;i++)
	{
		if(ch[i]=='0' || ch[i]=='1')
		{
			dfa=0;
		}
		else
		{
			return 0;
		}
	}
	for(i=len-2;i<len;i++)
	{
		if(dfa==0)
		{
			state0(ch[i]);
		}
		else if(dfa==1)
		{
			state1(ch[i]);
		}
		else if(dfa==2)
		{
			state2(ch[i]);
		}
		else 
		{
			return 0;
		}
	}
	if(dfa==2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void main()
{
	char ch[10];
	printf("Enter the binary string");
	scanf("%s",ch);
	
	if(isacceptance(ch))
	{
		printf("Accepted\n");
	}
	else
	{
		printf("Rejected\n");
	}	
}
