#include <iostream>

using namespace std;

// for two-dimensional array
int alloc2DArray(int **&arr, int m, int n);
void inputData(int **arr, int m, int n, char Symbol);
void freeArray(int **arr, int m, int n);
void displayArray(int **arr, int m, int n);

struct matrix {
    int row;
    int col;
    int** arr;

    matrix& operator= (const matrix& B); 
}; 

matrix& matrix::operator= (const matrix& B) {
    if (this->arr != NULL) {
        for (int i = 0; i < row; i++) delete[] this->arr[i];
        delete[] this->arr;
        cout << "marked" << endl;
    }
    row = B.row; col = B.col;
    this->arr = B.arr;

//cach 2:
    // alloc2DArray(this->arr, row, col); // alloc cho matrix C va D 
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         this->arr[i][j] = B.arr[i][j];
    //     }
    // }

    // //sau do giai phong B
    // for (int i = 0; i < B.row; i++) delete[] B.arr[i];
    // delete[] B.arr;
    return *this;
}

int checkAdd(matrix A, matrix B) {
    if (A.row != B.row || A.col != B.col) {
        printf("Khong thoa man dk cua phep cong ma tran!!!");
        return 0;
    }
    return 1;
}

matrix operator + (matrix A, matrix B) {
    matrix sum;
    sum.row = A.row;
    sum.col = A.col;
    alloc2DArray(sum.arr, sum.row, sum.col); // nho giai phong
    for (int i = 0; i < sum.row; i++) {
        for (int j = 0; j < sum.col; j++) {
            sum.arr[i][j] = A.arr[i][j] + B.arr[i][j];
        }
    }
    return sum;
}

int checkMulti(matrix A, matrix B) {
    if (A.col != B.row) {
        printf("Khong thoa man dk cua phep nhan ma tran!!!");
        return 0;
    }
    return 1;
}

matrix operator * (matrix A, matrix B) {
    matrix suply;
    suply.row = A.row;
    suply.col = B.col;
    alloc2DArray(suply.arr, suply.row, suply.col);
    for (int i = 0; i < suply.row; i++) {
        for (int j = 0; j < suply.col; j++) {
            int tmp = 0;
            for (int k = 0; k < A.col; k++) tmp += (A.arr[i][k] * B.arr[k][j]);
            suply.arr[i][j] = tmp;
        }
    }
    return suply;
}


int main(void) {
    matrix A, B, C, D;
    
    printf("Nhap vao so hang cua A: "); scanf("%d", &A.row);
    printf("\nNhap vao so cot cua A: "); scanf("%d", &A.col);
    printf("\nNhap vao so hang cua B: "); scanf("%d", &B.row);
    printf("\nNhap vao so cot cua B: "); scanf("%d", &B.col);

    alloc2DArray(A.arr, A.row, A.col);
    alloc2DArray(B.arr, B.row, B.col);
    inputData(A.arr, A.row, A.col, 'A');
    inputData(B.arr, B.row, B.col, 'B');

    // o day ko cap phat cho ket qua: ma tran C va D
    // con tro trong C va D se duoc gan cho tro vao ma tran ket qua thong qua da nang hoa toan tu
    C.arr = NULL;
    D.arr = NULL;
    printf("\nCong ma tran:\n");
    if (checkAdd(A,B)) {     
        for (int i = 0; i < 10; i++)
            C = A + B; // A+B cap phat cho sum => gan vao C xog thi phai giai phong
        displayArray(C.arr, C.row, C.col);
        freeArray(C.arr, C.row, C.col);
    }

    printf("\nNhan ma tran:\n");
    if (checkMulti(A,B)) {
        for (int i = 0; i < 10; i++)
            D = A * B; // A*B cap phat cho sum => gan vao C xog thi phai giai phong
        displayArray(D.arr, D.row, D.col);
        freeArray(D.arr, D.row, D.col);
    }

    freeArray(A.arr, A.row, A.col);
    freeArray(B.arr, B.row, B.col);
    return 0;
}


// for2D_array:
int alloc2DArray(int **&arr, int m, int n) {
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

void displayArray(int **arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}