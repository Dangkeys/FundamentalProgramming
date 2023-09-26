#include <stdio.h>
int main()
{
    int num[10];
    int odd[10];
    int even[10];
    int counter = 0;
    int oddCounter = 0;
    int evenCounter = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("%d:", i + 1);
        scanf("%d", &num[i]);
        if (num[i] == 0)
            break;
        counter++;
    }
    for (int i = 0; i < counter; i++)
    {
        if (num[i] % 2 == 0)
        {
            even[evenCounter] = num[i];
            evenCounter++;
        }
        else
        {
            odd[oddCounter] = num[i];
            oddCounter++;
        }
    }
    printf("Odd = ");
    for (int i = 0; i < oddCounter; i++)
    {
        printf("%d ", odd[i]);
    }
    printf("\n");
    printf("Even = ");
    for (int i = 0; i < evenCounter; i++)
    {
        printf("%d ", even[i]);
    }
}