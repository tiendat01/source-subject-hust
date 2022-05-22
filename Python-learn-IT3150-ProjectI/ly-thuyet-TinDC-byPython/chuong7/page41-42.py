# #include <stdio.h>
# int fibo(int k)
# {
# if (k == 0)
# return 0;
# if (k == 1)
# return 1;
# return fibo(k - 1) + fibo(k - 2);
# }
# • Ví dụ 2: In ra dãy số Fibonaci
# int main()
# {
# int i, n;
# printf("Nhap n: "); scanf("%d", &n);
# printf("So fibonaci thu %d la: %d\n", n,
# fibo(n));
# printf("Day so fibonaci\n");
# for (i = 0; i <= n; i++)
# printf("%5d", fibo(i));
# return 0;
# }

def fibo(k):
    if k == 0:
        return 0
    if k == 1:
        return 1
    return fibo(k-1) + fibo(k-2)

def main():
    n = int(input('Nhap n: '))
    print(f'So fibonacci thu {n} la: {fibo(n)}')
    print('Day so fibonacci: ')
    for i in range(0, n+1):
        print(f'{fibo(i):>5}', end='')

main()