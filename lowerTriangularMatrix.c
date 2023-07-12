#include <stdio.h>
#include <stdlib.h>

/* lower triangluar matrix:    rows and columns traditionally start with 1 indexing
 *    1    2    3    4    5
 *  1 a11  0    0    0    0
 *  2 a21  a22  0    0    0
 *  3 a31  a32  a33  0    0
 *  4 a41  a42  a43  a44  0
 *  5 a51  a52  a53  a54  a55
 *
 * number of non-zero elements: (n(n+1))/ 2  (sum of n natural numbers) 
 * number of zero     elements: n^2 - ((n(n+1))/2)
 *
 * row-major array representation:
 *     A = [ a11  a21  a22  a31  a32 a33 a41 a42 a43 a44 a51 a52 a53 a54 a55]
 *   row =   1    2    2    3    3   3   4   4   4   4   5   5   5   5   5        
 * 
 * for 1 based matrix index formula into 0-based index in Array:
 * M[i][j] --> A[i][j] : 
 *     M[row, column] -> A[i, j] = ( (i(i-1))/2 ) + j - 1
 *
 * column-major array representation:
 *     A = [ a11  a21  a32  a41  a51 a22 a32 a42 a52 a33 a43 a53 a44 a54 a55]
 *   row =   1    1    1    1    1   3   4   4   4   4   5   5   5   5   5    
 *  A[i] =   0    1    2    3    4   5   6   7   8   9   10  11  12  13  14
 *  M[row, column] -> A[i, j]:
 *       m[4][2] = a[7]  = [5] + 2
 *       m[4][3] = a[10] = [5+4] + 1
 *       m[5][5] = a[14] = [5+4+3+2] + 0
 */

typedef struct LTM
{
    int* A;    // array representation of matrix
    int rows;  // number of rows in the matrix 
} LTM;

void Display(LTM ltm)
{
    int i, j, index;
    for (i=1; i<ltm.rows+1; i++)
    {
        for (j=1; j<ltm.rows+1; j++)
        {
            if (i>=j)
            {
                index = ( (i * (i-1)) / 2 ) + j - 1;
                printf("%d ", ltm.A[index]);
            }
            else
            {
                printf("0 ");
            }
        }

        printf("\n");
    }
}

int main()
{
    printf("aye y0 , how many rows you want on your LOWER TRIANGULAR MATRIX huh? ");

    int rows = 0;
    scanf("%d", &rows);
    int numElements = ( rows * (rows+1)) / 2;
    int* A = (int *) malloc(numElements * sizeof(int));
    int num = 0;
    int i;
    for (i=0; i<numElements; i++)
    {
       printf("\naye y0, gimme element %d: ", i+1);
       scanf("%d", &num);
       A[i] = num;
    }

    LTM ltm = { A, rows };

    printf("here's y0 matrix y0: \n");
    Display(ltm);
    
    return 0;
}
    
