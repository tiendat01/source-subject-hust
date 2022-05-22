# 6. Đọc kích thước file ảnh bitmap (BMP).
# Chiều rộng và chiều cao của file ảnh BMP được lưu trữ
# trong phần header có địa chỉ offset lần lượt là 0x12 và 0x14
# dưới dạng số nguyên 16 bit.
# Hãy đọc các giá trị này từ 1 file ảnh BMP và hiển thị trên
# màn hình.

import struct
import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    filename = input('Nhap ten file anh bitmap: ')
    with open(curdir+'\\'+filename, 'rb') as f:
        f.seek(0x12, 0) # di chuyen den byte 0x12
        width = struct.unpack('i'*1, f.read(2*1)) # doc 2 bytes vao bien width 1 lan
        f.seek(0x16, 0) # di chuyen den byte 0x16
        height = struct.unpack('i'*1, f.read(2*1)) # doc 2 bytes vao bien height 1 lan

    print(f'Kich thuoc anh la {width}x{height}')
main()