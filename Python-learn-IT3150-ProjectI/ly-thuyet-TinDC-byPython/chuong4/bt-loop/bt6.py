# Bài 6. Tính xấp xỉ số PI theo công thức
# Với sai số epsilon nhập từ bàn phím (số hạng cuối
# cùng có giá trị tuyệt đối không lớn hơn epsilon)

import math
def main():
    epsilon = float(input('Nhap sai so epsilon: '))
    # epsilon = 0.00001
    pi_one_forth = 0
    i = 1
    dau = 0
    while True:
        x = 1.0 / i
        if x <= epsilon:
            break
        pi_one_forth += (-x) if dau else x
        dau = not dau
        i += 2 # i = 2n+1
    pi = pi_one_forth * 4
    print(f'Ket qua tinh xap xi: {pi}')

main()    