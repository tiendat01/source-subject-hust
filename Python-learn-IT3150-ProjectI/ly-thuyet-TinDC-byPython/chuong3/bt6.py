# 6. Viết chương trình thực hiện công việc sau:
# – Nhập vào 3 điểm Toán, Lý, Hóa
# – Tính và in ra điểm trung bình 3 môn (làm tròn
# đến 2 chữ số thập phân)
# – Tìm và in ra điểm lớn nhất (sử dụng biểu thức
# điều kiện)
# – Tìm và in ra điểm nhỏ nhất (sử dụng biểu thức
# điều kiện)

def main():
    t = float(input('Nhap diem Toan: '))
    l = float(input('Nhap diem Ly: '))
    h = float(input('Nhap diem Hoa: '))
    print(f'Diem trung binh 3 mon: {(t + l + h)/3 :.2f}')
    print(f'Diem lon nhat: {max(t, l, h)}')
    print(f'Diem nho nhat: {min(t, l, h)}')

main()
