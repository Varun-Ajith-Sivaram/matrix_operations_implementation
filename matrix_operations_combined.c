#include<stdio.h>
#include<stdlib.h>

void mat_read(int x,int y,int[x][y]);
void mat_display(int x, int y,int[x][y]);
void mat_add(int x,int y,int[x][y],int[x][y],int[x][y]);
void mat_sub(int x,int y,int[x][y],int[x][y],int[x][y]);
void mat_mult(int w,int x,int y,int z,int[w][x],int[y][z],int[w][z]);

int i,j,k,m,n,p,q,ch;

void main()
{
    /*Matrix addition and subtraction can only be performed on square matrices.
    Matrix multiplication can be performed only if the no. of columns of matrix1
    is equal to the no. of rows of matrix2*/
    
    printf("\tImplementation of Matrix Operations\n");
    
    printf("\n Enter the no. of rows & columns (order) of matrix1: \n");
    scanf("%d %d",&m,&n);
    
    printf("\n Enter the no. of rows & columns (order) of matrix2: \n");
    scanf("%d %d",&p,&q);
    
    int a[m][n],b[p][q],c[m][q];
    
    do{
        printf("\n Operations Available: \n\n");
        printf("  1.Matrix Addition\n");
        printf("  2.Matrix Subtraction\n");
        printf("  3.Matrix Multiplication\n");
        printf("  4.Exit\n");
        
        printf("\n   Enter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            {
                if((m!=p) || (n!=q))
                {
                    printf("\n   --> Inputted matrices are not square\n");
                    printf("   --> Matrix addition not possible\n");
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
                   
                mat_add(m,n,a,b,c);
                
                printf("\nResultant matrix after addition: \n");
                mat_display(m,n,c);
                
                exit(0);
                }

            break;
            
            case 2:
            {
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
                
                exit(0);
                }
    
            break;
            
            case 3:
            {
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
                
                exit(0);
                }
        
            break;
            
            case 4:
            {
                printf("\n   --> Exited the program\n");
                exit(0);
            }
                
            default:
                printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
        
    }while(ch!=4);  
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

void mat_add(int x,int y,int mat1[x][y],int mat2[x][y],int mat3[x][y])
{
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            mat3[i][j]= mat1[i][j] + mat2[i][j];
        }
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
