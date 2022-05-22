# Bài 1: Viết chương trình nhập 2 hệ số bất kỳ a và
# b từ bàn phím và giải phương trình bậc nhất ax +
# b = 0

def ptbacnhat(a, b):
    if a == 0 and b == 0:
        print('Phuong trinh co vo so nghiem')
    elif a == 0 and b != 0:
        print('Phuong trinh vo nghiem')
    else:
        print(f'Nghiem cua phuong trinh la {-b / a}', end='', flush=True)

def main():
    print('Giai phuong trinh bac nhat ax + b = 0')
    a = float(input('Nhap he so a: '))
    b = float(input('Nhap he so b: '))
    # if a == 0 and b == 0:
    #     print('Phuong trinh co vo so nghiem')
    # elif a == 0 and b != 0:
    #     print('Phuong trinh vo nghiem')
    # else:
    #     print(f'Nghiem cua phuong trinh la {-b / a}', end='', flush=True)
    ptbacnhat(a, b)

if __name__ == '__main__':
    main()