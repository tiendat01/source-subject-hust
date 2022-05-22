# Bài 1. Lập trình nhập vào số nguyên dương N. In
# các số nguyên tố nhỏ hơn N.

import os
import sys
import inspect

currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
print(currentdir) # abspath to bt-loop dir
print(parentdir) # abspath to chuong4 dir

# from page47_49 import check_prime
import page47_49

def main():
    N = int(input('Nhap vao so nguyen duong N = '))
    while N <= 0:
        N = int(input('Nhap sai N! Moi nhap lai N = '))
    print(f'Cac so nguyen to nho hon {N}: ')
    for i in range(1, N):
        if (page47_49.check_prime(i)):
            print(f'{i:5d}')

if __name__ == '__main__':
    main()
            