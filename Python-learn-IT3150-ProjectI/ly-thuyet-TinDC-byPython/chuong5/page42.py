# tinh tong va tich cac phan tu trong mang

def main():
    m = []
    n = int(input('Cho biet so phan tu cua mang: '))
    for i in range(0, n):
        m.append(int(input(f'Nhap gia tri cua m[{i}] = ')))
    s = 0
    for i in range(0, n):
        s += m[i]
    print(f'Tong cua cac phan tu: {s}')

    p = 1
    for i in range(0, n):
        p *= m[i]
    print(f'Tich cua cac phan tu: {p}')