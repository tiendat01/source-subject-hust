# Ví dụ 2: Thao tác với tệp nhị phân
# ⚫ Tạo tệp nhị phân my_float.dat đặt tại ổ đĩa C
# để ghi 100 số thực.
# ⚫ Mở lại tệp này và ghi nội dung sang một tệp
# khác, tệp này có tên được nhập từ bàn phím.
# ⚫ Hiển thị giá trị số thực đầu tiên trong tệp
# my_float.dat
# ⚫ Cho phép người dùng nhập một số thứ tự từ
# bàn phím và hiển thị số thực ở vị trí này trong
# tệp my_float.dat

import struct
import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    a = []
    for i in range(0, 100):
        sothuc = float(i * 2 + 1) 
        a.append(sothuc)
    with open(curdir+'\\my_float.dat', 'wb') as f:
        s = struct.pack('f'*len(a), *a) # float to bytes
        f.write(s)
    
    filename = input('Nhap ten file moi: ')
    f1 = open(curdir+'\\my_float.dat', 'rb')
    f2 = open(curdir+'\\'+filename, 'wb')
    for tmp_float in f1:
        f2.write(tmp_float)
    f1.close()
    f2.close()

    with open(curdir+'\\my_float.dat', 'rb') as f:
        ls = struct.unpack('f'*100, f.read(4*100)) # 4 vi float kich thuoc 4 bytes
        print(ls)
        f.seek(0,0) # quay ve
        x = struct.unpack('f'*1, f.read(4))
        print(f'So thuc dau tien trong file: {x}')
        n = int(input('Nhap vi tri can doc: '))
        f.seek((n-1)*4, 0) # from the beginning of file
        y = struct.unpack('f'*1, f.read(4))
        print(f'So thuc thu {n} trong file: {y}')
    
main()