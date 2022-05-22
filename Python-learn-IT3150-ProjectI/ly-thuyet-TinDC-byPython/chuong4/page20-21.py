# Hãy viết chương trình nhập vào 1 tháng, sau đó
# đưa ra kết luận tháng đó có bao nhiêu ngày
# #include <conio.h>
# #include <stdio.h>
# void main ()
# {
# int thang; clrscr();
# printf("\n Nhap vao thang trong nam ");
# scanf("%d", &thang);
# switch(thang)
# {
# case 1:
# case 3:
# case 5:
# case 7:
# case 8:
# case 10:
# case 12:
# printf("\n Thang %d co 31 ngay ",thang);
# break;
# case 4:
# case 6:
# case 9:
# case 11:
# printf("\n Thang %d co 30 ngay ",thang);
# break;
# case 2:
# printf ("\n Thang 2 co 28 hoac 29 ngay");
# break;
# default :
# printf("\n Khong co thang %d", thang);
# break;
# }
# getch();
# }

import msvcrt

def main():
    thang = int(input('Nhap vao thang trong nam: '))
    match thang:
        case 1 | 3 | 5 | 7 | 8 | 10 | 12:
            print(f'Thang {thang} co 31 ngay', end='', flush=True)
        case 4 | 6 | 9 | 11:
            print(f'Thang {thang} co 30 ngay', end='', flush=True)
        case 2:
            print('Thang 2 co 28 hoac 29 ngay')
        case _:
            print(f'Khong co thang {thang}')
    msvcrt.getch()

if __name__ == '__main__':
    main()