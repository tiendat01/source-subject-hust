# Viết 1 chương trình thực hiện những công việc sau:
# • Yêu cầu người dùng nhập vào một số nguyên
# dương n với 5  n  20 (có kiểm tra tính hợp lệ của
# giá trị được nhập vào, nếu giá trị n nhập vào không
# thỏa mãn điều kiện thì yêu cầu nhập lại)
# • Yêu cầu người dùng nhập vào thông tin của n sinh
# viên gồm những mục sau
# – Họ và tên: có kiểu dữ liệu là xâu kí tự gồm không quá 30
# kí tự
# – Lớp: xâu kí tự có độ dài không quá 5 kí tự
# – Điểm thi Tin đại cương: là một số nguyên có giá trị từ 0
# đến 10
# • Đưa ra màn hình danh sách các sinh viên cùng
# thông tin mà người dùng vừa nhập vào.
# • Yêu cầu người dùng nhập vào từ bàn phím một số
# thực. Đưa ra màn hình danh sách các sinh viên có
# điểm thi Tin đại cương nhỏ hơn giá trị số thực vừa
# nhập vào.
# • Đưa ra màn hình danh sách sinh viên được sắp xếp
# theo chiều giảm dần của điểm thi Tin đại cương.

class sinhvien:
    def __init__(self) -> None:
        self.hoten = ''
        self.lop = ''
        self.diemthiTDC = 0

def outputds(ds):
    print('Danh sach cac sinh vien:')
    print('{0:>3}  {1:<30} {2:<5} {3:<2}'.format('STT', 'HOTEN', 'LOP', 'DIEMTHI'))
    for i in range(0, len(ds)):
        print(f'{i+1:>3}. {ds[i].hoten:<30} {ds[i].lop:<5} {ds[i].diemthiTDC:<2}')

# ds sv co diemthiTDC < diem
def outputds_condition(ds, diem):
    print(f'Danh sach cac sinh vien co diemthiTDC < {diem}:')
    print('{0:>3}  {1:<30} {2:<5} {3:<2}'.format('STT', 'HOTEN', 'LOP', 'DIEMTHI'))
    for i in range(0, len(ds)):
        if ds[i].diemthiTDC < diem:
            print(f'{i+1:>3}. {ds[i].hoten:<30} {ds[i].lop:<5} {ds[i].diemthiTDC:<2}')

def diem(sv):
    return sv.diemthiTDC

def main():
    n = int(input('Nhap so nguyen duong n voi 5<=n<=20: '))
    while n < 5 or n > 20:
        n = int(input('Nhap sai! Moi nhap lai n = '))
    ds = []
    for i in range(0, n):
        sv = sinhvien()
        print(f'Nhap thong tin cho sinh vien {i+1}: ')
        sv.hoten = input('Nhap ho ten: ')
        while len(sv.hoten) > 30:
            sv.hoten = input('Ten dai qua 30 ky tu. Moi nhap lai ho ten: ')

        sv.diemthiTDC = int(input('Nhap diem thi Tin dai cuong: '))
        while sv.diemthiTDC < 0 or sv.diemthiTDC > 10:
            sv.diemthiTDC = int(input('Invalid. Nhap lai diem thi Tin dai cuong: '))

        sv.lop = input('Nhap ten lop: ')
        while len(sv.lop) > 5:
            sv.lop = input('Ten lop dai qua 5 ky tu. Moi nhap lai ten lop: ')

        ds.append(sv)

    outputds(ds)
    diem_muc = int(input('Nhap diem muc: '))
    outputds_condition(ds, diem_muc)
    ds.sort(key=diem, reverse=True)
    outputds(ds)
    
main()