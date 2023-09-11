#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
           if (i % 2 == 0)
           {
            if (j % 2 == 0)
            {
                printf("*");
            } else {
                printf("_");
            }
           } else {
            if (j % 2 == 0)
            {
                printf("_");
            } else {
                printf("*");
            }
           }
        }
        printf("\n");
    }
}
