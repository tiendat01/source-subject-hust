# Nhập vào số nguyên N, tính tổng và tích của
# các số nguyên từ 1 đến N.
# #include <stdio.h>
# void main()
# {
# int i, N, S, P;
# printf(“Nhap N = “); scanf(“%d”, &N);
# S = 0; P = 1;
# for(i = 1; i <= N; i++)
# {
# S += i;
# P *= i;
# }
# printf(“S = %d\n”, S);
# printf(“P = %d\n”, P);
# }

def main():
    N = int(input("Nhap N = "))
    S = 0 ; P = 1
    for i in range(1, N+1): # from 1 to N
        S += i
        P *= i
    print(f'S = {S}')
    print(f'P = {P}')

main()