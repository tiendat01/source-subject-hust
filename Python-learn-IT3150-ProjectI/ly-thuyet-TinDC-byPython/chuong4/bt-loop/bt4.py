# Bài 4. Lập trình nhập vào số nguyên dương N.
# Kiểm tra xem N có phải là số hoàn hảo hay
# không?



def tongcs(n):
    tmp = n
    res = 0
    while tmp != 0:
        res += tmp % 10
        tmp //= 10
    return res

def tonguoc(n):
    res = 0
    for i in range (1, n):
        if n % i == 0:
            res += i
    return res

def main():
    n = int(input('Nhap vao mot so nguyen duong n: '))
    if n == tonguoc(n):
        print(f'{n} la so hoan hao')
    else:
        print(f'{n} ko la so hoan hao')

main()