# 8. Viết hàm tìm trung điểm của đoạn thẳng tạo bởi 2
# điểm trong không gian 3 chiều.

import bt7

def main():
    print('Nhap toa do diem p1: ')
    p1 = bt7.input_point()
    print('Nhap toa do diem p2: ')
    p2 = bt7.input_point()
    print('Toa do trung diem: ', end='')
    p1.mid(p2).display()

if __name__ == '__main__':
    main()