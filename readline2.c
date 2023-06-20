#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHONK 42

/* INPUT: char* prompt: string prompt to user
 *        int*  len;    strlen of user input :  passed by ref
 *        char* input;  string to be written to by user
*/
char* readline2(char* prompt, int* len)
{
    printf("%s", prompt);                  
   
    int c;
    int size   = CHONK;
    int length = 0;
    
    char* input = malloc(size * sizeof(char));

    while ( (c=getchar()) != EOF && c!='\n' && c!='\r' )
    {
        input[length++] = c;
        if (length==size)
            input = realloc(input, sizeof(char) * (size *= 2));
        
    }
    
    input[length] = '\0';
    *len = length;
    input = realloc(input, sizeof(char) * length);

    return input;
}

int main()
{
    char prompt[] = "Welcome to RJ's readline 2:  THE REMATCH. Writing this shit again for practice!\n"
                    "Now give me a string, i'll write it out again for you and count how many chars are in it!\n";
    char* input;
    int len;    
    input = readline2(prompt, &len);

    printf("\n\nThe input you provided: \n%s\n", input);
    printf("\nIt had %d chars in it!", len);
}

