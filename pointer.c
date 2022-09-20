#include<stdio.h>

int main(){

    int a,b,*c,*d;

    scanf("%d",&a);
    scanf("%d",&b);
    d=&a;
    c=&b;

    

    
    printf(" Adress of a : %d", d);
    printf(" Valuse of a  %d", *d);
     


    return 0;
