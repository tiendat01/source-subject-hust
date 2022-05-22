# #include <stdio.h>
# #include <conio.h>
# void main(){
#     float a, b, x;
#     printf("Nhap he so a khac 0");scanf("%f",&a);
#     printf("Nhap he so b, b=");scanf("%f",&b);
#     x = -b/a;
#     printf("Nghiem cua phuong trinh %f",x);
#     getch();
# }

import msvcrt

def main():
    a = float(input("Nhap he so a khac 0"))
    b = float(input("Nhap he so b, b="))
    x = -b/a
    print(f"Nghiem cua phuong trinh {x}", end="", flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main()