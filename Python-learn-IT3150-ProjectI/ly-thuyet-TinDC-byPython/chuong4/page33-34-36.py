# Ví dụ: nhập vào điểm của một sinh viên, nếu
# điểm đó không nằm trong đoạn [0, 10] thì
# thông báo cho người dùng nhập lại
# #include <stdio.h>
# void main()
# {
# float diem;
# printf("Chuong trinh nhap diem sinh vien\n");
# printf("Nhap diem (0<=diem<=10):");
# scanf("%f", &diem);
# while (diem < 0 || diem > 10)
# {
# printf("\nBan nhap khong dung!\n");
# printf("Ban hay nhap lai (0<=diem<=10):");
# scanf("%f", &diem);
# }
# printf("\nDiem ban vua nhap la: %.2f", diem);
# }

def main():
    print('Chuong trinh nhap diem sinh vien')
    diem = float(input('Nhap diem (0<=diem<=10): '))
    while diem < 0 or diem > 10:
        print('Ban nhap khong dung!')
        diem = float(input('Ban hay nhap lai (0<=diem<=10): '))
    print(f'\nDiem ban vua nhap: {diem:.2f}')

def main2():
    print('Chuong trinh nhap diem sinh vien')
    while True:
        diem = float(input('Nhap diem (0<=diem<=10): '))
        if diem >= 0 and diem <= 10:
            break
        else:
            print('Ban nhap khong dung!')
    print(f'\nDiem ban vua nhap: {diem:.2f}')

# main()
main2()