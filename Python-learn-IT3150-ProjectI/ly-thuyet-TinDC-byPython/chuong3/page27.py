# #include <conio.h>
# #include <stdio.h>
# void main()
# {
# // khai bao bien
# int a; float x;
# char ch; char str[30];
# // Nhap du lieu
# printf(“Nhap vao mot so nguyen”);
# scanf(“%d”, &a);
# printf(“\n Nhap vao mot so thuc”);
# scanf(“%f”, &x);
# printf(“\n Nhap vao mot ki tu”);
# fflush(stdin); scanf(“%c”, &ch);
# printf(“\n Nhap vao mot xau ki tu”);
# fflush(stdin); scanf(“%s”, str);
# // Hien thi du lieu vua nhap vao
# printf(“\n Nhung du lieu vua nhap vao”);
# printf(“\n So nguyen: %d”, a);
# printf(“\n So thuc : %.2f”, x);
# printf(“\n Ki tu: %c: ”, ch);
# printf(“\n Xau ki tu: %s”, str);
# getch();
# }

import msvcrt
import sys

def main():
    a = int(input('Nhap vao mot so nguyen: '))
    x = float(input('Nhap vao mot so thuc: '))
    # read a character
    # print('Nhap vao mot ky tu: ', end='', flush=True)
    # ch = sys.stdin.read(1) # import sys

    ch = input('Nhap vao mot ky tu: ').split(' ')[0][0]

    str = input('Nhap vao mot xau ky tu: ').split(' ')[0] # mo phong scanf("%s", str);

    print('Nhung du lieu vua nhap vao')
    print(f'So nguyen: {a}')
    print(f'So thuc: {x:.2f}')
    print(f'Ky tu: {ch}')
    print(f'Xau ky tu: {str}', end='', flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main() 