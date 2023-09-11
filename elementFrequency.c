#include <stdio.h>
#include <stdbool.h>
const int MAX = 10;
typedef struct
{
  int frequency;
  int number;
} element;
element elements[MAX];
int counter = 0;
int main(void) {
  int num[MAX];
  for (int i = 0; i < MAX; i++)
    {
      scanf("%d", &num[i]);
    }
  for (int i = 0; i < MAX; i++)
    {
      if (i != 0)
      {
        bool isDuplicate = false; 
        for (int j = i - 1; j >= 0; j--)
          {
            if(num[j] == num[i])
            {
              isDuplicate = true;
            }
          }
        if(!isDuplicate)
        {
          counter++;
        }
      } else {
        counter++;
      }
    }
}