#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define INT_MAX 2147483647
#define WARPEACE_LEN 3359372
#define TEST_FILE_LEN 52

   
// returns a reversed copy of input
char* reverseString1(char* str, int size)
{
    char* rev;
    rev = (char *) malloc(size * sizeof(char));

    for (int i=0, j=size-1; i<size && j>=0; i++, j--)
        rev[i] = str[j];
    
    rev[size] = '\0';       // because fgets keeps the '\n'    
    return rev;
}

// reverse string in place using pointers
void reverseString2(char* str, int size)
{
    char* end = str + size -1;
    char* beg = str;
    char  tmp;

    while (beg < end)
    {
        tmp = *end;
        *end = *beg;
        *beg = tmp;
        beg++;
        end--;
    }
}

int main()
{
    /*
    int size;
    char* str;
    char* rev;

    printf("gimme a string yo: ");
    scanf("%s", str);

    size = strlen(str);

   
    reverseString2(str, size);
    printf("\nyo new string dawg: \n");
    printf("%s", str);

    int revLength = strlen(str);
    printf("\nrev length: %d", revLength);
    */
    
    FILE* fptr;         
    clock_t start, end;
    double elapsed;

    printf("\nreading a file and reversing it...\n");
    fptr = fopen("WarAndPeaceTolstoy.txt", "r"); 
    fseek(fptr, 0L, SEEK_END);
    size_t sz = ftell(fptr);
    rewind(fptr);   
    char* testfile;
    testfile = (char *) malloc((sz+1) * sizeof(char)); //sz+1:  dat '\0' though...
    size_t newLen = fread(testfile, sizeof(char), sz, fptr); 
         
    printf("\n%zu characters read\n", newLen);
    
    //printf("%s\n", testfile);
   
    // REVERSE STRING 1 (array copy)
    start = clock();
    char* reversed = reverseString1(testfile, sz);
    end = clock();
    elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed for reversing War and Peace:  reverseString1() (two array):%lf\n", elapsed);
   
    char ch;
    char* ptr = reversed;
    for (int i=0; i<100; i++)
    {  
        ch = *ptr;
        printf("%c", ch);
        ptr++;
    }  
     
    // REVERSE STRING 2 (two pointers))
    start = clock();
    reverseString2(reversed, sz);
    end = clock();
    elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed for reversing War and Peace:  reverseString2 (two pointer):%lf\n", elapsed);
    
    ptr = &reversed[0];
    for (int i=0; i<100; i++)
    {  
        ch = *ptr;
        printf("%c", ch);
        ptr++;
    }  
    fclose(fptr);
    
}
