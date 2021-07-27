#include<stdio.h>
#include<stdlib.h>

void mat_read(int x,int y,int[x][y]);
void mat_display(int x, int y,int[x][y]);
void mat_sub(int x,int y,int[x][y],int[x][y],int[x][y]);

int i,j,m,n,p,q;

void main()
{
    //Matrix subtraction can be performed only on square matrices.
    
    printf("\tImplementation of Matrix Subtraction\n");
    
    printf("\n Enter the no. of rows & columns (order) of matrix1: \n");
    scanf("%d %d",&m,&n);
    
    printf("\n Enter the no. of rows & columns (order) of matrix2: \n");
    scanf("%d %d",&p,&q);
    
    int a[m][n],b[p][q],c[m][q];
    
    if((m!=p) || (n!=q))
    {
        printf("\n   --> Inputted matrices are not square\n");
        printf("   --> Matrix subtraction not possible\n");
        printf("\n   --> Exited the program\n");

        exit(1); 
    }
    
    printf("\n   Enter the elements of matrix1: \n");
    mat_read(m,n,a);
                
    printf("\nMatrix1: \n");
    mat_display(m,n,a); 
                
    printf("\n   Enter the elements of matrix2: \n");
    mat_read(m,n,b);
                
    printf("\nMatrix2: \n");
    mat_display(m,n,b);
    
    mat_sub(m,n,a,b,c);
                
    printf("\nResultant matrix after subtraction: \n");
    mat_display(m,n,c);
}

void mat_read(int x,int y,int mat[x][y])
{
    printf("\n");
    
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Element at index(%d,%d): ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void mat_display(int x,int y,int mat[x][y])
{
    printf("\n");
    
    for(i=0;i<x;i++)
    {
        printf("\t");
        for(j=0;j<y;j++)
        {
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
}

void mat_sub(int x,int y,int mat1[x][y],int mat2[x][y],int mat3[x][y])
{
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            mat3[i][j]= mat1[i][j] - mat2[i][j];
        }
    }
}
