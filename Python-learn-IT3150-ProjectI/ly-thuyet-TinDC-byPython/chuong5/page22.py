# Lập trình nhập vào mảng N số nguyên, in ra các số
# vừa nhập, tìm phần tử (chỉ số + giá trị) có giá trị
# tuyệt đối lớn nhất

def main():
    a = []
    while True:
        n = int(input('Cho so phan tu cua mang: '))
        if n > 0 and n <= 100:
            break
        else: print('Moi nhap lai: ')
    for i in range(0, n):
        a.append(int(input(f'a[{i}] = ')))

    max_abs = a[0]
    max_index = 0
    for i in range(1, n):
        if abs(max_abs) < abs(a[i]):
            max_abs = a[i]
            max_index = i
    
    print(f'Phan tu co gia tri tuyet doi lon nhat: a[{max_index}] = {max_abs}')

main()
