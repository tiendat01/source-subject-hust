# Ví dụ 1: Thao tác với tệp văn bản
# Nhập thông tin điểm thi toán, lý, hóa từ bàn phím
# Ghi các điểm này vào tệp văn bản có tên
# “my_score.txt”.
# Đọc từ tệp trên, tính điểm trung bình và in kết quả
# ra màn hình.

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)
def main(): 
    print('Nhap diem thi Toan Ly Hoa:')
    dToan = float(input())
    dLy = float(input())
    dHoa = float(input())
    f = open(curdir+'\\my_score.txt', 'w') # /my_score.txt cũng đc
    f.write(f'{dToan}\n{dLy}\n{dHoa}\n')
    f.close()

    # using with => don't need to close()
    with open(curdir+'\\my_score.txt', 'r') as f:
        dT = float(f.readline())
        dL = float(f.readline())
        dH = float(f.readline())
    dTB = (dT + dL + dH) / 3
    print(f'Diem trung binh: {dTB}')
main()

# def main(): 
#     print('Nhap diem thi Toan Ly Hoa:')
#     dToan = float(input())
#     dLy = float(input())
#     dHoa = float(input())
#     f = open('my_score.txt', 'w')
#     f.write(f'{dToan}\n{dLy}\n{dHoa}\n')
#     f.close()

#     # using with => don't need to close()
#     with open('my_score.txt', 'r') as f:
#         dT = float(f.readline())
#         dL = float(f.readline())
#         dH = float(f.readline())
#     dTB = (dT + dL + dH) / 3
#     print(f'Diem trung binh: {dTB}')
# main()