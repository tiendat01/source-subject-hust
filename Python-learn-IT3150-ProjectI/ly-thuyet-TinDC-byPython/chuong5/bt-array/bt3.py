# 3. Nhập N số nguyên dương từ bàn phím. Lập trình
# sắp xếp các số lẻ tăng dần, các số chẵn giảm dần (giữ
# nguyên thứ tự đan xen).
# Ví dụ: 1 3 2 7 4 6 5 => 1 3 6 5 4 2 7

def main():
    a = []
    n = int(input('Nhap vao so N: '))
    for i in range(0, n):
        a.append(int(input(f'Nhap so nguyen duong a[{i}] = ')))
    # so chan giam dan
    for i in range(0, n):
        if (a[i] % 2 == 0):
            for j in range(i+1, n):
                if (a[j] % 2 == 0 and a[j] > a[i]):
                    a[i], a[j] = a[j], a[i]
    # so le tang dan
    for i in range(0, n):
        if (a[i] % 2 == 1):
            for j in range(i+1, n):
                if (a[j] % 2 == 1 and a[j] < a[i]):
                    a[i], a[j] = a[j], a[i]
    for i in range(0, n):
        print(f'{a[i]} ', end='')
main()