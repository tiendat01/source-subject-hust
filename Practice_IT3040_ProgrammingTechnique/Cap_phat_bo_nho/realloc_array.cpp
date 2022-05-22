#include <iostream>

using namespace std;

// int allocArray(int *&arr, int n) {
//     arr = new int[n];
//     if (arr == NULL) return 0;
//     return 1;
// }

// void inputArray(int *arr, int n, char symbol) {
//     for (int i = 0; i < n; i++) {
//         printf("%c[%d] = ", symbol, i);
//         scanf("%d", arr+i);
//     }
// }

void freeArray(int *arr, int n) {
    delete[] arr;
}

void displayArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
}

// void reallocArray(int *&arr, int n, int newsize) {
//     int *arr_trung_gian = new int[newsize];
//     for (int i = 0; i < n; i++) {
//         arr_trung_gian[i] = arr[i];
//     }
//     delete[] arr;
//     arr = arr_trung_gian;
// }

int main() {
    int *A, n = 1, choice;
    A = new int[n];
    printf("Chuong trinh tai cap phat mang\n1. Nhap them 1 ptu\n2. Ket thuc");    
    while (1) {
        printf("\nLua chon cua ban: "); scanf("%d", &choice);
        if (choice == 2) break;
        printf("A[%d] = ", n-1); scanf("%d", A+n-1);
        n++;
        
        int *A_tmp = new int[n];
        for (int i = 0; i < n; i++) A_tmp[i] = A[i];
        delete[] A;
        A = A_tmp;
    }
    displayArray(A,n-1);
    freeArray(A,n);
}
