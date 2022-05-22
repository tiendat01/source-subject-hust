#include <stdio.h>

void allocate_mem(int ***mt, int m, int n){
    //#Allocate memory for the matrix
	(*mt) = new int* [m];
	for (int i = 0; i < n; i++) (*mt)[i] = new int[n];
}


void input(int **mt, int m, int n, char name){
    //#Input elements of the matrix
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c[%d][%d] = ",name, i ,j);
			scanf("%d", (*(mt + i) + j));
		}
	}
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mt[i][j]);
		}
		printf("\n");
	}
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    for (int i = 0; i < m; i++) delete[] mt[i];
    delete[] mt;
}

int main() {
	printf("Hoten: Nguyen Tien Dat\nMSSV: 20194242\n\n");
	int n, **A, **B;
	printf("Enter the size of matrix n = "); scanf("%d", &n);
	allocate_mem(&A,n,n);
	allocate_mem(&B,n,n);
	printf("Input data to matrix:\n");
	input(A,n,n,'A');
	input(B,n,n,'B');
	printf("Matrix A:\n"); output(A,n,n);
	printf("Matrix B:\n"); output(B,n,n);
	// process:
	// Tong 2 matran: A + B
	printf("A + B = \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j] + B[i][j]);
		}
		printf("\n");
	}
	// Tich 2 matran:
	printf("A * B = \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++) {
				tmp += A[i][k] * B[k][j];
			}
			printf("%d ", tmp);
		}
		printf("\n");
	}
}
