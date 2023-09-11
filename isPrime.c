#include <stdio.h>
#include <math.h>
void isPrime(int number);
int main()
{
    int num;
    scanf("%d",&num);
    isPrime(num);
}
void isPrime(int number)
{
    if (number <= 1)
    {
        printf("Not Prime Number");
        return;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            printf("Not Prime Number");
            return;
        }
    }
    printf("Prime Number");
}