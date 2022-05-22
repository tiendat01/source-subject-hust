#include <iostream>
#include "alloc_matrix.hpp" 

int checkMulti(int rowA, int colA, int rowB, int colB) {
    if (colA == rowB) return 0;
    else return 1;
}

void multiMatrix(int **A, int **B, int **C, int rowA, int colA, int rowB, int colB) {
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            int tmp = 0;
            // colA == rowB
            for (int k = 0; k < colA; k++) {
                tmp += (A[i][k] * B[k][j]);
            }
            C[i][j] = tmp;
        }
    }
}

int main() {
    int **A = NULL, **B = NULL, **C = NULL;
    int rowA, colA, rowB, colB;
    printf("Nhap so dong cua A: "); scanf("%d", &rowA);
    printf("Nhap so cot cua A: "); scanf("%d", &colA);
    printf("Nhap so dong cua B: "); scanf("%d", &rowB);
    printf("Nhap so cot cua B: "); scanf("%d", &colB);

    if (checkMulti(rowA, colA, rowB, colB)) return 0;
    
    alloc2DArray(A,rowA,colA);
    alloc2DArray(B,rowB,colB);
    alloc2DArray(C,rowA,colB);

    inputData(A,rowA,colA,'A');
    inputData(B,rowB,colB,'B');

    multiMatrix(A,B,C,rowA,colA,rowB,colB);

    displayArray(C,rowA,colB);

    freeArray(A,rowA,colA);
    freeArray(B,rowB,colB);
    freeArray(C,rowA,colB);

}