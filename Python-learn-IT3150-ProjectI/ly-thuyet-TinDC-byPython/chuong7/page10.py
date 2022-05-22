# #include <stdio.h>
# #include <conio.h>
# int binhphuong(int x){
# int y;
# y = x * x;
# return y;
# }
# int main(){
# int i;
# for (i=0; i<=10; i++)
# printf(“%d ”, binhphuong(i));
# return 0;
# }

def binhphuong(x):
    y = x * x
    return y

def main():
    for i in range(0, 11):
        print(f'{binhphuong(i)} ', end='')
main()