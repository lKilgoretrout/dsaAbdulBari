#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix 
{
    int* A;    // element only in matrix (A[i][j]) if i==j
    int  size;
} Matrix;

void Set(Matrix *m, int i, int j, int x) { if (i==j) m->A[i-1]=x; }
int  Get(Matrix *m, int i, int j)        { return (i==j) ? m->A[i-1] : -1; }

void Display(Matrix *m)
{
    for (int i=0; i<m->size; i++)
    {
        printf("\n");
        for (int j=0; j<m->size; j++)
        {
            if   (i==j) printf("%d ", m->A[i]);
            else        printf("0 ");
        }
    }
}

int main()
{
    printf("how big you want your 'diagonal matrix' y0 ?: ");
    
    int size;
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));
    printf("aye y0, now gimme %d numbahz fo dat shit: ", size);
    for (int i=0; i<size; i++)
    {
        printf("numbah %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    Matrix m = {arr, size};
    for (int i=1; i<=size; i++)
        Set(&m, i, i, arr[i-1]);

    printf("Y0 matrix dawg!:\n "); 
    Display(&m);
    
    return 0;
}
