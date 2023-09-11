#include <stdio.h>
void star(int n);
int main()
{
    int n;
    scanf("%d", &n);
    star(n);
}
void star(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}