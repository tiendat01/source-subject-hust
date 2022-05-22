#include <stdio.h>

int fibonacci(int pos) {
    if (pos == 2 || pos == 1) return 1;
    else return fibonacci(pos-1) + fibonacci(pos-2);
}

int main() {
    printf("%d", fibonacci(5));
}