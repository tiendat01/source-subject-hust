# Them phan tu vao mang:
def main():
    m = []
    n = int(input('Cho biet so phan tu cua mang: '))
    for i in range(0, n):
        m.append(int(input(f'Nhap gia tri cua m[{i}] = ')))

    k = int(input('Nhap vi tri can chen: '))
    p = int(input('Nhap gia tri can chen: '))

    # Chen phan vao mang:
    m.append(0)
    if k < n-1:
        for i in range(n-1, k, -1):
            m[i+1] = m[i]
    m[k] = p
    n += 1
    #  In ra noi dung mang sau khi xoa phan tu:
    print('Noi dung cua mang: ')
    for i in range(0, n):
        print(f'{m[i]:5d}', end='')

main()