# 1. Viết chương trình nhập từ bàn phím N số thực lưu vào
# một mảng (N < 100 và N được nhập từ bàn phím). Sau đó
# ghi ra một file văn bản có tên là “float.dat” theo quy cách:
# dòng đầu tiên lưu số lượng các số thực, các dòng tiếp theo
# lưu các số thực, mỗi số lưu trên một dòng. Đọc lại tệp văn
# bản đó và lưu các số thực đọc được vào một mảng. Sắp
# xếp các số thực trong mảng theo thứ tự tăng dần và ghi ra
# một tệp văn bản khác có tên là “float_sx.dat” theo quy cách
# giống như tệp “float.dat”.
# => Áp dụng với mảng các đối tượng cấu trúc sinh viên gồm
# các trường: MSSV, Hoten, Diemthi

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    n = int(input('Nhap so N: '))
    while n >= 100:
        n = int(input('Nhap N qua lon. Nhap lai N:'))
    a = []
    for i in range(0, n):
        sothuc = float(input(f'Nhap so thuc thu {i+1}:'))
        a.append(sothuc)
    with open(curdir+'\\float.dat', 'w') as f:
        f.write(str(n) + '\n')
        for i in range(0,n):
            f.write(str(a[i]) + '\n')

    b = []
    with open(curdir+'\\float.dat', 'r') as f:
        m = int(f.readline())
        for tmp_st in f:
            b.append(float(tmp_st))
    b.sort(reverse=False)
    with open(curdir+'\\float_sx.dat', 'w') as f:
        f.write(str(m) + '\n')
        for i in range(0,m):
            f.write(str(b[i]) + '\n')
    
main()