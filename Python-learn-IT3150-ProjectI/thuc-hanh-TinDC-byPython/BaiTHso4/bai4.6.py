# Bài 4.6 Viết chương trình tính các tổng sau:
# a)
# b)
# c)
# Trong đó là một số nguyên dương và là một số thực bất kỳ được nhập vào từ
# bàn phím khi chạy chương trình.
# Chú ý:
# - Sử dụng vòng lặp while để làm
# - Kiểm tra dữ liệu đầu vào của chương trình, nếu không đúng thì kết thúc chương
# trình và in ra màn hình ERROR.

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
    if n <= 0:
        print('ERROR')
        return None
    n1 = n
    s1 = 0
    while n1 < 0:
        s1 += x**n1
        n1 -= 1
    n2 = n
    s2 = 0
    while n2 < 0:
        s2 += x**n2 * (1 if n2 % 2 == 0 else -1)
        n2 -= 1
    n3 = n
    s3 = 0
    while n3 < 0:
        s3 += x**n3 / giaithua(n3)
        n3 -= 1
    print(f's1 = {s1}')
    print(f's2 = {s2}')
    print(f's3 = {s3}')

main()    