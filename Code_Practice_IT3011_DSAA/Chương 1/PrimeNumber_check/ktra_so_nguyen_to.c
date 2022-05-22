#include <stdio.h>
#include <math.h>

// Thuat toan kiem tra mot so nguyen duong co la nguyen to
int prime_number_check(int m) {
    int i, flag = 1;
    for (i = 2; i <= (int)(sqrt(m)); i++) {
        if (m % i == 0) flag = 0; 
    }
    return flag;
}

// Thuat toan tim so nguyen to lon hon so nguyen duong n
int large_prime_number(int n) {
    int large_m = n;
    do {
        large_m++;
    } while (prime_number_check(large_m) == 0);
    return large_m;
}
int main() {
    unsigned int input;
    scanf("%d", &input);
    if (prime_number_check(input) == 0) printf("khong la so nguyen to");
    else printf("la so nguyen to");

    printf("\n%d", large_prime_number(input));

}