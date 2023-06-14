// scans a sorted array and prints the duplicates. does not print repeated duplicates

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Array
{  
    int* A;
    int size;
}

void findDuplicates (struct Array arr)
{
    int lastDuplicate = -1;
    for (int i=0; i<arr.size; i++)
    {
        if (arr->A[i]==arr->[i+1] && arr->[i] != lastDuplicate)
        {
            printf("duplicate '%d' found at index %d", arr->A[i], i);
	    lastDuplicate = arr->A[i];
	}
	else if (arr->A[i]==arr->[i+1])
	{
	    lastDuplicate = arr->A[i];
	}
    }
}

int Main()
{
    // create user defined int array
    int size;
    print("Set size of array: ");
    scanf("%d", &size);

    printf("enter %d natural numbers: ", size);
    
    int* A = (int *) malloc(size * sizeof(int));
    for (int i=0; i<size; i++)
    {
	printf("number %d: ", i+1);
	int val = -1;      
        scanf("%d", &val);
	*A[i] = val; 
    }

    struct Array arr = { A, size };

    findDuplicates(arr);
}	     

