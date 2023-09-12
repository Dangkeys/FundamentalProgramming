#include<stdio.h>
int main()
{
    int max = 0;
    int min = 100;
    int result = 0;
    int number[4];
    for (int i = 0; i < 4; i++)
        scanf("%d", &number[i]);
    for (int i = 0; i < 4; i++)
    {
        if (number[i] < min) min = number[i];
        if (number[i] > max) max = number[i];
    }
    for (int i = 0; i < 4; i++)
        if (!(number[i] == min || number[i] == max)) result += number[i];
    printf("Max: %d, Min: %d\n", max, min);
    printf("%d", result);
}
//6 9 3 8// 2 9 7 3 
