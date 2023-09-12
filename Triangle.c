#include <stdio.h>
int main()
{
    int max = 0;
    int squareSum = 0;
    int number[3];
    for (int i = 0; i < 3; i++)
        scanf("%d",&number[i]);
    for (int i = 0; i < 3; i++)
        if(number[i] > max) max = number[i];
    for (int i = 0; i < 3; i++)
        if(number[i] != max) squareSum += number[i] * number[i];
    printf("squareSum: %d, MaxSquare: %d\n", squareSum, max * max);
    squareSum == max * max ? printf("Yes") : printf("No");
}