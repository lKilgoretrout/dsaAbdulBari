#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK 42

// prompt : displayed to user
// finalSize:  length of returned char*
char* readline(char* prompt, int* finalSize)
{
    printf("%s", prompt);

    char* str = malloc(CHUNK * sizeof(char));
    char c;
    size_t len  = 0;
    size_t size = CHUNK;
    while (EOF != (c=getchar()) && c!='\r' && c!='\n')
    {
        str[len++] = c;
        if (len==size) str = realloc(str, sizeof(char) * (size *= 2));
    }

    str[len] = '\0';
    *finalSize = len;
    return realloc(str, sizeof(char) * len);
}

int main()
{
   int finalSize; 
   char prompt[] = "hello\n"
                   "Welcome to RJ's readline() program\n"
                   "Enter some text and it will print it back out\n"
                   "hello\n\n";
   
   char* input = readline(prompt, &finalSize);

   printf("\nyou typed:\n");
   printf("%s", input);
   printf("\n\nThe length of your input was: %d", finalSize);

}


