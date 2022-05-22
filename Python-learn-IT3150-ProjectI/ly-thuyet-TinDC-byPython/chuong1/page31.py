# #include <stdio.h>
# #include <conio.h>
# #define PI 3.14
# void main(){
#     float r, s;//Hai biến r, s thuộc kiểu số thực
#     printf("Nhap ban kinh hinh tron:");
#     scanf("%f",&r);
#     s = PI * r * r;
#     printf("Dien tich hinh tron %f\n",s);
#     getch();
# }


import msvcrt

PI = 3.14

def main():
    r = float(input("Nhap ban kinh hinh tron:"))
    s = PI * r * r
    print("Dien tich hinh tron {}".format(s), end='', flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main()