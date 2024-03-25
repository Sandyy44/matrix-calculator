#include <stdio.h>
void sum(float first[10][10], float second[10][10], float result[10][10], int r1, int c1); //summation
void sub(float first[10][10], float second[10][10], float result[10][10], int r1, int c1); //subtraction
void display(float result[10][10], int r1, int c1); //displaying the matrix
void matrixmultiply(float first[10][10], float second[10][10], float result[10][10], int r1,int c2, int r2); //multiplication
void get_element(float array[][10], int r,int c); //getting the elements of the matrix
void get_rc_two(int *r1,int *c1,int *r2,int *c2); //getting number of rows and column of two matrices, to be used in (sum)(sub)(multiply)(division)
void get_rc_one(int *r,int *c); //getting number of row and column of just one matrix, to be used in (transpose)(inverse)(determinant)
float det3(float second[10][10]); //find the determinant of 3x3 matrix
void inverse(float second[10][10],float determinant,float inv[10][10]); //finding the inverse of 3x3 matrix
void division(float first[10][10],float second[10][10],float inv[10][10],float result2[10][10]); //finding the division of 3x3 matrix
void transpose(float matrix[10][10],float trans[10][10], int r ,int c); //transpose a matrix
void divscal(float matrix[10][10], int r,int c, float result[10][10], float scal); //dividing a matrix by a scalar
float det2(float second[10][10]); //finding determinant of 2x2 matrix
void inverse2(float first[10][10],float inv[10][10]); //finding inverse of 2x2 matrix
void division2(float first[10][10],float second[10][10],float inv[10][10],float result2[10][10]); //finding the division of 2x2 matrix
