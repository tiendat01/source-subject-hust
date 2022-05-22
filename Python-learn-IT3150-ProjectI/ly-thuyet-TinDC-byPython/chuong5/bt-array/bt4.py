# 4. Cho mảng a gồm N phần tử đã được sắp xếp theo
# thứ tự tăng dần. Lập trình nhập và chèn số X vào
# mảng sao cho mảng vẫn giữ nguyên thứ tự.

def main():
    a = []
    n = int(input('Nhap vao so N: '))
    for i in range(0, n):
        a.append(int(input(f'Nhap so nguyen a[{i}] = ')))
    a.sort(reverse=False) # tang dan
    x = int(input('Nhap so X can chen vao: '))
    if x < a[0]:
        a.insert(0, x)
    if x > a[n-1]:
        a.append(x)
    for i in range(0, n-1):
        if a[i] < x and x <= a[i+1]:
            a.insert(i+1, x)
    for i in range(0, len(a)):
        print(f'{a[i]} ', end='')
main()