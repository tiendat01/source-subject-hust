# Bài 5.3 Nhập mảng 𝑛 số nguyên bất kỳ từ bàn phím. Sắp xếp dãy số theo thứ tự
# tăng dần và đưa kết quả ra màn hình (Mỗi phần tử cách nhau một dấu cách)

def main():
    a = []
    n = int(input('Nhap vao so N: '))
    for i in range(0, n):
        a.append(int(input(f'Nhap so nguyen a[{i}] = ')))
    a.sort(reverse=False) # tang dan
    print(a)
main()