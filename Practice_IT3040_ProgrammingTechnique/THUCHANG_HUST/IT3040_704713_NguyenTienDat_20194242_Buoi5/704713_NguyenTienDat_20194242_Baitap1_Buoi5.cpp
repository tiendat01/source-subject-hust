#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    // print("\n"); // viet sai chinh ta lenh printf
    // sua loi:
    printf("\n");
}

void process(int i) {
    if (i > n){
        // printf(); // sai chinh ta lenh print da dinh nghia
        // sua loi:
        print();
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    printf("Ho ten: Nguyen Tien Dat\n MSSV: 20194242\n");
    n = 5;
    process(1);
    return 0;
}