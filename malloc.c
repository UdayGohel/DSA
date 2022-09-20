#include<stdio.h>
#include<stdlib.h>


int main(){

    // use of malloc

    int *p,n;
    printf("Enter the size of array you want to creat : \n");
    scanf("%d",&n);
    p = (int*) malloc(n*sizeof(int));

    for( int i=0; i<n;i++)
    {
        printf("Enter the value no %d of this array \n",i);
        scanf("%d", &p[i]);
    }

    for(int i =0; i<n;i++)
    {
        printf("The value at %d of this array is %d\n",i,p[i]);
    }




    return 0;
}