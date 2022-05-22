def main():
    a = []
    # n = 0
    while True:
        n = int(input('Cho so phan tu cua mang: '))
        if n > 0 and n <= 100:
            break
        else: print('Moi nhap lai: ')
    for i in range(0, n):
        a.append(int(input(f'a[{i}] = ')))

main()
