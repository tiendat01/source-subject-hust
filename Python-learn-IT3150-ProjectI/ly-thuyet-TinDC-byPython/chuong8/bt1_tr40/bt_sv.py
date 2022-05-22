# => Áp dụng với mảng các đối tượng cấu trúc sinh viên gồm
# các trường: MSSV, Hoten, Diemthi

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

class sinhvien:
    def __init__(self) -> None:
        self.mssv = ''
        self.hoten = ''
        self.diemthi = 0
    def nhap(self):
        self.mssv = input('Nhap mssv: ')
        self.hoten = input('Nhap ho ten: ')
        self.diemthi = float(input('Nhap diem thi: '))
    def xuat(self):
        return (f'{self.mssv}\n{self.hoten}\n{self.diemthi}\n')

def myComparison(sv):
    return sv.diemthi

def main():
    n = int(input('Nhap so sinh vien N: '))
    while n >= 100:
        n = int(input('Nhap N qua lon. Nhap lai N:'))
    ls = []
    for i in range(0, n):
        sv_tmp = sinhvien()
        sv_tmp.nhap()
        ls.append(sv_tmp)
    with open(curdir+'\\sv.dat', 'w') as f:
        f.write(str(n)+'\n')
        for i in range(0, n):
            f.write(ls[i].xuat())
    ls_sx =[]
    with open(curdir+'\\sv.dat', 'r') as f:
        m = int(f.readline())
        for i in range(0, m):
            sv_tmp = sinhvien()
            sv_tmp.mssv = f.readline().strip()
            sv_tmp.hoten = f.readline().strip()
            sv_tmp.diemthi = float(f.readline().strip())
            ls_sx.append(sv_tmp)
    ls_sx.sort(key=myComparison, reverse=False)
    with open(curdir+'\\sv_sx.dat', 'w') as f:
        f.write(str(m)+'\n')
        for i in range(0, m):
            f.write(ls_sx[i].xuat())
main()   