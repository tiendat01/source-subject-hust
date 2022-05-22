# Ví dụ:
# – Khai báo một cấu trúc gồm họ tên và điểm thi
# Tin đại cương
# – Khai báo mảng tên là lop gồm 60 phần tử có
# kiểu trên
# – Nhập thông tin cho mảng trên và hiển thị kết
# quả.

class sinhvien:
    def __init__(self) -> None:
        self.hoten = ''
        self.diemthiTHDC = 0
    
def main():
    n = 3
    lop = []
    for i in range(0, n):
        sv = sinhvien()
        print(f'Nhap thong tin cho sinh vien {i+1}: ')
        sv.hoten = input('Nhap ho ten: ')
        sv.diemthiTHDC = int(input('Nhap diem thi Tin dai cuong: '))
        lop.append(sv)
    print('Danh sach sinh vien: ')
    for i in range(0, n):
        print(f'{i+1:>3}. Ho ten: {lop[i].hoten:<20} Diem: {lop[i].diemthiTHDC:<3}')

main()