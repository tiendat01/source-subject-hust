# Bài 5.1 Nhập mảng n số nguyên từ bàn phím, in ra màn hình các giá trị từ cuối
# đến giá trị đầu, sau đó tính tổng các phần tử của mảng.
# Chú ý:
# Nếu n <= 0 in "Error"

def main():
    n = int(input('Nhap so nguyen duong N: '))
    if n <= 0:
        print('ERROR')
        return None
    a = []
    sum = 0
    print('Nhap n so nguyen cach nhau boi enter:')
    for i in range(0, n):
        songuyen = int(input())
        a.append(songuyen)
        sum += songuyen
    print(a)
    print(f'Tong: {sum}')

main()    