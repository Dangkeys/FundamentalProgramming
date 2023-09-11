#include<stdio.h>
#include<ctype.h>
#include<string.h>
int sum = 0;
int main()
{
    char str[100];
    scanf("%s", str);
    
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        char alphabet = str[i];
        if (isdigit(alphabet))
        {
            while(isdigit(str[i]))
            {
                sum = sum * 10 + (str[i] - '0');
                i++;
            }
            for (int j = 0; j < sum; j++)
            {
                printf("%c", str[i]);
            }
            sum = 0;
        } else {
            printf("%c",alphabet);
        }

    }
}