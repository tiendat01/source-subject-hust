# #include <stdio.h>
# #include <conio.h>
# int i; // Bien toan cuc
# int binhphuong(int x){
# int y; // Bien cuc bo
# y = x * x;
# return y;
# }
# void main(){
# int y; // Bien cuc bo
# for (i=0; i<= 10; i++){
# y = binhphuong(i);
# printf(“%d ”, y);
# }
# }

global i # bien toan cuc
def binhphuong(x):
    y = x * x
    return y

def main():
    global i
    for i in range(0, 11):
        y = binhphuong(i);
        print(f'{y} ', end='')

main()