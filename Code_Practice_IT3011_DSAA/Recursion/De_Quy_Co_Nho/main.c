#include <stdio.h>

// de quy co nho:
//+ tinh toan se nhanh hon do luu cac bai toan con vao mang F.
//+ tuy nhien se ton bo nho de luu cac bai toan con

// Bai toan tim so thu n cua day Fibonacci
int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; // tat ca cac bai toan con chua dc giai

int FibiTer(int n) {
    F[0] = 1, F[1] = 1; // giai hai bai toan con nho nhat
    if (F[n] == -1) F[n] = FibiTer(n-1) + FibiTer(n-2); // neu bai toan con F[n] chua dc giai thi giai no
    return F[n];
}



// Bai toan tinh to hop chap k cua n C(n,k)
int D[10][10];

int ToHop(int k, int n) {
    // cac buoc neo de quy
    D[0][1] = 1; 
    if (k == n || k == 0) return 1;
    // neu da giai quyet bai toan con roi thi ko can de quy.
    if (D[k][n] > 0) return D[k][n];
    else {
        D[k][n] = ToHop(k,n-1) + ToHop(k-1,n-1);
        return D[k][n];
    }
} 

int main()
{
    printf("%d\n", FibiTer(8)); // 1,1,2,3,5,8,13,21,34
    printf("%d", ToHop(3,5)); // 10
}
