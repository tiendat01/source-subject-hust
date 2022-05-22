# Bài 4.1 Viết chương trình
# - Nhập vào số nguyên bất kỳ.
# - Tính giai thừa của .
# Chú ý:
# - Sử dụng vòng lặp for để giải quyết bài toán.
# - Nếu dữ liệu đầu vào không đúng mô tả của đề bài, hiển thị ra màn hình
# "ERROR".

def main():
    n = int(input('Nhap so nguyen n < 8: '))
    if (n >= 8):
        print('ERROR')
        return None
    giaithua = 1
    for i in range (1, n+1):
        giaithua *= i
    print(f'Ket qua giai thua: {giaithua}')
main()