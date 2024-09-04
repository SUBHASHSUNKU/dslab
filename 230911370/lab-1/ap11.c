#include <stdio.h>
int main()
{
    int arrA[100][100],arrB[100][100],arrC[100][100],rows,cols;
    printf("enter the number of rows: ");
    scanf("%d", &rows);
    printf("enter the number of columns: ");
    scanf("%d", &cols);
    //matrix A
    printf("enter the elements of the matrix A: ");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d", &arrA[i][j]);
        }
    }
    //matrix B
    printf("enter the elements of the matrix B: ");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d", &arrB[i][j]);
        }
    }
    //matrix C
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(arrA[i][j]>=arrB[i][j])
            {
                arrC[i][j]=arrA[i][j];
            }
            else
            {
                arrC[i][j]=arrB[i][j];
            }
        }
    }
     printf("matrix C:");
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ", arrA[i][j]);
        }
        printf("\n");
    }
     printf("matrix C:");
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ", arrB[i][j]);
        }
        printf ("\n");
    }
    printf("matrix C:");
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ", arrC[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
