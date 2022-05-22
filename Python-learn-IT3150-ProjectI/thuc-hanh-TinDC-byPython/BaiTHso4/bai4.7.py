# Bài 4.7 Lập chương trình thực hiện các công việc sau:
# Viết một chương trình yêu cầu người dùng nhập các giá trị của x và n và tính các
# biểu thức sau:
# (n dấu căn bậc 2)
# Chú ý:
# - Hiện thị kết quả 4 số sau dấu phẩy, các số trên 1 dòng
# - Nếu n < 1 và x <0 hiển thị "Error"

import math
def giaithua(a):
    if a < 0:
        ket_qua = -1
    elif a == 0:
        ket_qua = 1
    else:
        ket_qua = 1
        for i in range(1, a+1):
            ket_qua *= i
    return ket_qua



def main():
    n = int(input('Nhap so nguyen duong N: '))
    x = float(input('Nhap so thuc x: '))
    if n <= 0 or x < 0:
        print('ERROR')
        return None
    s1 = x
    for i in range(0, n+1):
        s1 = math.sqrt(s1)
    s2 = 1
    for i in range(1, n+1):
        s2 += x**i / i
    s3 = 1
    for i in range(1, n+1):
        s3 += x**i / giaithua(i)
    s4 = 1
    for i in range(1, n+1):
        s4 += x**i * (1 if i % 2 == 0 else -1) / giaithua(i)
    print(f's1 = {s1}')
    print(f's2 = {s2}')
    print(f's3 = {s3}')
    print(f's4 = {s4}')

main()    