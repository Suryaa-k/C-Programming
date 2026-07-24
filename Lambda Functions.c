#include <stdio.h>

// C has NO native lambda support at all (pre-C11/C23).
// The closest simulation is a function pointer to a normal function.
int square(int x) {
    return x * x;
}

int main() {
    int (*squareLambda)(int) = square; // simulating a lambda reference
    printf("Square: %d\n", squareLambda(5));
    return 0;
}