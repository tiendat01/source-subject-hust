# Nhập vào số nguyên dương N, in ra màn hình
# biểu diễn nhị phân của N.
# #include <stdio.h>
# void main()
# {
# int N, S, i;
# printf(“Nhap N = “); scanf(“%d”, &N);
# S = 0; i = 1;
# while (N > 0)
# {
# S += (N % 2) * i;
# N /= 2;
# i *= 10;
# }
# printf(“S = %d\n”, S);
# }

def main():
    N = int(input('Nhap N = '))
    S = 0; i = 1
    while N > 0:
        S += (N % 2) * i
        N //= 2
        i *= 10
    print(f'S = {S}')

main()