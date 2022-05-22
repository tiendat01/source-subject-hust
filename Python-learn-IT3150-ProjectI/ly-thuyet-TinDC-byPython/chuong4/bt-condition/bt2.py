# Bài 2: Viết chương trình nhập 3 hệ số bất kỳ a, b
# và c từ bàn phím và giải phương trình bậc hai ax2
# + bx + c = 0

import bt1
import math

def ptbachai(a, b, c):
    denta = b*b - 4*a*c
    if denta == 0:
        print(f'Phuong trinh co 1 nghiem duy nhat: {-b / (2*a)}')
    elif denta > 0:
        print(f'Phuong trinh co 2 nghiem phan biet: \
            {(-b + math.sqrt(denta)) / (2*a)} va    \
            {(-b - math.sqrt(denta)) / (2*a)}')
    else:
        print(f'Phuong trinh co 2 nghiem phuc:          \
            ({-b} + {math.sqrt(-denta)}i) / {2*a} va    \
            ({-b} - {math.sqrt(-denta)}i) / {2*a}')

def main():
    print('Giai phuong trinh bac hai ax^2 + bx + c = 0')
    a = float(input('Nhap he so a: '))
    b = float(input('Nhap he so b: '))
    c = float(input('Nhap he so c: '))
    if a == 0:
        bt1.ptbacnhat(b, c)
    else:
        ptbachai(a, b, c)

if __name__ == '__main__':
    main()

