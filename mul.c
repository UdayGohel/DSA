#include <stdio.h>
#include <stdlib.h>

void Creatmat(int *mat, int r, int c);

int main()
{
    int r1, c1, r2, c2;
    
    printf("Enter rows and columns for first Matrix: ");
    scanf("%d %d", &r1, &c1);
    
    printf("Enter rows and columns for second Matrix: ");
    scanf("%d %d", &r2, &c2);
    printf("\n");
    
    if(c1!=r2)
        printf("Matrix multiplication not possible.\n");
    else {
        int *a = (int *)malloc(sizeof(int *) * r1 * c1);
        int *b = (int *)malloc(sizeof(int *) * r2 * c2);
        int *c = (int *)malloc(sizeof(int *) * r1 * c2);
        
        printf("Enter values of first matrix...\n");
        Creatmat(a, r1, c1);
        
        printf("Enter values of second matrix...\n");
        Creatmat(b, r2, c2);
        
        printf("The resulted matrix multiplication is as follows:\n");
        for(int i=0; i<r1; i++) {
            for(int j=0; j<c2; j++) {
                int sum=0;
                for(int k=0; k<c1; k++)
                    sum+= *(a+i*c1+k) * *(b+k*c2+j);
                
                *(c+i+j) = sum;
                printf("%d ", *(c+i+j));
            }
            printf("\n");
        }
    }
    
    return 0;
}

void Creatmat(int *mat, int r, int c) {
    for(int i=0; i<r; i++) {
        printf("Row %d: ", i+1);
        for(int j=0; j<c; j++)
            scanf("%d", mat+i*c+j);
    }
    printf("\n");
}