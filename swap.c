#include <stdio.h>
void swap(int *a, int *b);
int main()
{
    int num[2];
    for (int i = 0; i < 2; i ++)
        scanf("%d",&num[i]);
    printf("%d %d\n",num[0], num[1]);
    swap(&num[0], &num[1]);
    printf("%d %d\n",num[0], num[1]);
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b  = *a;
    *a = tmp;
}