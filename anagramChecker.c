#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// works for words with chars a-z and A-Z ONLY
void anagramChecker(char* str1, char* str2)
{
   
    // hashtable for counting instances of letters
    char* hash = (char *) calloc(26, sizeof(char));
    char* hash2= (char *) calloc(26, sizeof(char));
   
    // count instances of chars in st1 and st2
    int i=0, j=0;
    while (str1[i]!='\0')
    {
        if (str1[i]<97)       // A-Z -> 65 - 90
          hash[str1[i] - 65] += 1;
        if (str1[i]>=97)
          hash[str1[i] - 97] += 1;
      i++;
    }
    while (str2[j]!='\0')
    {
        if (str2[j]<97)
          hash2[str2[j] - 65] += 1;
        if (str2[j]>=97)
          hash2[str2[j] -97] += 1;
      j++;
    }

    // if str1 and str2 different lengths they can't be anagrams !
    if (i!=j)
    {
        printf("\nNOT ANAGRAMS!");
        free(hash);
        return;
    }

    // count occurrences of chars in each str
    char notAnagram = 0;
    for (i=0; i<26; i++)
        if (hash[i]!=hash2[i]) notAnagram = 1; 

    if (notAnagram) 
    { 
      free(hash);
      printf("\nNOT ANAGRAMS!");
    }

    printf("\nTHEY ARE ANAGRAMS! YOU ARE SO SMART!");
}


int main()
{
    printf("HELLO! welcome to the anagram checker\n"); 
    printf("gimme word one (letters ONLY): ");
    char* input1 = (char *) malloc(42 * sizeof(char));
    scanf("%s", input1);

    printf("\nGREAT JOB!  now gimme another word (LETTERS ONLY): ");
    char* input2 = (char *) malloc(42 * sizeof(char));
    scanf("%s", input2);

    printf("\nCOMPUTING !  BEEP BOOP BEEP!");
    sleep(1);
    printf("\nBEEP BOOP BEEP BOOP!\n\n");
    sleep(1);

    anagramChecker(input1, input2);

    printf("\n\nTHANKS FOR PLAYING!");

    free(input1);
    free(input2);
        
}
