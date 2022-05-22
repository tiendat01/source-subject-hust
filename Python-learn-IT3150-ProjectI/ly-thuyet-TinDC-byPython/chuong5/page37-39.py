# sap xep mang theo selection sort:
def main():
    m = []
    n = int(input('Cho biet so phan tu cua mang: '))
    for i in range(0, n):
        m.append(int(input(f'Nhap gia tri cua m[{i}] = ')))

    print('Mang truoc khi sap xep: ')
    for i in range(0, n):
        print(f'{m[i]:3}', end='')
    
    for i in range(0, n-1):
        for j in range(i+1, n):
            if m[j] < m[i]:
                # tmp = m[j]
                # m[j] = m[i]
                # m[i] = tmp
                m[i], m[j] = m[j], m[i]
        print(f'\nMang o luot sap xep thu {i+1}: ')
        for k in range(0, n):
            print(f'{m[k]:3}', end='')

main()