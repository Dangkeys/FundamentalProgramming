#include <stdio.h>
#define MAX 256
int main()
{
    char text[MAX], *ptr1, *ptr2;
    scanf ("%s", text);
    ptr1 = text;
    ptr2 =  ptr1;
    while (*ptr1 != '\0')
    {
        ptr1++;
    }
    ptr1--;
    while(*ptr2 != '\0')
    {
        if(*ptr1 != *ptr2)
        {
            printf("Not Palindrome");
            return 0;
        }
        ptr1--;
        ptr2++;
    }
    printf("Palindrome");
}