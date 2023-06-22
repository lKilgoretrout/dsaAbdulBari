#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toggleCase(char* str)
{
    for (int i=0; str[i]!='\0'; i++)
    {
        // capital letters
        if (str[i]>=65 && str[i] <=90) 
        {
            str[i] += 32;
        }
        else if (str[i]>=97 && str[i]<=122)
        {
            str[i] -= 32;
        }
    }
}

int main()
{
    printf("now gimme an input breh:\n");

    char* input = malloc(420 * sizeof(char));
    fgets(input, 420, stdin);
    int size = strlen(input);
    input = realloc(input, size * sizeof(char));

    printf("\nyo' input toggled an' shit: \n");
    toggleCase(input);
    printf("%s", input);

}
