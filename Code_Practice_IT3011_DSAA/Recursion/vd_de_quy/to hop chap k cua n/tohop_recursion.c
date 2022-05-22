#include <stdio.h> 

int tohop_recursion(int k, int n) {
    if (k < 0 || n < 0) return 0;
    if (k == 0 || k == n)  return 1;
    else return tohop_recursion(k, n-1) + tohop_recursion(k-1, n-1);
}

int main() {
    printf("%d", tohop_recursion(3,5));
}