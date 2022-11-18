#include<stdio.h>

int r=-1, f=-1;
int queue2[5];

void insert()
{
	int val;
	printf("Enter the element : ");
	scanf("%d", &val);
	if(r==4)
	{
		r=0;
	}
	else
	{
		r=r+1;
	}
	if(f==r)
	{
		printf("Queue is full!!\n");
	}
	if(f==-1)
	{
		f=0;
	}
	queue2[r]=val;
	printf("Element inserted!!\n");
}

int delete()
{
	int a;
	if(f==-1)
	{
		printf("Queue is empty");
		return 0;
	}
	a = queue2[f];
	if(f==r)
	{
		f=0;
		r=0;
		return a;
	}
	if(f==4)
	{
		f=0;
	}	
	else
	{
		f=f+1;
		return a;
	}
}

void display()
{
    if (f == -1)
        printf("quueue is empty");

    else
    {
        printf("queue elemets are : ");
        if (r == 4)
        {
            for (int i = f; i <= r; i++)
            {
                printf("%d", queue2[i]);
            }
        }
        else if (f > r)
        {

            for (int i = f; i <= 4; i++)
            {
                printf("%d ", queue2[i]);
            }

            for (int i = 0; i <= r; i++)
            {
                printf("%d ", queue2[i]);
            }
        }
    }
}
void peek()
{
    if (f == -1 && r == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("%d", queue2[f]);
    }
}


int main()
{
	int x;
    while (1)
    {
        printf("1.Insert\n2.Remove\n3.Display\n4.Exit\n");
        printf("Enter Your choice :");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
		case 4:
            peek();
            break;
        case 5:
            return 0;
            break;
        
        default:
        printf("Enter Valid choice :");
            break;
        }
    }
    
	return 0;
}