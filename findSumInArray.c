#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array
{
    int* A;
    int size;
} Array;

// input: arr = int[] (array to scan);  sum=target; max=largest in in arr
// scans array and prints the values of elements that add to 'sum'
//
int findSumInArrayHash(Array arr, int sum, int max)
{
   
    int *hash;
    hash = (int *) calloc(max, sizeof(int));
    int hits = 0;

    for (int i=0; i<arr.size-1; i++)
    { 
        if (arr.A[i] <= sum) // if arr element > sum then it can't add up to sum (+ arr bounds index error))
        {
            // index of hash is the value of element, so if arr.A[i] + hash[sum - arr.A[i]] = sum, then you got a winner!
            if (hash[sum - arr.A[i]])
            {
                hits++;  
                printf("\n%d +  %d =  %d",arr.A[i], sum-arr.A[i],  sum);
            }
        }
        hash[arr.A[i]] = arr.A[i];
    }
    return hits;
}

int findSumInArrayTwoPointer(Array arr, int sum)
{
    int hits = 0;
    for (int i=0; i<arr.size-1; i++)
    {
        for (int j=i+1; j<arr.size; j++)
        {
            if (arr.A[i] + arr.A[j] == sum)
            {
                hits++;; 
                printf("\n%d + %d = %d", arr.A[i], arr.A[j], sum);
            }
        }
    }
    return hits;
}

int findSumInSortedArray(Array arr, int sum)
{
    int i=0, hits=0; 
    int j=arr.size-1;
    

    while (i < j)
    {
        if (arr.A[i] + arr.A[j] == sum)
        {   
            hits++;
            printf("%d + %d = %d", arr.A[i], arr.A[j], sum);
            i++; j++;
        }
        else if (arr.A[i] + arr.A[j] > sum)
        {
            i++;
        }
        else 
        {
            j++;
        }
    }
    return hits;
}


int main()
{
    printf("How big an array do you want ?");
    
    int size;
    scanf("%d", &size);

    printf("Max int size for array element ?(-1 for max int size)");
    int max;
    scanf("%d", &max);

    printf("What sum do you want to scan for in the array? " );
    int sum;
    scanf("%d", &sum);


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
    printf("The array: "); 
    for (int x=0; x<size; x++) printf("%d ", arr[x]);
    ///////////////////////////////////////////////////////////

    Array array = { arr, size };
    int hits = 0;
          
    // START TIMING HASH 
    clock_t start, end;
    start = clock();

    hits = findSumInArrayHash(array, sum, max);

    end = clock();   
    
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nfindSumInArrayHash()  took: %f seconds", cpu_time_used);   
    printf("\nfound %d pairs of ints that add to %d\n", hits, sum);
          
    // START TIMING TWO POINTER
    start = clock();
    hits = findSumInArrayTwoPointer(array, sum);
    end = clock();   
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("\nfindSumInArrayTwoPointer()  took: %f seconds", cpu_time_used);   
    printf("\nfound %d pairs of ints that add to %d\n", hits, sum);
     
    // START TIMING FINDSUMINSORTEDARRAY
    start = clock();
    hits = findSumInSortedArray(array, sum);
    end = clock();   
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("\nfindSumInSortedArray() took %f seconds", cpu_time_used);      
    printf("\nfound %d pairs of ints that add to %d\n", hits, sum);
}

