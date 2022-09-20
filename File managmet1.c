#include <stdio.h>
#include <stdlib.h>

typedef struct stud
{
    int roll;
    char name[20];
    int marks;

} stud;

void creatrec();

int main()
{

    int choice;

    printf("1. Creat student record");
    printf("1. Search student record");
    printf("1. update student record");
    printf("1. Delete a student record");
    printf("1. Display student record");
    printf("1. sort student record");
    printf("1. Merge student record");

    scanf("%d", &choice);

    printf("Enter Your Choice ");

    switch (choice)
    {
    case 1:
        creatrec();
        break;
    case 2:
        searchRecord();
        break;
    case 3:
        updateRecord();
        break;
    case 4:
        deleteRecord();
        break;
    case 5:
        displayRecord();
        break;
    case 6:
        sortRecord();
        break;
    case 7:
        mergeRecord();
        break;
    case 0:
        break;
    default:
        printf("Option is wrong. Please try again.\n");
        break;
    }
}

void creatrec(){

    FILE *fp;
    fopen("studentrec.txt",'w');
    int n;
    printf("How many student do want to add ? ");
    scanf("%d",&n);
    stud *s;
    s = (stud*)malloc(sizeof(stud)*n);
    for(int i=0; i<n;i++)
    {
        printf("Enter student %dth student info\n",i+1);
        printf("Roll no. ");
        scanf("%d",&((s+i)->roll));
        printf("Name : ");
        scanf("%s",&((s+i)->name));
        printf("Marks: ");
        scanf("%d", &((s + i)->marks));
        fwrite(&s[i], sizeof(stud), 1, fp);

    }
    printf("Data Created.\n\n");
    fclose(fp);
}

// void creatrec()
// {
//     FILE *fp;
//     fp = fopen("stuRecord.txt", "w");
//     int n;
//     printf("Enter number of students to add: ");
//     scanf("%d", &n);
//     stud *s;
//     s = (stud *)malloc(sizeof(stud) * n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nEnter data of student %d.\n", i + 1);
//         printf("Roll no: ");
//         scanf("%d", &(s + i)->roll);
//         printf("Name: ");
//        // fflush(stdin);
//         scanf("%s", (s + i)->name);
//         printf("Marks: ");
//         scanf("%d", &((s + i)->marks));

//         fwrite(&s[i], sizeof(stud), 1, fp);
//     }
//     printf("Data Created\n\n");
//     fclose(fp);
// }

