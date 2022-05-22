# Bài 3.4 Viết chương trình yêu cầu người dùng nhập giá chưa có thuế của một kg
# cà chua, số kg bạn muốn mua và thuế theo đơn vị phần trăm. Chương trình phải
# tính tổng giá đã bao gồm thuế.

def main():
    price = float(input('Nhap gia khong thue cua 1kg ca chua: '))
    weight = float(input('So kg ban muon: '))
    tax = float(input('Thue theo don vi phan tram: '))
    print(f'Tong gia da bao gom thue: {price * weight * (1+tax/100)}')
main()