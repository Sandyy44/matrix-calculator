#include <stdio.h>
//summation function
void sum(float first[10][10], float second[10][10], float result[10][10], int r1, int c1)
{
    for(int m=0; m<r1; m++)
    {
        for(int n=0; n<c1; n++)
        {
            result[m][n]= first[m][n]+second[m][n];
        }
    }
}

//subtraction function
void sub(float first[10][10], float second[10][10], float result[10][10], int r1, int c1)
{
    for(int m=0; m<r1; m++)
    {
        for(int n=0; n<c1; n++)
        {
            result[m][n]= first[m][n]-second[m][n];
        }
    }
}

//Multiplication function
void matrixmultiply(float first[10][10], float second[10][10], float result[10][10], int r1, int c2,int r2 )
{
    int j;
    float sum=0;
    for( int i=0 ; i<r1 ; i++)
    {
        for( int j=0 ; j<c2 ; j++)
        {
            for( int k=0 ; k<r2 ; k++)
            {

                sum+= first [i][k] * second [k][j] ;
            }

            result [i][j]= sum ;
            sum=0;
        }
     }
}

//getting elements from function
void get_element(float array[][10], int r,int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%f", &array[i][j]);
        }
    }
}

//displaying function
void display(float result[10][10], int r1, int c1)
{
    for(int u=0; u< r1; u++)
    {
        for(int y=0; y< c1; y++)
        {
            printf("%.3f\t\t", result[u][y]);
            if (y==c1-1)
            printf("\n");
        }

    }

}


void get_rc_two(int *r1,int *c1, int *r2,int *c2)
{
    printf("Enter the number of rows and columns of the 1st matrix ");
    scanf("%d %d", r1, c1);
    printf("Enter the number of rows and columns of the 2nd matrix ");
    scanf("%d %d", r2, c2);
}

void get_rc_one(int *r,int *c)
{
    printf("Enter the number of rows and columns of the matrix ");
    scanf("%d %d", r, c);
}

//
float det3(float second[10][10])
{
    float determinant=0;
    for(int i = 0; i < 3; i++)
    determinant = determinant + (second[0][i] * (second[1][(i+1)%3] * second[2][(i+2)%3] - second[1][(i+2)%3] * second[2][(i+1)%3]));
    return determinant;
}



void inverse(float second[10][10],float determinant,float inv[10][10])
{
    for(int m = 0; m < 3; m++)
    {
        for(int n = 0; n < 3; n++)
        {
        inv[m][n]=(((second[(n+1)%3][(m+1)%3] * second[(n+2)%3][(m+2)%3]) - (second[(n+1)%3][(m+2)%3] * second[(n+2)%3][(m+1)%3]))/ determinant);
        }
    }
}

void division(float first[10][10],float second[10][10],float inv[10][10],float result2[10][10])
{
    float determinant;
    inverse(second,det3(second),inv);
    matrixmultiply(first,inv, result2, 3, 3,3 );

}



void transpose(float matrix[10][10],float trans[10][10], int r ,int c)
{
    trans[c][r];
    for(int  i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++ )
        {
          trans[i][j]=  matrix[j][i];
        }

    }
}


void divscal(float matrix[10][10], int r,int c, float result[10][10], float scal)
{
    for(int  i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++ )
        {
          result[i][j]=  matrix[i][j]/scal;
        }
}
}

float det2(float second[10][10])
{
    float det;
    det =second[0][0]*second[1][1]-second[1][0]*second[0][1];
    return det;
}


void inverse2(float first[10][10],float inv[10][10])
{
    float mat[10][10];
    mat[0][0]=first[1][1];
    mat[0][1]=-1*first[0][1];
    mat[1][0]=-1*first[1][0];
    mat[1][1]=first[0][0];
    divscal(mat,2,2,inv,det2(first));
}



void division2(float first[10][10],float second[10][10],float inv[10][10],float result2[10][10])
{
    float determinant;
    inverse2(second,inv);
    matrixmultiply(first,inv, result2, 2, 2,2 );

}
