# 2. Viết hàm kiểm tra 1 số có phải là số nguyên
# tố hay không.

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
    n = int(input('Nhap vao so nguyen n: '))
    if check_prime(n):
        print(f'{n} la so nguyen to')
    else:
        print(f'{n} khong la so nguyen to')
        
main()
