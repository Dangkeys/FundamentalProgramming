/*
  เขียนโปรแกรมรับ input เป็นชุดตัวเลขเรียงลำดับจากน้อยไปมา 2 ชุด
แล้วแสดงผลเป็นชุดตัวเลขที่เรียงลำดับจากน้อยไปมาก ของตัวเลขภายใน input ทั้งสองชุด

input :
3 8 14 23 56
1 2 9 18 22 89
output :
1 2 3 8 9 14 18 22 23 56 89
  */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
const int MAX = 100;
int main(void) {
  char text1[MAX];
  char text2[MAX];
  int array1[MAX];
  int array2[MAX];
  int tmp[MAX];
  int array1Counter = 0;
  int array2Counter = 0;
  int sum = 0;
  fgets(text1, MAX, stdin);
  fgets(text2, MAX, stdin);
  text1[strcspn(text1, "\n")] = '\0';
  text2[strcspn(text2, "\n")] = '\0';
  for (int i = 0, n = strlen(text1);i < n; i++)
    {
      char alphabet = text1[i];
      if(isdigit(alphabet))
      {
        while(isdigit(text1[i]))
          {
            sum = sum * 10 + (text1[i] - '0');
            i++;
          }
        array1[array1Counter] = sum;
        array1Counter++;
        sum = 0;
      }
    }
    for (int i = 0, n = strlen(text2); i < n; i++)
    {
      char alphabet = text2[i];
      if(isdigit(alphabet))
      {
        while(isdigit(text2[i]))
          {
            sum = sum * 10 + (text2[i] - '0');
            i++;
          }
        array2[array2Counter] = sum;
        array2Counter++;
        sum = 0;
      }
    }
    // for (int i = 0; i < array1Counter; i++)
    // {
    //     printf("%d\n", array1[i]);
    // }
    // for (int i = 0; i < array2Counter; i++)
    // {
    //     printf("%d\n", array2[i]);
    // }
    
}