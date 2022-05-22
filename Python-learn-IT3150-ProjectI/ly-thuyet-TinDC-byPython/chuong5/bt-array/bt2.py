# 2. Nhập N số nguyên dương từ bàn phím. Lập trình
# chuyển các số lẻ lên đầu dãy, các số chẵn về cuối dãy.
# Ví dụ: 1 3 2 7 4 6 5 => 1 3 7 5 2 4 6


def main():
    a = []
    n = int(input('Nhap vao so N: '))
    for i in range(0, n):
        a.append(int(input(f'Nhap so nguyen duong a[{i}] = ')))
    for i in range(0, n):
        if (a[i] % 2 == 0):
            for j in range (n-1, i, -1):
                if (a[j] % 2 == 1):
                    a[i], a[j] = a[j], a[i]
    for i in range(0, n):
        print(f'{a[i]} ', end='')
main()