# Ví dụ: Nhập vào số nguyên không âm, đưa ra
# ngày trong tuần tương ứng (theo số dư khi
# chia cho 7).
# #include <conio.h>
# #include <stdio.h>
# void main()
# {
# int a;
# printf(“Nhap mot gia tri so nguyen
# khong am: “);
# scanf(“%d”, &a);
# 174.2.2. Cấu trúc lựa chọn switch (4)
# switch (a % 7)
# {
# case 0: printf(“ Chu nhat”); break;
# case 1: printf(“ Thu Hai”); break;
# case 2: printf(“ Thu Ba”); break;
# case 3: printf(“ Thu Tu”); break;
# case 4: printf(“ Thu Nam”); break;
# case 5: printf(“ Thu Sau”); break;
# case 6: printf(“ Thu Bay”); break;
# }
# getch();
# }


import msvcrt

def main():
    a = int(input('Nhap mot gia tri so nguyen khong am: '))
    # dictionary
    switch = {
        0: 'Chu nhat',
        1: 'Thu Hai',
        2: 'Thu Ba',
        3: 'Thu Tu',
        4: 'Thu Nam', 
        5: 'Thu Sau',
        6: 'Thu Bay'
    }
    print(switch.get(a % 7, 'Invalid value'), end='', flush= True)
    msvcrt.getch()

if __name__ == '__main__':
    main()