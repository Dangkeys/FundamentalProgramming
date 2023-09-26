#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    printf("Enter you number: ");
    scanf("%d", &num);

    int halfNum = ceil((float)num / 2) - 1;
    printf("%d\n", halfNum);
    for (int i = 0; i < halfNum; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == 0 || j == 0 || i == j || i + j == num - 1 || j == num - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    if (num % 2 == 1)
    {
        for (int j = 0; j < num; j++)
        {
            if (j == 0 || j == num - 1 || j == halfNum)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (j == 0 || j == num - 1 || j == halfNum || j == halfNum + 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    for (int i = halfNum - 1; i >= 0 ; i--)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == 0 || j == 0 || i == j || i + j == num - 1 || j == num - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}