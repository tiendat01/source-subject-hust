# #include <conio.h>
# #include <stdio.h>
# //Noi dung cua ham main() cung la mot khoi lenh
# void main()
# {
# // khai bao bien
# int c;
# c = 10;
# printf(“Gia tri cua c = %d day la c ngoai”, c);
# 6Ví dụ
# // bat dau mot khoi lenh khac
# {
# int c;
# c = 10;
# printf(“\n Gia tri cua c = %d day la c trong”, c);
# printf(“\n Tang gia tri cua c them 10 don vi”);
# c = c + 10;
# printf(“\n Gia tri cua c = %d day la c trong”, c);
# }
# printf(“\n Gia tri cua c = %d day la c ngoai”, c);
# getch();
# }// ket thuc khoi lenh cua ham main()


import msvcrt

def main():
    c = 10
    print(f'Gia tri cua c = {c} day la c ngoai')
    def inner(): 
        c = 10
        print(f'Gia tri cua c = {c} day la c trong')
        print('Tang gia tri cua c them 10 don vi')
        c = c + 10
        print(f'Gia tri cua c = {c} day la c trong')
    inner()
    print(f'Gia tri cua c = {c} day la c ngoai', end='', flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main()
