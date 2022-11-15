#include<stdio.h>
 #include<ctype.h>
 #include<math.h>
 #include<string.h>
 #include<stdlib.h>
 int top=0;
 char s[100];
 
 void push(char x)
{

	if(top>=99)
	{
		printf("Stack Overflow");
		return;
	}
	top=top+1;
	s[top]=x;

}

char pop()
{
	char c;
	if(top==-1)
	{
		printf("Stack is Empty.\n");
	}
	c=s[top];
	top=top-1;
	return c;
}
int f(char x)
{
		if(x=='-'||x=='+')
		{
			return 1;
		}
		else if(x=='*'||x=='/')
		{
			return 3;
		}
		else if(x=='^')
		{
			return 6;
		}else if(x>=97&&x<=122)
		{
			return 7;
		}else if(x=='(')
		{
			return 9;
		}
		else if(x==')')
		{
			return 0;
		}
	
}
int g(char x)
{
		if(x=='-'||x=='+')
		{
			return 2;
		}
		else if(x=='*'||x=='/')
		{
			return 4;
		}
		else if(x=='^')
		{
			return 5;
		}else if(x>=97&&x<=122)
		{
			return 8;
		}else if(x=='(')
		{
			return 0;
		}
	}

int rank(char y)
{
	if(y=='+'||y=='-'||y=='*'||y=='/'||y=='^')
	{
		return -1;
	}
	else if(isalpha(y)||isdigit(y))
	{
		return 1;
	}
	else
	return 0;
	
}
int main()
{
	int i=0,rnk=0,j=-1;
	char ch[100],polish[100],next,temp;
	s[0]='(';
	
	printf("Enter Infix Expression:");
	scanf("%s",ch);
    strrev(ch);
    int k = 0;
    while(ch[k]!='\0')
    {
        if(ch[k]=='(')
            ch[k]=')';
        else if(ch[k]==')')
            ch[k]='(';
        k++;
    }
	strcat(ch,")");
	for(i=0;ch[i]!='\0';i++)
	{
		next=ch[i];
				while(f(next)<g(s[top]))
				{
					j++;
					temp=pop();
					polish[j]=temp;
					rnk+=rank(temp);
					if(rnk<1)
					{
						printf("Invalid expression");
						return 0;
					}
				}
				if(f(next)!=g(s[top]))
				{
					push(next);
					
				}
				else
				{
					pop();
				}
			}
	
	if(top!=-1||rnk!=1)
	{
		printf("Invalid expression");
		return 0;
	}
    strrev(polish);
	puts(polish);
}