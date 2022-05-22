# #include <stdio.h>
# int main()
# {
# int thang;
# do {
# printf("Nhap vao thang trong nam ");
# scanf("%d", &thang);
# } while(thang < 1 || thang > 12);
# switch(thang)
# {
# case 2:
# printf ("Thang 2 co 28 hoac 29 ngay");
# break;
# 37Sửa bài xác định ngày trong tháng (2)
# case 4:
# case 6:
# case 9:
# case 11:
# printf("Thang %d co 30 ngay", thang);
# break;
# default :
# printf("Thang %d co 31 ngay", thang);
# break;
# }
# return 0;
# }

def days_in_month(thang):
    match thang:
        case 1 | 3 | 5 | 7 | 8 | 10 | 12:
            print(f'Thang {thang} co 31 ngay', end='', flush=True)
        case 2:
            print('Thang 2 co 28 hoac 29 ngay')
        case _:
            print(f'Thang {thang} co 30 ngay', end='', flush=True)
            

def main():
    while True:
        thang = int(input('Nhap vao thang trong nam: '))
        if thang >= 1 and thang <= 12: break
        else:
            print('Ban nhap sai! Moi nhap lai!')
    days_in_month(thang)

main()