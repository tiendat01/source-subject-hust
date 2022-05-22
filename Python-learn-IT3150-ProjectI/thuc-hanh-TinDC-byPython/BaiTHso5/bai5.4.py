# Bài 5.4 Viết một chương trình nhập một chuỗi S và số nguyên n. Chương trình
# sẽ cắt chuỗi đó theo số nguyên n.

def main():
    s = input('Nhap chuoi S: ')
    n = int(input('Nhap so nguyen n: '))
    split_res = [s[i:i+n] for i in range(0, len(s), n)] # list comprehension
    print(split_res)
main()