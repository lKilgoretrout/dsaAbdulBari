// scans a sorted array and prints the duplicates. does not print repeated duplicates

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Array
{  
    int* A;
    int size;
};

void findDuplicates (struct Array arr)
{
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

void countDuplicates (struct Array arr)
{
    int count = 0, j=0;
    for (int i=0; i<arr.size; i++)
    {
	    if (arr.A[i]==arr.A[i+1])
        {
            j = i+1;
            while (arr.A[j]==arr.A[i])
                j++;
          
            printf("\n'%d' was found %d times ", arr.A[i], j-i);
            i = j-1;
        }
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

    findDuplicates(arr);
    countDuplicates(arr);

    return 0;
}	     

