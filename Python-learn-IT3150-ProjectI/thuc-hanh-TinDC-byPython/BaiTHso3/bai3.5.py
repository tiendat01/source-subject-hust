# Bài 3.5 Lập chương trình thực hiện các công việc sau:
# - Nhập 3 số thực bất kì.
# - Tính giá trị biểu thức:

import math
def main():
    x = float(input('Nhap x: '))
    y = float(input('Nhap y: '))
    z = float(input('Nhap z: '))
    f = ((x+y+z)/(x**2+y**2+1)) - abs(x-z*math.cos(y))
    print(f'Ket qua: {f}')

main()