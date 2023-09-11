#include <stdio.h>
#include <string.h>
#include <stdbool.h>
const int MAX = 100;

int main(void) {
  char text[MAX];
  char keyword[MAX];
  bool isAnyKeyword = false;

  printf("input 1: ");
  fgets(text, MAX, stdin);

  printf("input 2: ");
  fgets(keyword, MAX, stdin);

  text[strcspn(text, "\n")] = '\0';
  keyword[strcspn(keyword, "\n")] = '\0';

  printf("text length = %d, keyword length = %d\n", strlen(text), strlen(keyword));

  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == keyword[0]) {
      int j;
      for (j = 0; j < strlen(keyword); j++) {
        if (text[i + j] != keyword[j]) {
          break;
        }
      }
      if (j == strlen(keyword)) {
        isAnyKeyword = true;
        printf("%d\n", i);
        i += j - 1;  // Jump to the end of the keyword in the text
      }
    }
  }

  if (!isAnyKeyword) {
    printf("Keyword not found\n");
  }

  return 0;
}
