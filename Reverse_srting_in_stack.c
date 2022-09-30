#include <stdio.h>  
#include <string.h>  
  
#define MAX 100  
int top,stack[MAX];  
  
void push(char x){  
  
      if(top == MAX-1){  
          printf("stack overflow");  
      }  else {  
          stack[++top]=x;  
      }  
  
}  
  
char pop(){   

    if(top==NULL)
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    
    top=top-1;
    return stack[top+1]; 
}  
  
  
int main()  
{  
   static char str[MAX];
   static char arr[MAX];
    
    int i;
    
    printf("Input a string: ");
    scanf("%[^\n]s",str);  
  
   for(i=0;i<strlen(str);i++)  
        push(str[i]);  
  printf("Your reverse string is : ");
   for(i=0;i<strlen(str);i++)  
     arr[i]=pop();
     arr[i]='\0';
     printf("%s",arr);
} 