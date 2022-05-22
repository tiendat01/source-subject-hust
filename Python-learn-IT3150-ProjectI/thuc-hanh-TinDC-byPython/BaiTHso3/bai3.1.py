# Bài 3.1 Lập chương trình thực hiện các công việc sau:
# - Nhập vào chương trình điểm 03 môn Toán, Lý, Hóa của 1 học sinh
# - Tính tổng điểm và điểm trung bình 03 môn của học sinh đó.

def main():
    dToan = float(input('Nhap diem Toan: '))
    dLy = float(input('Nhap diem Ly: '))
    dHoa = float(input('Nhap diem Hoa: '))
    print(f'Tong diem 3 mon: {dToan + dLy + dHoa}')
    print(f'Diem trung binh 3 mon: {(dToan + dLy + dHoa)/3}')
main()