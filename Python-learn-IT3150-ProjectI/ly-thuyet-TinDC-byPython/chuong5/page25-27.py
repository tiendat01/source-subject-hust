# tim kiem tren mang
def main():
    a = []
    chiso = []
    n = int(input('Nhap vao so phan tu cua mang: '))
    k = int(input('Nhap vao gia tri tim kiem: '))
    print('Nhap vao cac phan tu cho mang a')
    for i in range(0, n):
        a.append(int(input(f'a[{i}] = ')))

    # tim kiem
    for i in range(0, n):
        if a[i] == k:
            chiso.append(i) # luu chi so
    
    if len(chiso) > 0:
        print(f'Trong mang co {len(chiso)} phan tu co gia tri bang {k}')
        print('\nChi so cua cac phan tu la: ')
        for i in chiso:
            print(f'{i:3}', end='')
    else:
        print(f'Trong mang khong co phan tu nao co gia tri bang {k}')

main()