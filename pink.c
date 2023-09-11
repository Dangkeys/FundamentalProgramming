#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter your number: ");
    scanf("%d", &num);

    int colSize = num * 2 - 1;
    int topHalf = num - 1;

    if (num > 2) {
        // Create top wing
        for (i = 0; i <= topHalf; i++) {
            for (j = 0; j < colSize; j++) {
                if (j <= i || j >= colSize - i - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Create bottom wing (reversed top wing)
        for (i = topHalf - 1; i >= 0; i--) {
            for (j = 0; j < colSize; j++) {
                if (j <= i || j >= colSize - i - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    } else {
        printf("Please type again (Number has to be more than 2)\n");
        printf("Your number is ");
        scanf("%d", &num);
    }

    return 0;
}
