# #include <stdio.h>
# int GT(int n)
# {
# int ket_qua, i;
# if (n < 0) return -1;
# if (n == 0) return 1;
# ket_qua = 1;
# for (i = 1; i <= n; i++)
# ket_qua = ket_qua * i;
# return ket_qua;
# }
# // khai bao ham tinh chinh hop A(k, n)
# int A(int k, int n)
# {
# return GT(n) / GT(n - k);
# }
# // khai bao ham tinh top hop C(k, n)
# int C(int k, int n)
# {
# return GT(n) / (GT(k) * GT(n - k));
# }
# int main() {
# int n = 4, k = 3;
# printf("%d! = %d\n", n, GT(n));
# printf("%d! = %d\n", k, GT(k));
# printf("A(%d, %d) = %d\n", k, n, A(k, n));
# printf("C(%d, %d) = %d\n", k, n, C(k, n));
# return 0;
# }

# tinh giai thua
def GT(n):
    if n < 0: return -1
    if (n == 0): return 1

    ket_qua = 1
    for i in range(1, n+1):
        ket_qua *= i
    return ket_qua

# tinh chinh hop A(k, n)
def A(k , n):
    return GT(n) / GT(n-k)

# tinh to hop C(k, n)
def C(k, n):
    return GT(n) / (GT(k) * GT(n-k))

def main():
    n = 4; k = 3
    print(f'{n}! = {GT(n)}')
    print(f'{k}! = {GT(k)}')
    print(f'A({k}, {n}) = {A(k, n)}')
    print(f'C({k}, {n}) = {C(k, n)}')

main()
