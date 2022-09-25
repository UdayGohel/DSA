#include<stdio.h>
#include<stdlib.h>
int top=-1, *p,n;



void push(int *ptr){
    int b;
    if(top>=n-1){
      printf("Stact is overflow\n");
      return;
    }
    else{
      printf("Enter numbre you want to push : ");
      scanf("%d",&b);
      top++;
      ptr[top]=b;
    }
}
void pop(int *ptr)
{
  if(top==-1)
  {
    printf("Your stack is Empty ");
  }
  printf("%d is poped from stack ",ptr[top]);
  top-=1;
}
void peep(int *ptr)
{
  int l;
  printf("Enter number you want to peep : ");
  scanf("%d",&l);
  if(top-l+1<=-1){
    printf("Your Stack is underflow\n");
    //exit(0);
    return;
  }
  else
  {
    printf("%d\n",ptr[top-l+1]);
  }
}

void change(int *ptr)
{
  int s,l1;
  printf("Enter location to change number : ");
  scanf("%d",&s);
  if(top-s+1<=-1)
{
  printf("Stack Underflow : ");
  return;
}
else
{
  printf("Enter new number : ");
  scanf("%d",&l1);
  printf("Your number %d changed to %d \n",ptr[top],l1);
  ptr[top-s+1]=l1;
  
}

}

void display(int *ptr)
{
  if(top==-1){
    printf("Your stack underflow ");
    return;
  }
  else{
    for(int i=1,j=top;j>=0;i++,j--)
  {
    printf("Your %d number is %d\n",i,ptr[j]);
  }

}
}



int main()
{
    int a;
    printf("Enter size of stack : ");
    scanf("%d",&n);
    p=(int*) malloc(sizeof(int)*n);
    printf("\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peep\n");
    printf("4.change\n");
    printf("5.Display\n");
    printf("6.Exit\n");
    printf("\n");

    xyz : 
    printf("Enter Your choice : ");
    scanf("%d",&a);
   switch(a)
	{
		case 1:
			push(p);
			break;
		case 2:
			pop(p);
			break;
		case 3:
			peep(p);
			break;
		case 4:
			change(p);
		break;
		case 5:
			display(p);
			break;
		case 6:
			exit(0);
		default:
			printf("Please Enter valid choice : ");
	}
    goto xyz;

}
