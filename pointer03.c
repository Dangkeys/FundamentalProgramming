#include <stdio.h>
#include <string.h>
#define MAX 256
int areResultStringsEqual(const char *str1, const char *str2);
int main() {
    struct Uniq {
        char word[MAX];
        char *ptr[2];
        char result[MAX];
        int counter;
    };

    struct Uniq input[2];

    for (int i = 0; i < 2; i++) 
    {
        scanf("%s", input[i].word);
        input[i].counter = 0;  
        input[i].ptr[0] = &input[i].word[0];
        input[i].ptr[1] = &input[i].word[0];
        input[i].result[0] = input[i].word[0];
        
        for (int j = 1; input[i].word[j] != '\0'; j++) 
        {
            while (*input[i].ptr[0] == input[i].word[j])
                j++;
            input[i].ptr[1] = &input[i].word[j];
            input[i].result[++input[i].counter] = *input[i].ptr[1];
            input[i].ptr[0] = input[i].ptr[1];
        }
        input[i].result[input[i].counter + 1] = '\0';
    }
    areResultStringsEqual(input[0].result, input[1].result) ? printf("uniq(a) = uniq(b)\n"): printf("uniq(a) != uniq(b)\n");
}
int areResultStringsEqual(const char *str1, const char *str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') 
    {
        if (str1[i] != str2[i])
            return 0; // Return 0 if characters not the same
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0'; // Return 1 if both are '\0'
}