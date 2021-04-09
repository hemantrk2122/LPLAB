//101 as substring
#include<stdio.h>
#include<string.h>
int dfa=0;
void state0(char c)
{
	if(c == '0')
	{
		dfa=0;
	}
	else if(c == '1')
	{
		dfa=1;
	}
}
void state1(char c)
{
	if(c == '0')
	{
		dfa=2;
	}
	else if(c == '1')
	{
		dfa=1;
	}
}
void state2(char c)
{
	if(c == '0')
	{
		dfa=0;
	}
	else if(c == '1')
	{
		dfa=3;
	}
}
void state3(char c)
{
	if(c == '0')
	{
		dfa=4;
	}
	else if(c == '1')
	{
		dfa=3;
	}
}
void state4(char c)
{
	if(c == '0')
	{
		dfa=5;
	}
	else if(c == '1')
	{
		dfa=3;
	}
}
void state5(char c)
{
	if(c == '0')
	{
		dfa=5;
	}
	else if(c == '1')
	{
		dfa=3;
	}
}
int isacceptance(char ch[])
{
	int i,len;
	len=strlen(ch);
	for(i=0;i<len;i++)
	{
		if (dfa == 0)
		{
			state0(ch[i]);
		}
		else if (dfa == 1)
		{
			state1(ch[i]);
		}
		else if(dfa == 2)
		{
			state2(ch[i]);
		}
		else if (dfa == 3)
		{
			state3(ch[i]);
		}
		else if (dfa == 4)
		{
			state4(ch[i]);
		}
		else if(dfa == 5)
		{
			state5(ch[i]);
		}
		else
		{
			return 0;
		}
	}
	if(dfa == 3||dfa == 4 ||dfa == 5)
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
	char ch[20];
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
