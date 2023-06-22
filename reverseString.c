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

int main()
{
    // int size;
    // char* str;

    //printf("gimme a string yo: ");
    //scanf("%s", str);

    //size = strlen(str);

    /*
    char* rev = reverseString1(str, size);
    printf("\nyo new string dawg: \n");
    printf("%s", rev);

    int revLength = strlen(rev);
    printf("rev length: %d", revLength);
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
   
    start = clock();
    char* reversed = reverseString1(testfile, sz);
    end = clock();
    elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    
    printf("Time elapsed for reversing War and Peace:  reverseString1() (two array):%lf\n", elapsed);
    
    //int revLen = strlen(reversed);
    //printf("\nrevLen: %d", revLen);

   // for (int i=0; i<=sz+1; i++)
   //     printf("%c", reversed[i]);

    // printf("%s", reversed);
    fclose(fptr);
}
