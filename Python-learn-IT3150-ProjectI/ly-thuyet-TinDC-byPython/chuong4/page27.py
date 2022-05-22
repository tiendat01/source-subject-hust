# • Ví dụ: Đưa ra màn hình các số nguyên lẻ nhỏ hơn 100
# #include <stdio.h>
# void main()
# {
# int i;
# for(i = 1; i < 100; i += 2)
# {
# printf(“%5d”,i);
# if((i+1)%20 ==0) printf(“\n”);
# }
# }

def main():
    for i in range(1, 100, 2):
        print(f'{i:>5d}', end='')
        if ((i+1) % 20 == 0): print('')

main()