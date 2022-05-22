# Nhập vào số nguyên dương N, in ra màn hình
# tổng các chữ số của N.
# #include <stdio.h>
# void main()
# {
# int N, S;
# printf(“Nhap N = “); scanf(“%d”, &N);
# S = 0;
# while (N > 0)
# {
# S += N % 10;
# N /= 10;
# }
# printf(“S = %d\n”, S);
# }

def main():
    N = int(input('Nhap N = '))
    S = 0
    while N > 0:
        S += N % 10
        N //= 10
    print(f'S = {S}')

main()