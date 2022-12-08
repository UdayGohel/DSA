#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *del_front(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is Empty !!\n");
    }
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
    return head;
}
struct node *del_pos(struct node *head, int pos)
{
    if (pos == 1)
    {
        del_front(head);
    }
    else
    {
        struct node *temp = head;
        struct node *temp1 = head->link;
        while (pos != 2)
        {
            temp = temp->link;
            temp1 = temp->link;
        }
        temp->link = temp1->link;
        free(temp1);
        return head;
    }
}
struct node *del_end(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is Empty !!\n");
    }
    else if (head->link == NULL)
    {
        // del_front(head);
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        struct node *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

void insert_pos(struct node *head, int x, int p)
{
    struct node *temp = head;
    struct node *temp1 = malloc(sizeof(struct node));
    temp1->data = x;
    temp1->link = NULL;
    while (p != 2)
    {
        temp = temp->link;
        p--;
    }
    temp1->link = temp->link;
    temp->link = temp1;
}
void insert_end(struct node *head, int x)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
struct node *insert_front(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    temp->link = head;
    head = temp;
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is Empty !!\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int n, x, pos;
    printf("Your node has been created !!\nEnter your Element in First node :");
    scanf("%d", &head->data);
    head->link = NULL;

    while (1)
    {
        printf("1.Insert at End\n2.Insert at front\n3.Insert At Position\n");
        printf("4.Delete at Front\n5.Delete at End\n6.Delete at Position\n7.Display\n8.Exit\n\n");
        printf("Enter Your Choice :");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter Value :");
            scanf("%d", &x);
            insert_end(head, x);
            break;
        case 2:
            printf("Enter Value :");
            scanf("%d", &x);
            head = insert_front(head, x);
            break;
        case 3:
            printf("Which position Do Want to Enter Element :");
            scanf("%d", &pos);
            printf("Enter Your Element");
            scanf("%d", &x);
            if (pos == 1)
            {
                head = insert_front(head, x);
            }
            else
                insert_pos(head, x, pos);
            break;
        case 4:
            head = del_front(head);
            break;
        case 5:
            head = del_end(head);
            break;
        case 6:
            printf("Which position Do Want to Enter Element :");
            scanf("%d", &pos);
            head = del_pos(head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            return 0;
        default:
            printf("Enter Valid choice !!\n");
            break;
        }
    }
}