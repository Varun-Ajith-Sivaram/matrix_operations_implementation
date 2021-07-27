#include<stdio.h>
#include<stdlib.h>

void mat_read(int x,int y,int[x][y]);
void mat_display(int x, int y,int[x][y]);
void mat_mult(int w,int x,int y,int z,int[w][x],int[y][z],int[w][z]);

int i,j,k,m,n,p,q;

void main()
{
    /*Matrix multiplication can be performed only if the no. of columns of matrix1
    is equal to the no. of rows of matrix2*/
    
    printf("\tImplementation of Matrix Multiplication\n");
    
    printf("\n Enter the no. of rows & columns (order) of matrix1: \n");
    scanf("%d %d",&m,&n);
    
    printf("\n Enter the no. of rows & columns (order) of matrix2: \n");
    scanf("%d %d",&p,&q);
    
    int a[m][n],b[p][q],c[m][q];
    
    if(n!=p)
    {
        printf("\n   --> No.of columns of matrix1 is not equal to no. of rows of matrix2\n");
        printf("   --> Matrix multiplication not possible\n");
        printf("\n   --> Exited the program\n");
    
        exit(1);
    }
                
    printf("\n   Enter the elements of matrix1: \n");
    mat_read(m,n,a);
                
    printf("\nMatrix1: \n");
    mat_display(m,n,a); 
                
    printf("\n   Enter the elements of matrix2: \n");
    mat_read(p,q,b);
                
    printf("\nMatrix2: \n");
    mat_display(p,q,b);
    
    mat_mult(m,n,p,q,a,b,c);
                
    printf("\nResultant matrix after multiplication: \n");
    mat_display(m,q,c);
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

void mat_mult(int w,int x,int y,int z,int mat1[w][x],int mat2[y][z],int mat3[w][z])
{
    for(i=0;i<w;i++)
    {
        for(j=0;j<z;j++)
        {   
            mat3[i][j]=0;
            
            for(k=0;k<x;k++)
            {
                mat3[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
}
