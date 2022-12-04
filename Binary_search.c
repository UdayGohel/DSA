#include<stdio.h>


int binary_search(int a[],int size,int t)
{
    int s,e;
    s=0;
    e=size-1;
    int mid =s+(e-s)/2;
    while(s<=e)
    {
        if(a[mid]==t)
        {
            return mid;
        }
        if(t>a[mid])
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
int main()
{
    int n,temp;
    printf("How many element Do you Enter :-");
    scanf("%d",&n);
    printf("Enter your Element :");
    int a[n],t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Which element do want to Find ?");
    scanf("%d",&t);  
    int find =binary_search(a,n,t);
    printf("Your Element is %d position ",find);
}