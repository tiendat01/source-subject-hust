def UCLN_dequy(a, b):
    if a < b:
        return UCLN_dequy(a, b-a)
    elif a > b:
        return UCLN_dequy(a-b, b)
    else:
        return a 
def main():
    a = int(input('Nhap so nguyen duong a: '))
    b = int(input('Nhap so nguyen duong b: '))
    print(f'UCLN cua {a} va {b} la: {UCLN_dequy(a, b)}')
    
main()