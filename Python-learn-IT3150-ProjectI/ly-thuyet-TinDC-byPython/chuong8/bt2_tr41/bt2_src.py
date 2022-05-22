# 2. Viết chương trình so sánh nội dung hai file:
# a. Nhập từ bàn phím hai xâu kí tự là đường dẫn tới hai file
# cần so sánh.
# b. Hiển thị ra màn hình dòng thông báo:
# Hai file ten_1 và ten_2 giống nhau (nếu hai file có nội dung
# giống nhau, hai file có cùng kích thước và các byte cùng vị
# trí thì có giá trị giống nhau).
# Hai file ten_1 và ten_2 không giống nhau (nếu hai file có
# nội dung khác nhau. Ở đây ten_1 và ten_2 là đường dẫn
# của hai file cần so sánh).

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    filename1 = input('Nhap vao ten file 1 trong thu muc hien tai: ')
    filename2 = input('Nhap vao ten file 2 trong thu muc hien tai: ')
    try:
        f1 = open(curdir+'\\'+filename1, 'r')
    except:
        print('khong ton tai file 1 trong thu muc hien tai!')
    try:
        f2 = open(curdir+'\\'+filename2, 'r')
    except:
        print('khong ton tai file 2 trong thu muc hien tai!')
    
    flag = True
    content1 = f1.read()
    content2 = f2.read()
    if (content2 != content1):
        flag = False
    tb = f'Hai file {filename1} va {filename2} giong nhau' \
        if flag else f'Hai file {filename1} va {filename2} khong giong nhau'
    print(tb)
    f1.close()
    f2.close()

main()