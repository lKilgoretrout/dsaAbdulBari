#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct Array
{
    int* A;           // array
    int  size;        // num of elements in A
    int  max;         // largest in in array (natural numbers)
} Array;


// prints number of pairs of ints that add to sum
// **array must be sorted**
int findSumTwoPointer (Array arr, int sum)
{
    int i=0; 
    int j=arr.size-1;
    int hits = 0;

    while (i < j)
    {
        if (arr.A[i] + arr.A[j] == sum)
        {
            hits++;
            printf("\n%d + %d = %d", arr.A[i], arr.A[j], sum);
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }

    }

    return hits;
}

int main()
{
    printf("size of array? ");
    int size = 0;
    scanf("%d", &size);

    printf("max val of array? ");
    int max = 0;
    scanf("%d", &max);

    printf("target sum: ");
    int target = 0;
    scanf("%d", &target);

    srand(time(NULL));

    int *A = (int *) malloc(size * sizeof(int));
    for (int i=0; i<size; i++)
    {
        printf("number %d: " , i);
        scanf("%d", &A[i]);
    }
    

    Array arr = {A, size, max};
    
    int hits = 0;
    hits = findSumTwoPointer(arr, target);
    printf("\nfound %d pairs of ints adding up to %d", hits, target);
   

} 
