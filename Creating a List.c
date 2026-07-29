#include <stdio.h>

int main() {
    int list[5];
    for (int i = 0; i < 5; i++) {
        list[i] = (i + 1) * 10;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}