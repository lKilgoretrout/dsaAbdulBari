// scans a sorted array and prints the duplicates. does not print repeated duplicates

#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Array
{  
    int* A;
    int size;
};

// print out duplicates in sorted int array
void findDuplicates (struct Array arr)
{
    printf("ENTERED findDuplicates()");
    int lastDuplicate = -1;
    for (int i=0; i<arr.size; i++)
    {
        if (arr.A[i]==arr.A[i+1] && arr.A[i] != lastDuplicate)
        {
            printf("duplicate '%d' found at index %d\n", arr.A[i], i);
	    lastDuplicate = arr.A[i];
	}
	else if (arr.A[i]==arr.A[i+1])
	{
	    lastDuplicate = arr.A[i];
	}
    }
}

// print count of duplicates in sorted int array
void countDuplicates (struct Array arr)
{
    printf("entered countDuplicates()");
    int count = 0, j=0;
    for (int i=0; i<arr.size; i++)
    {
	    if (arr.A[i]==arr.A[i+1])
        {
            j = i+1;
            while (arr.A[j]==arr.A[i]) j++;
          
            printf("\n'%d' was found %d times ", arr.A[i], j-i);
            i = j-1;
        }
    }
}

void countDuplicatesSorted (struct Array *arr)
{
    int count;
    int i=0; int j=1;
    for (i=0; i<arr->size-1; i++)
    {
        count = 1;
        if (arr->A[i] != -1)
        { 
            for (j=i+1; j<arr->size; j++)
            {   
                if (arr->A[i]==arr->A[j])
                {   
                    count++;
                    arr->A[j] = -1;
                }
            }
        }   
        if (count != 1) 
            printf("\n%d was found %d times !", arr->A[i], count);
    }
}
                
int main()
{    

    // create user defined int array
    int size;
    printf("Set size of array: ");
    scanf("%d", &size);

    printf("enter %d natural numbers...\n ", size);
    
    int* A = (int *) malloc(size * sizeof(int));
    for (int i=0; i<size; i++)
    {
	    printf("\nnumber %d: ", i+1);
	    int val = -1;      
        scanf("%d", &val);
	    A[i] = val; 
    }

    struct Array arr = { A, size };
    
    printf("your array: ");
    for (int i=0; i<size; i++) printf(" %d", A[i]);
        
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    printf("\nfindDUplicates(arr): ");
    findDuplicates(arr);

    printf("\ncountDuplicates(arr): ");
    countDuplicates(arr);

    printf("\ncountDuplicatesSorted(&arr): ");
    countDuplicatesSorted(&arr);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nThat all took: %f seconds", cpu_time_used);
    return 0;
}	     

