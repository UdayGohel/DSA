#include<stdio.h>

int leanear_search(int a[],int size,int t)
{
    for(int i=0;i<size;i++)
    {
        if(t==a[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("How many element Do you Enter :-");
    scanf("%d",&n);
    printf("Enter your Element :");
    int a[n],t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Which element do want to Find ?");
    scanf("%d",&t);  
    int find = leanear_search(a,n,t);
    printf("your elsemt is %d position ",find);
    
}