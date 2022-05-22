# Bài 4.3 Lập chương trình thực hiện các công việc sau:
# - Nhập một số nguyên dương bất kỳ nhỏ hơn 1000
# - Tính tổng các chữ số của số đó. Ví dụ: số 123 có tổng các chữ số là 1+2+3=6.
# - Thông báo kết quả ra màn hình.
# Chú ý:
# - Sử dụng vòng lặp while để làm
# - Nếu giá trị nhập vào lớn hơn hoặc bằng 1000 thì in ra màn hình ERROR.

def main():
    N = int(input('Nhap N = '))
    S = 0
    while N > 0:
        S += N % 10
        N //= 10
    print(f'S = {S}')

main()