#include <stdio.h>

int main() {
    int score = 82;

    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 75) {
        printf("Grade: B\n");
    } else if (score >= 50) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    // Switch example
    int day = 3;
    switch (day) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        default: printf("Invalid day\n");
    }
    return 0;
}