#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud
{
    int rollNo;
    char name[10];
    int marks;
} stud;

// function prototypes
void setRecord();
void searchRecord();
void updateRecord();
void deleteRecord();
void displayRecord();
void sortRecord();
void mergeRecord();

int main()
{

    int option;
    printf("1.Create 2.Search 3.Update\n");
    printf("4.Delete 5.Display 6.Sort\n");
    printf("7.Merge 0.Quit\n");

    do
    {
        printf("\nEnter any 1 option: ");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
        case 1:
            setRecord();
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
    } while (option != 0);

    return 0;
}

void setRecord()
{
    FILE *fp;
    fp = fopen("stuRecord.txt", "w");
    int n;
    printf("Enter number of students to add: ");
    scanf("%d", &n);
    stud *s;
    s = (stud *)malloc(sizeof(stud) * n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data of student %d.\n", i + 1);
        printf("Roll no: ");
        scanf("%d", &((s + i)->rollNo));
        printf("Name: ");
        fflush(stdin);
        scanf("%s", (s + i)->name);
        printf("Marks: ");
        scanf("%d", &((s + i)->marks));

        fwrite(&s[i], sizeof(stud), 1, fp);
    }
    printf("Data Created.\n\n");
    fclose(fp);
}

void searchRecord()
{
    stud s;
    int r, flag = 0;
    FILE *fp;
    fp = fopen("stuRecord.txt", "r");
    printf("Enter Roll number to search: ");
    scanf("%d", &r);

    while (fread(&s, sizeof(stud), 1, fp))
    {
        if (s.rollNo == r)
        {
            flag = 1;
            printf("Roll no: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %d\n", s.marks);
            break;
        }
    }
    if (flag = 0)
        printf("Record not found.\n");
    printf("\n");
    fclose(fp);
}

void updateRecord()
{
    stud s;
    int r;
    FILE *fp, *fp1;
    fp = fopen("stuRecord.txt", "r");
    fp1 = fopen("stuRecordTemp.txt", "w");
    printf("Enter Roll number to update: ");
    scanf("%d", &r);

    while (fread(&s, sizeof(stud), 1, fp))
    {
        if (s.rollNo == r)
        {
            printf("Roll no: ");
            scanf("%d", &s.rollNo);
            printf("Name: ");
            fflush(stdin); // remove old and store new string
            scanf("%s", s.name);
            printf("Marks: ");
            scanf("%d", &s.marks);
        }

        fwrite(&s, sizeof(stud), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("stuRecord.txt", "w");
    fp1 = fopen("stuRecordTemp.txt", "r");

    while (fread(&s, sizeof(stud), 1, fp1))
    {
        fwrite(&s, sizeof(stud), 1, fp);
    }

    printf("\n");
    fclose(fp);
    fclose(fp1);
}

void deleteRecord()
{
    stud s;
    int r;
    FILE *fp, *fp1;
    fp = fopen("stuRecord.txt", "r");
    fp1 = fopen("stuRecordTemp.txt", "w");
    printf("Enter Roll number to delete: ");
    scanf("%d", &r);

    while (fread(&s, sizeof(stud), 1, fp))
    {
        if (s.rollNo == r)
        {
            continue;
        }

        fwrite(&s, sizeof(stud), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("stuRecord.txt", "w");
    fp1 = fopen("stuRecordTemp.txt", "r");

    while (fread(&s, sizeof(stud), 1, fp1))
    {
        fwrite(&s, sizeof(stud), 1, fp);
    }

    printf("Data Deleted.\n\n");
    fclose(fp);
    fclose(fp1);
}

void displayRecord()
{
    stud s;
    FILE *fp;
    fp = fopen("stuRecord.txt", "r");

    while (fread(&s, sizeof(stud), 1, fp))
    {
        printf("Roll no: %d\n", s.rollNo);
        printf("Name: %s\n", s.name);
        printf("Marks: %d\n\n", s.marks);
    }

    fclose(fp);
}

void sortRecord()
{
    stud s, s2;
    int max = 0;
    FILE *fp;
    char nmm[30];
    fp = fopen("stuRecord.txt", "r");
    while (fread(&s, sizeof(stud), 1, fp))
    {
        if (s.marks >= max)
        {
            max = s.marks;
            s2.rollNo = s.rollNo;
            strcpy(s2.name, s.name);
            s2.marks = s.marks;
        }
    }
    printf("Student with highest marks...\n");
    printf("Roll no: %d\n", s2.rollNo);
    printf("Name: %s\n", s2.name);
    printf("Marks: %d\n", s2.marks);
    printf("\n");
    fclose(fp);
}

void mergeRecord()
{
    stud s;
    FILE *fp;
    fp = fopen("stuRecord.txt", "a");

    printf("\nEnter data of student.\n");
    printf("Roll no: ");
    scanf("%d", &((&s)->rollNo));
    printf("Name: ");
    fflush(stdin);
    fflush(stdin);
    scanf("%s", (&s)->name);
    printf("Marks: ");
    scanf("%d", &((&s)->marks));

    fwrite(&s, sizeof(stud), 1, fp);

    printf("Data Merged.\n\n");
    fclose(fp);
}