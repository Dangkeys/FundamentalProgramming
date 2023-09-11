#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char word[256];
    scanf("%s", word);
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            printf("%c", word[i]);
        }
    }
}