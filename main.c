#include <stdio.h>
#include <stdlib.h>
#include"matrix.h"




int main()
{

    int r1, c1, r2, c2, order;;
    float first[10][10], second[10][10], result2[10][10], inv[10][10];
    float determinant;
    printf("\t\t\t-----MATRIX CALCULATOR-----\n\n");
    //choosing the operation
    char op;
    printf("\nPlease choose the operation from down below\n\n+\t(summation)\n-\t(subtraction)\n*\t(multiplication)\n/\t(division)\n^\t(transpose)\nd\t(determinant)\ni\t(inverse)\ns\t(scalar division) \n\n");
    scanf("%c",&op);

    if(op=='+'||op=='-' ||op=='*')
    {
        get_rc_two(&r1,&c1,&r2,&c2);
        if(op=='+')
        {
            if(r1==r2&&c1==c2) //testing if we can add or subtract the matrices
            {
                //getting the matrices from the user
                printf("\nEnter the 1st matrix\n");
                get_element(first,r1,c1);
                printf("\nEnter the 2nd matrix\n");
                get_element(second,r2,c2);
                sum(first, second, result2, r1, c1);
                printf("\nThe summation of the matrices is\n");
                display(result2,r1,c1);
            }

            else
            {
                printf("\nThese matrices can not be added\n");
            }
        }

        else if(op=='-')
        {
            if(r1==r2&&c1==c2) //testing if we can add or subtract the matrices
            {
                printf("\nEnter the 1st matrix\n");
                get_element(first,r1,c1);
                printf("\nEnter the 2nd matrix\n");
                get_element(second,r2,c2);
                printf("\nThe subtraction of the matrices is\n");
                sub(first,second,result2,r1,c1);
                display(result2, r1,c1);
            }
        else
        {
            printf("\nThese matrices can not be subtracted\n");
        }

        }

        else if(op=='*')
        {
            if(c1 == r2)
            {
                //getting the matrices from the user
                printf("\nEnter the 1st matrix\n");
                get_element(first,r1,c1);
                printf("\nEnter the 2nd matrix\n");
                get_element(second,r2,c2);

                //Multiplication operation
                matrixmultiply(first, second, result2, r1, c2,r2);
                printf("\nThe multiplication of the matrices is\n");
                display(result2,r1,c2);
            }
            else
            {
                printf("\nSorry!! We cannot multiply the first and second matrices\n");
            }
        }
    }

    else if(op=='/')
    {
        printf("\nChoose the order of the matrix\n2 (for 2x2 matrix)\n3 (for 3x3 matrix)\n");
        scanf("%d",&order);
        if(order==3)
        {
            printf("\nPlease enter the 1st matrix\n");
            get_element(first, 3, 3);
            printf("\nPlease enter the 2nd matrix\n");
            get_element(second, 3, 3);
            if(det3(second)==0)
            {
                printf("\nSORRY!! We can not divide these two matrices, We can not find the inverse of the second matrix because its determinant = 0.0\n");
            }
            else
            {
            //division operation
            division(first,second,inv,result2);
            // display the result
            printf("\nThe division of the two entered matrices is \n\n");
            display(result2, 3, 3);
            }
        }
        else if(order==2)
        {

            printf("\nPlease enter the 1st matrix\n");
            get_element(first,2,2);
            printf("\nPlease enter the 2nd matrix\n");
            get_element(second, 2, 2);
            if(det2(second)==0)
            {
                  printf("\nSORRY!! We can not divide these two matrices, We cannot find the inverse of the second matrix because its determinant = 0.0\n");
            }
            else
            {
            division2(first,second,inv,result2);
            printf("\nThe division of the two entered matrices is \n\n");
            display(result2, 2, 2);
            }
        }
        else
        {
            printf("\nPlease enter a valid order \n");
        }
    }

    else if(op=='d')
    {
        printf("\nChoose the order of the matrix\n2 (for 2x2 matrix)\n3 (for 3x3 matrix)\n");
        scanf("%d",&order);
        if(order==3)
        {
            printf("\nPlease enter the matrix\n");
            get_element(first,3,3);
            determinant=det3(first);
            printf("\nThe determinant of the entered matrix = %.3f\n\n",determinant);
        }
        else if(order==2)
        {
            printf("\nPlease enter the matrix\n");
            get_element(first,2,2);
            determinant=det2(first);
            printf("\nThe determinant of the entered matrix = %.3f\n\n",determinant);
        }
        else
        {
            printf("\nPlease enter a valid order \n");
        }
    }

    else if(op=='i')
    {
        printf("\nChoose the order of the matrix\n2 (for 2x2 matrix)\n3 (for 3x3 matrix)\n");
        scanf("%d",&order);
        if(order==3)
        {
            printf("\nPlease enter the matrix\n");
            get_element(first,3,3);
            determinant=det3(first);
            if(determinant==0)
            {
                printf("\nSORRY!! We cannot find the inverse of the matrix because its determinant = 0.0\n");
            }
            else
            {
            inverse(first,determinant,inv);
            printf("\nThe inverse of the entered matrix is\n");
            display(inv,3,3);
            }
        }
        else if(order==2)
        {
            printf("\nPlease enter the matrix\n");
            get_element(first,2,2);
            if(det2(first)==0)
            {
                printf("\nSORRY!! We cannot find the inverse of the matrix because its determinant = 0.0\n");
            }
            else
            {
            inverse2(first,inv);
            printf("\nThe inverse of the entered matrix is\n");
            display(inv,2,2);
            }
        }
        else
        {
            printf("\nPlease enter a valid order \n");
        }
    }

    else if(op=='^')
        {

            //Defining matrix rows and elements.
            get_rc_one(&r1,&c1);
           float matrix[r1][c1];
            float trans[c1][r1];
            //Receiving the matrix from the user.
            printf("please enter the matrix elements\n");
            get_element(matrix,r1,c1);
            //Defining the matrix received.
            printf("\nThe matrix is: \n");
            display(matrix,r1,c1);
            //Printing the transpose matrix.
            printf("\nThe transposed matrix is \n");
            transpose(matrix,trans, r1,c1);
            display(trans,c1,r1);
    }

    else if(op=='s')
    {
        float scal;
        get_rc_one(&r1,&c1);
        printf("\nplease enter the matrix elements\n");
        get_element(first,r1,c1);
        printf("\nplease enter the scaler you want the matrix be divided by \n");
        scanf("%f",&scal);
        if(scal==0)
        {
            printf("\nSORRY!! You are not allowed to divide by zero, It's infinity\n");
        }
        else
        {
        divscal(first,r1,c1,result2,scal);
        printf("\nThe result matrix is\n");
        display(result2,r1,c1);
        }
    }


    else
    {
        printf("\nPlease choose a valid operation\n");
    }
}
