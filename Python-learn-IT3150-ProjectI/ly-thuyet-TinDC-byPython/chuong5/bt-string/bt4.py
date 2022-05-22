# 4. In ra xâu theo chiều ngược lại.
# Ví dụ: người sử dụng nhập vào
# “Xin chao cac ban”
# Chương trình sẽ in ra
# “nab cac oahc niX”

def main():
    s = str(input('Nhap vao 1 xau ky tu: '))
    res = ''
    for i in range(len(s)-1, -1, -1):
        res += s[i]
    print(res)

main()