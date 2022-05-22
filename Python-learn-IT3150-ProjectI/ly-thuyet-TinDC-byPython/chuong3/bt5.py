# 5. Viết chương trình nhập vào 1 ký tự, sau đó
# in ra mã ASCII của ký tự đó.

def main():
    ch = input('Nhap vao mot ky tu: ').split(' ')[0][0]
    print(f'Ma ASCII cua ky tu {ch} la: {ord(ch)}') 
    # ord() convert a char to an integer
    # chr() convert an ASCII code (int) to a char

main()