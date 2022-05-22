# 2. Đếm số từ có trong câu. Giả sử giữa các từ chỉ có 1 dấu cách.
# Ví dụ: người sử dụng nhập vào
# “Xin chao cac ban”
# Kết quả in ra là: 4 từ

def main():
    s = str(input('Nhap vao 1 xau ky tu: '))
    x = s.split()
    print(f'So tu trong cau: {len(x)}')

main()
    