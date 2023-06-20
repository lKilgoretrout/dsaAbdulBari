#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct minMax
{
    int min;
    int max;
} minMax;

minMax minMaxOnePass(int *array, int size)
{
    int min = 0;
    int max = 0;

    for (int i=0; i<size; i++)
    {
        if       (array[i] < min) { min = array[i]; }
        else if  (array[i] > max) { max = array[i]; }
    } 

    minMax result = {min, max};

    return result;;
}


int main()
{
    int *a;
    int size;
    int maxInt;

    printf("How big an array you want breh? ");
    scanf("%d", &size);

    printf("and the max int size on that one breh? ");
    scanf("%d", &maxInt);

    a = (int *) malloc(size * sizeof(int));
    srand(time(NULL));

    printf("Your array:\n");
    for (size_t i=0; i<size; i++)
    {
        a[i] = (rand() % maxInt) + 1;
        printf("%d ", a[i]);
    }
    minMax result = minMaxOnePass(a, size);
    
    printf("\nMin: %d, Max: %d", result.min, result.max);
    
    return 0;;
}
