#include <stdio.h>

int main() {
    // For loop
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // While loop
    int j = 1;
    while (j <= 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // Do-while loop
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);
    printf("\n");

    return 0;
}