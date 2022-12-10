#include <stdio.h>
#include <stdlib.h>

// Declare A variable
int size, f1 = -1, f2 = -1, f3 = -1, r1 = -1, r2 = -1, r3 = -1;
int *p1, *p2, *p3;

// Function For insert Value in Simple Queue :-

void anqueue(int *p, int a)
{
    // Check condition for Queue is Full or Not ?
    if (r1 == size - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (f1 == -1)
    {
        f1 = 0;
        r1 = 0;
        p[f1] = a;
    }
    else
    {
        r1++;
        p[r1] = a;
    }
}
// Function For Delete Value in Simple Queue :-

int dequeue(int *p)
{
    // Check Condition for Queue is Empty
    if (r1 == -1)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else if (r1 == f1)
    {
        int a = p[r1];
        printf("%d Element Deleted !\n", p[f1]);
        r1 = -1;
        f1 = -1;
        return a;
    }
    else
    {
        // Element Deleted
        printf("%d Element Deleted !\n", p[f1]);
        f1++;
        return p[f1 - 1];
    }
}
void display(int *p) // Display Function for simple queue
{
    if (f1 == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        // Logic for Display Element
        printf("Your element are given below \n");
        for (int i = f1, j = 1; i <= r1; i++)
        {
            printf("%d\n", p[i]);
        }
    }
}
// Insert Element in Double Ended Queue from front
void insert_front(int *p, int i)
{
    // Check Condition for Insertion
    if ((f2 == 0 && r2 == size - 1) || (f2 == r2 + 1))
    {
        printf("Overflow\n");
    }
    if (f2 == -1)
    {
        f2 = 0;
        r2 = 0;
    }
    else
    {
        if (f2 == 0)
        {
            f2 = size - 1;
        }
        else
        {
            f2--;
        }
    }
    p[f2] = i;
}
void insert_end(int *p, int i)
{
    if (r2 == size - 1)
    {
        r2 = 0;
    }
    else
    {
        r2++;
    }
    if (f2 == r2)
    {
        printf("Queue OverFlow !!\n");
    }
    else
    {
        if (f2 == -1)
        {
            f2 = 0;
            r2 = 0;
        }
        p[r2] = i; // Give Value to Queue
    }
}
// Function Double ended Queue For Delete Element From  Front
int delete_front(int *p)
{
    int a; // check condition for Queue Empty or Not
    if (f2 == -1)
    {
        printf("Queue UnderFlow !\n");
    }
    else
    {
        a = p[f2];
        if (f2 == r2)
        {
            printf("%d Element Deleted !\n", p[f2]);
            f2 = -1;
            r2 = -1;
            return a;
        }
        else
        {
            if (f2 == size - 1)
            {
                printf("%d Element Deleted !\n", p[f2]);
                f2 = 0;
            }
            else
            {
                printf("%d Element Deleted !\n", p[f2]);
                f2++;
            }

            return a;
        }
    }
}
// Function for Double Ended Queue to Delete Element from End :-
int delele_end(int *p)
{
    if (f2 == -1)
    {
        printf("Queue UnderFlow !\n");
    }
    else
    {
        int a = p[r2];
        if (r2 == f2)
        {
            printf("%d Element Deleted !\n", p[f2]);
            r2 = -1;
            f2 = -1;
        }
        else if (r2 == 0)
        {
            printf("%d Element Deleted !\n", p[f2]);
            r2 = size - 1;
        }
        else
        {
            printf("%d Element Deleted !\n", p[f2]);
            r2--;
        }
        return a;
    }
}

// Display Function For Double Ended Queue to Display All Element

void display2(int *p)
{
    if (f2 == -1 && r2 == -1)
    {
        printf("Queue is Empty.\n");
    }
    else if (f2 > r2)
    {
        printf("Your element are given below \n");
        for (int i = f2; i <= size - 1; i++)
        {
            printf("%d\n", p[i]);
        }
        for (int i = 0; i <= r2; i++)
        {
            printf("%d\n", p[i]);
        }
    }
    else
    {
        printf("Your element are given below \n");
        for (int i = f2; i <= r2; i++)
        {
            printf("%d\n", p[i]);
        }
    }
}
// Function For Circular Queue to insert Element
void insert_circ(int *p, int i)
{
    if (r3 == size - 1)
    {
        r3 = 0;
    }
    else
    {
        r3++;
    }
    if (f3 == r3)
    {
        printf("Queue Overflow !\n");
    }
    else
    {
        p[r3] = i;
        if (f3 == -1)
        {
            f3 = 0;
        }
    }
}
// Function for Delete the Element in circular Queue
int delete_circ(int *p)
{
    // check condition
    if (f3 == -1)
    {
        printf("Queue Under Flow");
    }
    else
    {
        int a = p[f3];
        if (f3 == r3)
        {
            printf("%d Element Deleted !\n", p[f3]);
            f3 = -1;
            r3 = -1;
            return a;
        }
        else
        {
            if (f3 == size - 1)
            {
                printf("%d Element Deleted !\n", p[f3]);
                f3 = 0;
            }
            else
            {
                printf("%d Element Deleted !\n", p[f3]);
                f3++;
            }
            return a;
        }
    }
}
// Display Function for circular Queue
void display3(int *p)
{
    if (f3 == -1 && r3 == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        if (f3 > r3)
        {
            printf("Your element are given below \n");
            for (int i = f3; i <= size - 1; i++)
            {
                printf("%d\n", p[i]);
            }
            for (int i = r3; i < f3; i++)
            {
                printf("%d\n", p[i]);
            }
        }
        else
        {
            printf("Your element are given below \n");
            for (int i = f3; i <= r3; i++)
            {
                printf("%d\n", p[i]);
            }
        }
    }
}
int main()
{
    int n, a, ins;
rep:
    printf("Which Queue you want to use :\n");
    printf("1.simple\n2.Double ended\n3.Circular\n4.Exit\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter size of Queue : ");
        scanf("%d", &size);
        p1 = (int *)malloc(sizeof(int) * size);
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    rep1:
        printf("Enter Choice :");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter Value :");
            scanf("%d", &ins);
            anqueue(p1, ins);
            break;
        case 2:
            dequeue(p1);
            break;
        case 3:
            display(p1);
            break;
        case 4:
            printf("Program Exited Successfully !!\n");
            return 0;
        default:
            printf("Enter Valid Choice !!");
        }
        goto rep1;
        break;
    case 2:
        printf("Enter the size of Queue : ");
        scanf("%d", &size);
        p2 = (int *)malloc(sizeof(int) * size);
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
    rep2:
        printf("Enter Your choice:");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter Element You Want to Enter ");
            scanf("%d", &ins);
            insert_front(p2, ins);
            break;
        case 2:
            printf("Enter Element :");
            scanf("%d", &ins);
            insert_end(p2, ins);
            break;
        case 3:
            delete_front(p2);
            break;
        case 4:
            delele_end(p2);
            break;
        case 5:
            display2(p2);
            break;
        case 6:
            printf("Program Exited Successfully !!\n");
            return 0;

        default:
            printf("Enter Valid Choice");
            break;
        }
        goto rep2;

    case 3:
        printf("Enter the size of Queue : ");
        scanf("%d", &size);
        p3 = (int *)malloc(sizeof(int) * size);
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    rep3:
        printf("Enter Your choice:");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter Element :");
            scanf("%d", &ins);
            insert_circ(p3, ins);
            break;
        case 2:
            delete_circ(p3);
            break;
        case 3:
            display3(p3);
            break;
        case 4:
            printf("Program Exited Successfully !!\n");
            return 0;
        default:
            printf("Enter valid Choice\n");
            break;
        }
        goto rep3;
    case 4:
        printf("Program Exited Successfully !!\n");
        return 0;
    }
    goto rep;
}