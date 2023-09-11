#include <stdio.h>
#include <ctype.h>
#define MAX 256
int main()
{
    char *ptr;
    char input[MAX];
    scanf("%s",input);
    ptr = input;
    while (*ptr != '\0')
    {
        if (isalpha(*ptr))
        {
            if (isupper(*ptr))
                *ptr = tolower(*ptr);
            else
                *ptr = toupper(*ptr);
            printf("%c",*ptr);
        }
        ptr++;    
    }
}