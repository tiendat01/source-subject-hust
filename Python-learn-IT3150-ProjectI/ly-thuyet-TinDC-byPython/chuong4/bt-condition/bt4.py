# Bài 4: Nhập vào một năm bất kỳ, kiểm tra xem
# năm đó có phải là năm nhuận không?

def is4Divisible(a):
    return (a & 3) == 0

def main():
    year = int(input('Nhap vao mot nam bat ky: '))
    if (is4Divisible(year) and year % 100 != 0) or year % 400 == 0:
        print('la nam nhuan')
    else:
        print('khong la nam nhuan')

main()