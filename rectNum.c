#include <stdio.h>
#include <math.h>
void rectNum(int size, int middleNumber);
int main(void) {
  int m, n;
  scanf("%d", &m);
  scanf("%d", &n);
  rectNum(m, n);
}
void rectNum(int size, int middleNumber)
{
    int realSize = size * 2 + 1;
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < realSize; j++)
        {
            if (j < i)
            {
                printf("%d", (abs(i - size) + abs(i - j) + middleNumber) % 10);
            }else if (j > realSize - 1 - i)
            {
                printf("%d", (abs(j + i) - abs(realSize - abs(i - size)) + 1 + middleNumber) % 10);
            }else {
                printf("%d", (abs(i - size) + middleNumber) % 10);
            }
        }
        printf("\n");
    }
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < realSize; j++)
        {
            if (j < i)
            {
                printf("%d", (abs(i - size) + abs(i - j) + middleNumber) % 10);
            }else if (j > realSize - 1 - i)
            {
                printf("%d", (abs(j + i) - abs(realSize - abs(i - size)) + 1 + middleNumber) % 10);
            }else {
                printf("%d", (abs(i - size) + middleNumber) % 10);
            }
        }
        printf("\n");
    }
}