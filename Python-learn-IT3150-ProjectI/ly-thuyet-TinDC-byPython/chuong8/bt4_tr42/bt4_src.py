# 4. Viết chương trình ghép nối nội dung hai file:
# a. Nhập vào từ bàn phím hai xâu kí tự là đường dẫn của
# file nguồn và file đích.
# b. Ghép nội dung của file nguồn vào cuối file đích.

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    src = input('Nhap vao ten file nguon trong thu muc hien tai: ') # src.txt file nguon
    des = input('Nhap vao ten file dich trong thu muc hien tai: ') # des.txt file dich
    try:
        f1 = open(curdir+'\\'+src, 'r')
    except:
        print(f'khong ton tai file nguon {src} trong thu muc hien tai!')
    try:
        f2 = open(curdir+'\\'+des, 'a')
    except:
        print(f'khong ton tai file dich {des} trong thu muc hien tai!')
    
    content = f1.read()
    f2.write(content)
    f1.close()
    f2.close()

main()