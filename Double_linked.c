#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addnew(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = x;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *insert_beg_db(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = x;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}
struct node *insert_pos_db(struct node *head, int x, int pos)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = addnew(newp, x);
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    if (pos == 1)
    {
        head = insert_beg_db(head, x);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
    }
    return head;
}
struct node *insert_end_db(struct node *head, int x)
{
    struct node *tp, *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = x;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}
struct node *delfirst(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
}
struct node *dellast(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    return head;
}
struct node *delpos(struct node *head, int pos)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (pos == 1)
    {
        head = delfirst(head);
        return head;
    }
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        head = dellast(head);
    }
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
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
            temp = temp->next;
        }
    }
}
int main()
{
    int n, x, pos;
    struct node *head = malloc(sizeof(struct node));
    printf("Enter your First Element :");
    scanf("%d", &head->data);
    head = addnew(head, head->data);
    printf("Your List has been Created !\n");
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
            head = insert_end_db(head, x);
            break;
        case 2:
            printf("Enter Value :");
            scanf("%d", &x);
            head = insert_beg_db(head, x);
            break;
        case 3:
            printf("Which position Do Want to Enter Element :");
            scanf("%d", &pos);
            printf("Enter Your Element : ");
            scanf("%d", &x);
            head = insert_pos_db(head, x, pos);
        case 4:
            head = delfirst(head);
            printf("Your First node has been Deleted !!\n");
            break;
        case 5:
            head = dellast(head);
            printf("Your Last node has been Deleted !!\n");
            break;
        case 6:
            printf("Which position Do Want to Delete Element :");
            scanf("%d", &pos);
            head = delpos(head, pos);
            printf("Your Last node has been Deleted !!\n");
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
    return 0;
}