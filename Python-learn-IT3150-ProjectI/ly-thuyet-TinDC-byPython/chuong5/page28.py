# Lập trình nhập vào N số, liệt kê các phần tử khác
# nhau có trong mảng.
# • Ví dụ: 1 6 2 3 2 4 2 6 5 => Có 6 phần tử khác nhau
# là 1 6 2 3 4 5

def main():
    a = []
    check = {

    }

    while True:
        n = int(input('Cho so phan tu cua mang: '))
        if n > 0 and n <= 100:
            break
        else: print('Moi nhap lai: ')
    
    for i in range(0, n):
        a.append(int(input(f'a[{i}] = ')))
        check.update({a[i] : False})

    print('Cac phan tu khac nhau la: ')
    for i in range(0, n):
        if not check[a[i]]:
            print(f'{a[i]:3d}', end='')
            check[a[i]] = True
main()