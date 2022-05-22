#include <iostream>
 #include "alloc_matrix.hpp" // ham alloc dung tham chieu / dung tham tri dia chi

using namespace std;

// cach 2 dung con tro
// for two-dimensional array
// int** alloc2DArray(int **arr, int m, int n);
// void inputData(int **arr, int m, int n, char Symbol);
// void freeArray(int **arr, int m, int n);
// void displayArray(int **arr, int m, int n);

// int** alloc2DArray(int **arr, int m, int n) {
//     arr = new int* [m];
//     for (int i = 0; i < m; i++) {
//         arr[i] = new int[n];
//     }
//     return arr;

// }

// void inputData(int **arr, int m, int n, char Symbol) {
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%c[%d][%d] = ", Symbol, i, j);
//             // scanf("%d", &arr[i][j]);
//             scanf("%d", (*(arr + i) + j));
//         }
//     }
// }

// void freeArray(int **arr, int m, int n) {
//     for (int i = 0; i < m; i++) {
//         delete[] arr[i];
//     }
//     delete[] arr;
// }

// void displayArray(int **arr, int m, int n) {
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%5d", arr[i][j]);
//         }
//         printf("\n");
//     }
// }



void addMatrix(int **A, int **B, int **C, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int **A = NULL, **B = NULL, **C = NULL;
    int m, n;
    printf("Nhap so dong m = "); scanf("%d", &m);
    printf("Nhap so cot n = "); scanf("%d", &n);

    // dung tham chieu:
    // alloc2DArray(A,m,n); 
    // alloc2DArray(B,m,n);
    // alloc2DArray(C,m,n);

    // dung con tro:
    // A = alloc2DArray(A,m,n);
    // B = alloc2DArray(B,m,n);
    // C = alloc2DArray(C,m,n);

    // dung tham tri dia chi ***
    alloc2DArray(&A,m,n);
    alloc2DArray(&B,m,n);
    alloc2DArray(&C,m,n);

    inputData(A,m,n,'A');
    inputData(B,m,n,'B');

    addMatrix(A,B,C,m,n);
    displayArray(C,m,n);

    freeArray(A,m,n);
    freeArray(B,m,n);
    freeArray(C,m,n);
}