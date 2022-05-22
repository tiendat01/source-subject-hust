#include <stdio.h>

int main() {
    // int x = 100, *p = &x;
    // printf("In ra gia tri x: %d\n", x);
    // printf("In ra gia tri cua con tro p: %p\n", p);
    // *p++ = 5;
    // //*++p = 5;
    // // ++*p = 5; // cais nay bij loi
    // printf("In ra gia tri x: %d\n", x);
    // printf("In ra gia tri cua con tro p: %p", p);

    int i,n;
    int m[n]; // c ko ho tro kieu khai bao mang dong nay => C++
    // C ho tro theo malloc(), calloc(), realloc(), free()
    printf("\n vao kt mang "); scanf("%d", &n);
    for (i = 1; i < n; i++) i[m] = i*5;
    for (i = 1; i < n; i++) printf("\n m[%d] = %d", i, m[i]);
}