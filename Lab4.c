#include<stdio.h>
#include<ctype.h>
#include<string.h>
int digitAmount(char num[], int startAt);
const int MAX = 100;
int main()
{
    char word[MAX];
    scanf("%s", word);
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char alpha = word[i];
        if (isalpha(alpha))
        {
            printf("%c", alpha);
        } else if (isdigit(alpha))
        {
            int sum = 0;
            int amountDigit = digitAmount(word, i);
            //printf("%d", amountDigit);
            for (int j = 0; j < amountDigit; i++)
            {
                sum = sum * 10 + (word[j + i] - '0');
            }
            i += amountDigit;
            for (int j = 0; j < sum; j++)
            {
                printf("%d", word[i]);
            }
        }
    }
}
//this digitAmount return homany digit of number
int digitAmount(char num[], int startAt)
{
    int start = 0;
    while(isdigit(num[startAt + start]))
    {
        start++;
    }
    return start;
}