#include <iostream>
#include <stdlib.h>

using namespace std;

// for two-dimensional array
int alloc2DArray(int **arr, int m, int n);
void inputData(int **arr, int m, int n, char Symbol);
void freeArray(int **arr, int m, int n);
void displayArray(int **arr, int m, int n);

// for 3D-array:
int alloc3DArray(int ***arr, int m, int n, int p);
void inputData(int ***arr, int m, int n, int p, char Symbol);
void freeArray(int ***arr, int m, int n, int p);
void displayArray(int ***arr, int m, int n, int p);

// for 4D-array:
int alloc3DArray(int ****arr, int m, int n, int p, int q);
void inputData(int ****arr, int m, int n, int p, int q, char Symbol);
void freeArray(int ****arr, int m, int n, int p, int q);
void displayArray(int ****arr, int m, int n, int p, int q);


int main() {
    // do something
}

// for2D_array:
int alloc2DArray(int **arr, int m, int n) {
    arr = new int* [m];
    if (arr == NULL) return 0;
    else {
        for (int i = 0; i < m; i++) {
            arr[i] = new int[n];
            if (arr[i] == NULL) return 0;
        }
    }
    return 1;
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

// for 3D_array:
int alloc3DArray(int ***arr, int m, int n, int p) {
    arr = new int** [m];
    if (arr == NULL) return 0; 
    for (int i = 0; i < m; i++) {
        arr[i] = new int* [n];
        if (arr[i] == NULL) return 0;
        for (int j = 0; j < n; j++) {
            arr[i][j] = new int[p];
            if (arr[i][j] == NULL) return 0; 
        }
    }
    return 1;
}

void inputData(int ***arr, int m, int n, int p, char Symbol) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                printf("%c[%d][%d][%d] = ", Symbol, i, j, k);
                scanf("%d", (*(*(arr+i)+j) + k ) );
            }
        }
    }
}

void freeArray(int ***arr, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}

void displayArray(int ***arr, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                printf("%5d", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// for 4D_array
int alloc3DArray(int ****arr, int m, int n, int p, int q) {
    arr = new int*** [m];
    if (arr == NULL) return 0;
    for (int i = 0; i < m; i++) {
        arr[i] = new int** [n];
        if (arr[i] == NULL) return 0;
        for (int j = 0; j < n; j++) {
            arr[i][j] = new int* [p];
            if (arr[i][j] == NULL) return 0;
            for (int k = 0; k < p; k++) {
                arr[i][i][k] = new int[q];
                if (arr[i][j][k] == NULL) return 0;
            }
        } 
    }
    return 1;
}

void inputData(int ****arr, int m, int n, int p, int q, char Symbol) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                for (int l = 0; l < q; l++) {
                    printf("%c[%d][%d][%d][%d] = ", Symbol, i, j, k, l);
                    scanf("%d", (*(*(*(arr+i)+j) + k) + l) );
                }
                
            }
        }
    }
}
void freeArray(int ****arr, int m, int n, int p, int q) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                delete[] arr[i][j][k];
            }
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

}
void displayArray(int ****arr, int m, int n, int p, int q) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                for (int l = 0; l < q; l++) {
                    printf("%5d", arr[i][j][k][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}