# 4. Viết chương trình nhập vào số n có 3 chữ số,
# in ra màn hình số n theo chiều ngược lại.

def main():
    n = int(input('Nhap vao so n co 3 chu so: '))
    print(f'So n theo chieu nguoc lai: {str(n)[::-1]}') # slice str start at the end of str(n) & backward: -1

if __name__ == '__main__':
    main()