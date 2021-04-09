//1*2*3*

#include<stdio.h>
#include<string.h>
int dfa=0;


void state0(char c)
{
	if(c=='1')
	{
		dfa=1;
	}
	else if(c=='2')
	{
		dfa=2;
	}
	else if(c=='3')
	{
		dfa=3;
	}
	else
	{
		dfa=-1;
	}
}

void state1(char c)
{
	if(c=='2')
	{
		dfa=2;
	}
	else if(c=='3')
	{
		dfa=3;
	}
	else if(c=='1')
	{
		dfa=1;
	}
	else
	{
		dfa=-1;
	}

}
void state2(char c)
{
	if(c=='3')
	{
		dfa=3;
	}
	else if(c=='2')
	{
		dfa=2;
	}
	else
	{
		dfa=-1;
	}

}
void state3(char c)
{
	if(c=='3')
	{
		dfa=3;
	}
	else
	{
		dfa=-1;
	}
}
int isaccepted(char a[])
{
	int i,len;
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(dfa==0)
		{
			state0(a[i]);
			
		}
		else if(dfa==1)
		{
			state1(a[i]);
			
		}
		else if(dfa==2)
		{
			state2(a[i]);
			
		}
		else if(dfa==3)
		{
			state3(a[i]);
			
		}
		else
		{
			return 0;
		}
	}
	if(dfa==2 || dfa==1 || dfa==3)
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
	char a[20];
	printf("Enter the string");
	scanf("%s",a);
	if(isaccepted(a))
	{
		printf("Accepted\n");
	}
	else
	{
		printf("Rejected\n");
	}
}	
/*Output

Enter the string11112223
Accepted

Enter the string11231
Rejected

*/
