#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
 
int main(){
    srand((int)time(0));
    int x[MAX], y[MAX];
    int n = 1000, m = 1000;
    for(int i = 1; i <= n; ++i){
        x[i] = i;
        y[i] = random(1,n);
    }
    FILE *file;
    file = fopen("dothi.txt", "w");
    fprintf(file, "%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        fprintf(file, "%d %d\n", x[i], y[i]);
    }
    fclose(file);
}