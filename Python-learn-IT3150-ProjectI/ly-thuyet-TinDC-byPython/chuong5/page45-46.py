# xoa phan tu khoi mang:
def main():
    m = []
    n = int(input('Cho biet so phan tu cua mang: '))
    for i in range(0, n):
        m.append(int(input(f'Nhap gia tri cua m[{i}] = ')))

    k = int(input('Nhap vi tri can xoa: '))
    if k < n-1:
        for i in range(k, n-1):
            m[i] = m[i+1]
    n -= 1
    print('Noi dung cua mang: ')
    for i in range(0, n):
        print(f'{m[i]:5}', end='')
main()