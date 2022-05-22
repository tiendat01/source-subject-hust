# Bài 3.2 Lập chương trình thực hiện các công việc sau:
# - Nhập số thực bất kì
# - Tính chu vi , diện tích của hình tròn.
# Chú ý: Giá trị .
# Nếu giá trị đầu vào không thỏa mãn điều kiện, chương trình in ra màn hình
# chữ ERROR và kết thúc.

import math
def main():
    r = float(input('Nhap so thuc r (r>0) bat ky: '))
    if r <= 0:
        print('ERROR')
        return None
    print(f'Chu vi hinh tron: {2*math.pi*r}')
    print(f'Dien tich hinh tron: {r*r*math.pi}')

main()