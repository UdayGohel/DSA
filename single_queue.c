#include<stdio.h>

int r=-1, f=-1;
int q[100];

void anqueue()
{
    int x;
    printf("Enter element you want to enter : ");
    scanf("%d",&x);
    if(r==99)
    {
        printf("Queue is Full");
    }
    else if (f==-1 && r==-1)
    {
        f=0;
        r=0;
        q[r]=x;
    }
    else 
    {
        r=r+1;
        q[r]=x;
    }

}
void dequeue()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is EMpty\n");
    }
    else if(f==r)
    {
        printf(" %d Element is Deleted \n",q[f]);
        f=-1;
        r=-1;
    }
    else
    {
        printf("%d Element Deleted\n",q[f]);
        f=f+1;
    }
}
void display()
{
    if(f==-1 && r==-1){
        printf("YOur QUeue is empty");
    }
    else{
        printf("Your element are given below \n");
    for(int i=f;i<=r;i++){
        printf("%d\n",q[i]);
    }
    }
}
void peep(){
    if(f==-1)
    {
        printf("Queue is EMpty\n");
    }
    else{
        printf("Your element is %d\n\n",q[f]);
    }
}


int main()
{
    int n;
    while(1)
    {
        printf("1.Insert Elememt in Queue\n 2.Delete Element i Queue\n 3.Dispay ALL Queue Element\n 4.Peep Element in queue\n 5.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
        anqueue();
            break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        peep();
        break;
        case 5:
        return 0;
        break;
        default:
        printf("Enter Valid choice !!");
            break;
        }
    }
    return 0;
}