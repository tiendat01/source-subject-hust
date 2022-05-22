# 3. Chuyển các chữ cái đầu các từ thành chữ hoa, các chữ cái
# còn lại thành chữ thường.
# Ví dụ: người sử dụng nhập vào
# “Xin cHao caC bAn”
# Kết quả in ra là:
# “Xin Chao Cac Ban”

def main():
    s = str(input('Nhap vao 1 xau ky tu: '))
    x = s.split()
    for i in range(0, len(x)):
        word = x[i][0].upper() + x[i][1:len(x[i])].lower()
        x[i] = word
    s = ' '.join(x) # ' ' is separate
    print(s)

main()