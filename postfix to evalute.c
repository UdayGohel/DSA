#include<stdio.h>
 #include<ctype.h>
 #include<math.h>
 #include<string.h>
 #include<stdlib.h>
 int top=0;
 char s[100];

// Function For Push element in stack  

 void push(int x)
{

	if(top>=99)
	{
		printf("Stack Overflow");
		return;
	}
	top=top+1;
	s[top]=x;

}

// Function For POP element in stack

int pop()
{
	int c;
	if(top==-1)
	{
		printf("Stack is Empty.\n");
	}
	c=s[top];
	top=top-1;
	return c;
}

int main(){

   char postfix[100],ch;
   int a,b;
   int ans;
  printf("Enter '#' to complete the Expression \n");
  printf("Enter postfix expression : ");
  for (int i = 0; i <= 99 - 1; i++) 
  {
        scanf("%c", &postfix[i]);
        if (postfix[i] == '#')
        {
          break;
        }
  }
  for (int i = 0; postfix[i] != '#'; i++) 
  {
        ch = postfix[i];
        if (isdigit(ch)){
          push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='^') 
        {
            a = pop();
            b = pop();
            switch (ch) /* ch is an operator */
            {
            case '^':
                ans = pow(b,a);
                break;
            case '*':
                ans = b * a;
                break;

            case '/':
                ans = b / a;
                break;

            case '+':
                ans = b + a;
                break;

            case '-':
                ans = b - a;
                break;
            }
            push(ans);
        }
  }
   printf(" \n Result of expression evaluation : %d \n", pop());

return 0;
}