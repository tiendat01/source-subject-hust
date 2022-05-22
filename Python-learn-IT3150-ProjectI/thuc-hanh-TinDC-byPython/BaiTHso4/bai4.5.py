# Bài 4.5 Lập chương trình thực hiện các công việc sau:
# - Nhập 3 số thực bất kì.
# - Giải và biện luận phương trình bậc 2:
# Lưu ý tính cả trường hợp và trường hợp nghiệm phức.
# Chú ý:
# - Nếu phương trình vô nghiệm thì in ra màn hình: Phuong trinh vo nghiem
# - Nếu phương trình vô số nghiệm thì in ra màn hình: Phuong trinh vo so nghiem
# - Nếu phương trình có 2 nghiệm phân biệt thì hiển thị nghiệm lớn trước rồi mới
# đến nghiệm bé

import math

def ptbacnhat(a, b):
    if a == 0 and b == 0:
        print('Phuong trinh co vo so nghiem')
    elif a == 0 and b != 0:
        print('Phuong trinh vo nghiem')
    else:
        print(f'Nghiem cua phuong trinh la {-b / a}', end='', flush=True)

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
        ptbacnhat(b, c)
    else:
        ptbachai(a, b, c)

if __name__ == '__main__':
    main()
