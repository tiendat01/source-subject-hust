# Bài 5.6 Lập chương trình thực hiện các công việc sau:
# - Nhập vào từ bàn phím một câu tiêu đề bài báo bất kỳ.
# - Chuẩn hóa xâu đã nhập bằng cách xóa các dấu cách thừa ở đầu, cuối, giữa để
# đảm bảo chỉ có 1 dấu cách phân tách giữa các từ và chuyển các chữ cái thường
# thành chữ hoa tương ứng.
# - Đưa câu tiêu đề đã được chuẩn hóa ra màn hình.

def main():
    s = str(input('Nhap vao 1 xau ky tu: '))
    x = s.split()
    s = ' '.join(x)
    print(f'{s.upper()}:{len(s)}')
main()

#    Xin   chao   cac  ban     