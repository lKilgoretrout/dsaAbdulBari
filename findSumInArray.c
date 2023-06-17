#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array
{
    int* A;
    int size;
} Array;

// input: Array struct (int[]);  sum (int)
// scans array and prints the values of elements that add to 'sum'
void findSumInArray(Array arr, int sum)
{
    int *hash;
    hash = (int *) calloc(arr.size, sizeof(int));

    for (int i=0; i<arr.size-1; i++)
    { 
        if (sum - arr.A[i] >= 0)
        {
            // index of hash is the value of element, so if arr.A[i] + hash[sum - arr.A[i]] = sum, then you got a winner!
            if (hash[sum - arr.A[i]])
                printf("\n%d +  %d =  %d",arr.A[i], sum-arr.A[i],  sum);
        }
        hash[arr.A[i]] = arr.A[i];
    }
}


int main()
{
    clock_t start, end;
    printf("How big an array do you want ?");
    
    int size;
    scanf("%d", &size);

    printf("Max int size for array element ?(-1 for max int size)");
    int max;
    scanf("%d", &max);

    printf("What sum do you want to scan for in the array? " );
    int sum;
    scanf("%d", &sum);

    // START TIMING
    start = clock();

    int *arr;
    arr = (int *) malloc (size * sizeof(int));
    
      
    srand(time(NULL));
    if (max==-1)
    {
        for (int i=0; i<size; i++)
            arr[i] = rand();    
    }
    else
    {
        for (int i=0; i<size; i++)
            arr[i] = (rand() % max);
    }
    
    ///////////////////////////////////////////////////////////
    //  for (int x=0; x<size; x++) printf("%d ", arr[x]);
    ///////////////////////////////////////////////////////////

    Array array = { arr, size };
    
    findSumInArray(array, sum);

    end = clock();   
    
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nThat all took: %f seconds", cpu_time_used);   
    
}

