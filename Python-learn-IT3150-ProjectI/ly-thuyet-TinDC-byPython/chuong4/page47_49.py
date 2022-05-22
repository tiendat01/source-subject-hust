# Ví dụ: nhập vào 1 số nguyên. Kết luận số đó
# là số nguyên tố hay là hợp số?

import math

def check_prime(n):
    if n <= 1: return False
    elif n == 2: return True
    else:
        flag = True
        for i in range(2, round(math.sqrt(n))+1):
            if n % i == 0:
                flag = False
                break
        return flag

def main():
    n = int(input('Nhap vao 1 so nguyen:'))
    if n <= 1: print(f'So {n} ko la so nguyen to va khong la hop so')
    else:
        flag = True
        for i in range(2, round(math.sqrt(n))+1):
            if n % i == 0:
                print(f'So {n} la hop so')
                flag = False
                break
        if flag:
            print(f'So {n} la so nguyen to')

if __name__ == '__main__':
    main()