#include <stdio.h>

int globalVar = 100; // Global scope

// Function definition with parameters and return value
int add(int a, int b) {
    int localVar = 10; // Local scope - only visible inside this function
    return a + b + localVar - localVar; // demonstrating local scope usage
}

// Recursive function
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// C has no native lambdas (pre-C++11 style); function pointers simulate this
int square(int x) {
    return x * x;
}

int main() {
    printf("Add: %d\n", add(5, 3));
    printf("Factorial: %d\n", factorial(5));
    printf("Global: %d\n", globalVar);

    int (*squareFunc)(int) = square; // function pointer acting like a lambda reference
    printf("Square via pointer: %d\n", squareFunc(4));
    return 0;
}