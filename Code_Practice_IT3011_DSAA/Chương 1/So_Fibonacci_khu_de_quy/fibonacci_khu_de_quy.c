#include <stdio.h>

// day fibo 1,1,2,3,5,8,13,21,34,...
int FiboNoRecursion(int vitri) {
    int i = 1, j = 1;
    int temp;
    if (vitri == 1 || vitri == 2) return 1;
    for (int k = 3; k <= vitri; k++) {
        temp = j;
        j = i + j;
        i = temp;
    } 
    return j;
}

int main() {
    printf("%d", FiboNoRecursion(7));
}