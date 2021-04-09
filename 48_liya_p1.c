//Strings ending with abb
#include<stdio.h>
#include<string.h>
int dfa=0;

void state0(char c)
{
	if(c=='a')
	{
	     dfa=1;
	}
	else if(c=='b')
	{
		dfa=0;
	}
	else
	{
		dfa=-1;
	}
        
}
void state1(char c)
{
  if(c=='b')
  {
	dfa=2;
  }
  else if(c='a')
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
  if(c=='b')
  {
     dfa=3;  
  }
  else if(c='a')
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
	if(c=='a')
	{
		dfa=1;
	}
	else if(c=='b')
	{
		dfa=0;
	}
	else
	{
		dfa=-1;
	}
} 



int isacceptance(char s[],int l)
{
 int i;
 for(i=0;i<l-3;i++)
 {
 	if(s[i]=='a' || s[i]=='b')
 	{
 		dfa=0;
 	}
 	else
 	{
 		return 0;
 	}
 }

 for(i=l-3;i<l;i++)
 {
	if(dfa==0)
	{
		state0(s[i]);
	}
	else if(dfa==1)
	{
		state1(s[i]);
	}
	else if(dfa==2)
	{
		state2(s[i]);
	}
    else if(dfa==3)
    {
    	state3(s[i]);
    }
    else
    {
		return 0;      
    }
 }



     if(dfa==3)
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
char s[20];
int l;
printf("Enter the string:");
scanf("%s",s);
l=strlen(s);
if(isacceptance(s,l))
{
	 printf("Accepted\n");
}
else 
{
	printf("Rejected\n");
}

}		
/*Output

Enter the string:aaaaabb
Accepted

Enter the string:aaaaaaaba


Rejected
*/


