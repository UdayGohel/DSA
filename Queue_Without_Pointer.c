#include<stdio.h>
int r=-1, f=-1, size=5;
int r1=-1,f1=-1;
int r2=-1,f2=-1;
int q[5];
int cirqueue[5];
int queue2[5];
int deq[5];
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
void display1()
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


int simple()
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
        display1();
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


void insert()
{
	int val;
	printf("Enter the element : ");
	scanf("%d", &val);
	if(r1==4)
	{
		r1=0;
	}
	else
	{
		r1=r1+1;
	}
	if(f1==r1)
	{
		printf("Queue is full!!\n");
	}
	if(f1==-1)
	{
		f1=0;
	}
	queue2[r1]=val;
	printf("Element inserted!!\n");
}

int delete()
{
	int a;
	if(f1==-1)
	{
		printf("Queue is empty");
		return 0;
	}
	a = queue2[f1];
	if(f1==r1)
	{
		f1=0;
		r1=0;
		return a;
	}
	if(f1==4)
	{
		f1=0;
	}	
	else
	{
		f1=f1+1;
		return a;
	}
}

void display2()
{
    if (f1 == -1)
        printf("quueue is empty");

    else
    {
        printf("queue elemets are : ");
        if (r1 == 4)
        {
            for (int i = f1; i <= r1; i++)
            {
                printf("%d", queue2[i]);
            }
        }
        else if (f1 > r1)
        {

            for (int i = f1; i <= 4; i++)
            {
                printf("%d ", queue2[i]);
            }

            for (int i = 0; i <= r1; i++)
            {
                printf("%d ", queue2[i]);
            }
        }
    }
}
void peek()
{
    if (f1 == -1 && r1 == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("%d", queue2[f1]);
    }
}


int circ()
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
            display2();
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



int infront()
{
	int val2;
	printf("Enter the element : ");
	scanf("%d", &val2);
	if((r2==size-1 && f2==0) || f2 == r2+1)
	{
		printf("Queue is full!!");
		return 0;
	}
	else
	{
		if(f2==-1)
		{
			r2=0;
			f2=0;
		}
		else
		{
			if(f2==0)
				f=size-1;
			else
				f2=f2-1;
		}
	}
	deq[f2]=val2;
}

int inrear()
{
	int val; 
	printf("Enter the element : ");
	scanf("%d", &val);
	if((r2==size-1 && f2==0) || f2==r2+1)
	{
		printf("Queue is full!!");
		return 0;
	}
	else
	{
		if(f2==-1)
		{
			f2=0;
			r2=0;
		}
		else
		{
			if(r2==size-1)
				r2=0;
			else
				r2=r2+1;
		}
	}
	deq[r2]=val;
}

void defront()
{
	if(f2==-1 && r2==-1)
	{
		printf("Queue is empty!!");
	}
	else
	{
		if(f2==r2)
		{
			f2=-1;
			r2=-1;
		}
		else
		{
			if(f2==size-1)
				f2=0;
			else
				f2=f2+1;
		}
	}
}

void derear()
{
	if(f2==-1 && r2==-1)
	{
		printf("Queue is empty!!");
	}
	else
	{
		if(f2==r2)
		{
			f2=-1;
			r2=-1;
		}
		else
		{
			if(r2==0)
				r2=size-1;
			else
				r2=r2-1;
		}
	}
}
int twoend()
{
	while(1)
		{
			int x,val1,val2;
			printf("\n1.Insertrear\n2.Insertfront\n3.Dequeuerear\n4.Dequeuefront\n5.Dispaly\n6.Exit\n");
			printf("Enter your choice : ");
			scanf("%d", &x);
			switch(x)
			{
				case 1:
					inrear();
					break;
				case 2:
					infront();
					break;
				case 3:
					derear();
					break;
				case 4:
					defront();
					break;
				case 5:
					display2();
					break;
				case 6 :
					return 0;
				default :
					printf("Enter valid Chocie!!\n");
			}
		}
	
}
	

int main()
{
	int n;
	while(1)
	{
		printf("In which method Do Want to perform Queue Operation ?? \n");
		printf("1.Simple Queue\n2.Circurar Queue\n3.Double-Ended Queue\n");
		printf("Enter Your Choice : \n");
		scanf("%d",&n);
		switch (n)
		{
		case 1:
			simple();
			break;
		case 2:
			circ();
			break;
		case 3:
			twoend();
			break;
		case 4:
			return 0;
			break;
		default:
		printf("Enter Valid Choice : ");
			break;
		}
	}
	return 0;
}