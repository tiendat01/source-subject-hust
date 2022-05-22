# Xóa các dấu cách dư thừa
# Ví dụ: người sử dụng nhập vào
# “   Xin   chao   cac  ban     ”
# Chương trình sẽ in ra
# “Xin chao cac ban”

def main():
    s = str(input('Nhap vao 1 xau ky tu: '))
    x = s.split()
    s = ' '.join(x)
    print(s)
    print(len(s))
main()

