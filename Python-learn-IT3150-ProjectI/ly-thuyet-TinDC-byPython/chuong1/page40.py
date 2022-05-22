# #include <stdio.h>
# void main(){
#     // Khai bao cac bien
#     int a, b;
#     int tong, hieu, tich;
#     // Nhap vao tu ban phim 2 so nguyen
#     printf(“\n Nhap vao so nguyen thu
#     nhat: ”);
#     scanf(“%d”,&a);
#     printf(“\n Nhap vao so nguyen thu
#     hai: “);
#     scanf(“%d”,&b);
#     // Tinh tong, hieu, tich cua 2 so do
#     tong = a+b; hieu = a – b;tich = a*b;
#     // Hien thi cac gia tri ra man hinh
#     printf(“\n Tong cua 2 so vua nhap
#     la %d”, tong);
#     printf(“\n Hieu cua 2 so vua nhap
#     la %d”, hieu);
#     printf(“\n Tich cua 2 so vua nhap
#     la %d”, tich);
#     // Doi nguoi dung an phim bat ki
#     getch();
# }


import msvcrt

def main():
    # Nhap vao tu ban phim 2 so nguyen
    a = int(input("\n Nhap vao so nguyen thu nhat: "))
    b = int(input("\n Nhap vao so nguyen thu hai: "))
    # Tinh tong, hieu, tich cua 2 so do
    tong = a + b
    hieu = a - b
    tich = a * b
    # Hien thi cac gia tri ra man hinh
    print(f"\n Tong cua 2 so vua nhap la {tong}")
    print(f" Hieu cua 2 so vua nhap la {hieu}")
    print(f" Tich cua 2 so vua nhap la {tich}", end="", flush=True)
    # Doi nguoi dung an phim bat ky
    msvcrt.getch()

if __name__ == '__main__':
    main()
