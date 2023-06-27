#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// lower case letters only
void duplicateCharsBitwise(char* str, int len)
{
    u_int32_t mask = 0;    // i.e. 'd' is 1 << 3

    for (int i=0; i<len; i++)
    {
        if (mask & (1 << (str[i] - 97)))
            printf("duplicate %c found at position %d\n", str[i], i);
        mask |= (1 << (str[i] - 97));
    }
}

int main()
{
    char* input;
    input = (char *) malloc(420 * sizeof(char));
    int   len;

    printf("gimme an all lowercase word , no punctuation to find duplicates in: ");
    scanf("%s", input);
    len = strlen(input);

    duplicateCharsBitwise(input, len);
}

