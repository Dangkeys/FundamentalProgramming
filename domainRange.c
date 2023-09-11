#include<stdio.h>
int function(int num);
int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        if (function(i) == i)
        {
            printf("%d\n", i);
        }
    }
}
int function(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}