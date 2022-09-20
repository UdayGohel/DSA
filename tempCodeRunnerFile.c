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