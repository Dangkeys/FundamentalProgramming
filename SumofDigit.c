#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX = 100;
int sumOfDigit(char str[]);
int main()
{
    char number[MAX];
    scanf("%s", number);
    int answer = sumOfDigit(number);
    if (answer == -1)
    {
        printf("Invalid");
        return 1;
    }
    printf("%d", answer);
}
int sumOfDigit(char str[])
{
    int result = str[0] - '0';
    while (strlen(str) != 1)
    {
        result = 0;
        for (int i = 0, n = strlen(str); i < n; i++)
        {
            //change str[i] to int by minus '0'
            //add it to the totalSum
            //then change totalSum to string
            //str = totalSum
            int num = str[i] - '0';
            if (num >= 0 && num <= 9)
            {
                result += str[i] - '0';
            } else 
            {
                return -1;
            }
            

        }
        sprintf(str, "%d", result);
    }
    return result;
}