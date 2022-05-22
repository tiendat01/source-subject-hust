# Bài 3. Lập trình nhập vào số nguyên dương N. In
# ra dãy số Fibonaci nhỏ hơn N.

list = [0] * 1000
list[0] = 1 ; list[1] = 1

def fibo_dequy(n):
    if list[n] != 0:
        return list[n]
    # if n == 0 or n == 1:
    #     return 1
    else:
        list[n] = fibo_dequy(n-2) + fibo_dequy(n-1)
        return list[n]
    
def fibo_loop(n):
    a = 1
    b = 1
    res = 0
    if n == 0 or n == 1:
        return 1
    for i in range(2, n+1):
        res = a + b
        a = b
        b = res
    return res


def main():
    n = int(input('Nhap so nguyen duong n: '))
    i = 0
    tmp = fibo_loop(i)
    while tmp < n:
        print(f'{tmp}', end=' ')
        i = i + 1
        tmp = fibo_loop(i)

main()