#include <iostream>

using namespace std;

int** alloc2Darray(int **arr, int m, int n) {
    arr = new int* [m];
    for (int i = 0; i < m; i++) arr[i] = new int[n];
    return arr;
}

void inputData(int **arr, int m, int n, char Symbol) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c[%d][%d] = ", Symbol, i, j);
            // scanf("%d", &arr[i][j]);
            scanf("%d", (*(arr + i) + j));
        }
    }
}

void freeArray(int **arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void display(int **arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **A = NULL;
    A = alloc2Darray(A,2,2);
    inputData(A, 2,2,'A');
    display(A, 2,2);
    freeArray(A, 2,2);
}

// void alloc1D(int **arr, int n) {
//     *arr = new int[n];
// }

// void input(int *arr, int n) {
//     for (int i = 0; i < n; i++) {
//         printf("arr[%d] = ", i);
//         scanf("%d", arr+i);
//     }
// }

// void display(int *arr, int n) {
//     for (int i = 0; i < n; i++) printf("%5d", arr[i]);
// }

// void freearray(int *arr, int n) {
//     delete[] arr;
// }

// int main() {
//     int *A = NULL;
//     alloc1D(&A, 3);
//     input(A, 3);
//     display(A, 3);
//     freearray(A, 3);
// }