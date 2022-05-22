# 3. Viết chương trình nhập 2 số a và n. In ra
# màn hình giá trị bit thứ n của số a.

def main():
    a = int(input('Nhap so a: '))
    n = int(input('Nhap so n: '))
    print(f'Bit thu {n} cua so nguyen {a}: ' + str(bin(a))[2:][n-1])

if __name__ == '__main__':
    main()