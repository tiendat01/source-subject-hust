# #include <conio.h>
# #include <stdio.h>
# void main()
# {
# // khai bao bien
# float a, b;
# float max;
# printf(“ Nhap gia tri a va b: “);
# scanf(“%f %f”, &a, &b);
# 124.2.1. Cấu trúc if, if … else (tiếp)
# if (a < b)
# max = b;
# else
# max = a;
# printf(“\n So lon nhat trong 2 so
# %.0f va %.0f la %.0f “, a, b, max);
# getch();
# } //ket thuc ham main()


import msvcrt

def main():
    inp = input('Nhap gia tri a va b (tren cung 1 dong, cach nhau bang space): ')
    a = float(inp.split(' ')[0])
    b = float(inp.split(' ')[1])
    if a < b:
        max = b
    else:
        max = a
    print(f'So lon nhat trong 2 so {a:.0f} va {b:.0f} la {max:.0f}',end='', flush=True)
    msvcrt.getch()

main()