# Bài 3.6 Lập chương trình thực hiện các công việc sau:
# - Nhập 2 số thực
# - Tính giá trị của biểu thức

def main():
    x = float(input('Nhap x: '))
    y = float(input('Nhap y: '))
    f = 0
    for i in range(0,7):
        f += x**i * y**(6-i)
        # or (y**7 - x**7) / (y - x)
    print(f'Ket qua: {f}')
main()