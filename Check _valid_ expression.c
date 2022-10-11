// Write a program to check the expression for valid usage of parenthesis.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;

int isFull(char* s){
    if(top==strlen(s)-1){
        return 1;
    }
    return 0;
}

int isEmpty(char* s){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(char* s, char c){
    if(isFull(s)){
        printf("Stack overflow!\n");
        return;
    }
    top++;
    s[top]=c;
}

void pop(char* s){
    // if(isEmpty(s)){
    //     printf("Stack underflow!\n");
    //     return;
    // }
    top--;
}

int main(){
    int n;
    printf("Enter the number of characters : ");
    scanf("%d",&n);
    char* str;
    str=(char*)malloc(sizeof(char)*n);
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='{' || str[i]=='(' || str[i]=='['){
            push(str,str[i]);
        }
        else if(str[i]=='}' && str[top]=='{')
            pop(str);
        else if(str[i]==']' && str[top]=='[')
            pop(str);
        else if(str[i]==')' && str[top]=='(')
            pop(str);
    }
    if(isEmpty(str))
        printf("Valid\n");
    else    
        printf("Invalid\n");
    return 0;
}