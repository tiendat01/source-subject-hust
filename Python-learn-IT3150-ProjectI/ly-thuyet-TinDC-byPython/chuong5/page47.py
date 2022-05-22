# Lập trình nhập vào mảng N số nguyên, sau
# đó xóa tất cả các số chẵn khỏi mảng

def main():
    m = []
    n = int(input('Cho biet so phan tu cua mang: '))
    for i in range(0, n):
        m.append(int(input(f'Nhap gia tri cua m[{i}] = ')))
    i=0
    while i < len(m):
        if m[i] % 2 == 0:
            m.pop(i)
        else:
            i += 1
            
    for e in m:
        print(f'{e} ', end='')

main()