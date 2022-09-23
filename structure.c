#include<stdio.h> 
#include<string.h>
#include<stdlib.h>


struct student{
	int roll_no;
	char name[25];
	float marks;
}*p;

/* struct structName
{
   data type name;
}; */
void createrec(struct student *ptr, int s){

    for(int i=0;i<s;i++){

        printf("Plase %d student details : \n",i+1);
        printf("Enter %d student Roll no : ",i+1);
        scanf("%d",&(ptr+i)->roll_no);
        printf("Enter %d studet Name : ",i+1);
        scanf("%s",&(ptr+i)->name);
        printf("Enter %d student Marks : ",i+1);
        scanf("%f",&(ptr+i)->marks);


    }
}
void searchstd(struct student *ptr, int s){

    int x;
    printf("Enter the roll Number of Student You want to search :");
    scanf("%d",&x);
    for(int i=0;i<s;i++)
	{
		if((ptr+i)->roll_no==x)
		{
			printf("Student's Roll number:%d\n",(ptr+i)->roll_no);
			printf("Student's Name:%s\n",(ptr+i)->name);
			printf("Student's Marks:%f\n",(ptr+i)->marks);
		}
	}

}

void updatestd(struct student *ptr,int s){

    int u;
    printf("Which student details you want to change ? ");
    scanf("%d",&u);
    for(int i =0;i<s;i++){
        if((ptr+i)->roll_no==u)
        {
             printf("Enter %d new  student Roll no : ",i+1);
             scanf("%d",&(ptr+i)->roll_no);
             printf("Enter %d new studet Name : ",i+1);
             scanf("%s",&(ptr+i)->name);
             printf("Enter %d new student Marks : ",i+1);
             scanf("%f",&(ptr+i)->marks);

        }

    }
}

void deletestd(struct student *ptr, int s)
{
    int d;
    printf("Enter student roll no. you want to delete : ");
    scanf("%d",&d);
    for(int i=0;i<s;i++){

        if((ptr+i)->roll_no==d)
        {
            for(int j=i;j<s;j++)
            {
                (ptr+j)->roll_no=(ptr+(j+1))->roll_no;
				strcpy((ptr+j)->name,(ptr+(j+1))->name);
				(ptr+j)->marks=(ptr+(j+1))->marks;
            }
        }
    }

}

void displaystd(struct student *ptr,int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		
		printf("Student %d\n",i+1);

		printf("Roll No:%d\n",(ptr+i)->roll_no);
		
		printf("Name:%s\n",(ptr+i)->name);
		
		printf("Marks:%f\n",(ptr+i)->marks);
	}
}

void sortstd(struct student *ptr,int s)
{

    int temp;
	char temp2[25];
	float temp1;
	for(int i=0;i<s-1;i++)
	{
		for(int j=i+1;j<s;j++)
		{
			if((ptr+i)->marks<(ptr+j)->marks)
			{
				temp1=(ptr+i)->marks;
				(ptr+i)->marks=(ptr+j)->marks;
				(ptr+j)->marks=temp1;
				strcpy(temp2,(ptr+i)->name);
				strcpy((ptr+i)->name,(ptr+j)->name);
				strcpy((ptr+j)->name,temp2);
				temp=(ptr+i)->roll_no;
				(ptr+i)->roll_no=(ptr+j)->roll_no;
				(ptr+j)->roll_no=temp;	
			}
		}
	}
}
void mergestd(struct student *ptr,int s,int t)
{
	int i;
	for(i=s;i<s+t;i++)
	{
	printf("Enter the Details of Student%d\n",i+1);
		printf("Enter the roll number:");
		scanf("%d",&(ptr+i)->roll_no);
		printf("Enter the Name:");
		scanf("%s",(ptr+i)->name);
		printf("Enter Marks:");
		scanf("%f",&(ptr+i)->marks);
	}
}
int main()
{
	int choice,n,m;
	char q;
	printf("1.Create Student record\n");
	printf("2.Search Student record\n");
	printf("3.Update Student record\n");
	printf("4.Delete a Student record\n");
	printf("5.Display Student record\n");
	printf("6.Sort Student record\n");
	printf("7.Merge Student record\n");
	printf("8.Exit\n");
	restart:
	printf("Select the Option:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("How many Student's detail you want to Enter:");
		scanf("%d",&n);
		p=(struct student*)malloc(n * sizeof(struct student));
	
		createrec(p,n);
		break;
		case 2:searchstd(p,n);
		break;
		case 3:updatestd(p,n);
		break;
		case 4:deletestd(p,n);
		n=n-1;
		break;
		case 5:displaystd(p,n);
		break;
		case 6:sortstd(p,n);
		break;
		case 7:
			printf("How many Students detail you want to add:");
			scanf("%d",&m);
			p=(struct student*)realloc(p,(n+m)*sizeof(struct student));
			mergestd(p,n,m);
			n=n+m;
			break;
		case 8:exit(0);
		default:
		printf("!!Select the Valid Choice!!");
		goto restart;	
	}
	printf("Do you want to perform a task again?(y/n)");
	scanf("%c",&q);
	scanf("%c",&q);
	if(q=='y')
	goto restart;
	
}