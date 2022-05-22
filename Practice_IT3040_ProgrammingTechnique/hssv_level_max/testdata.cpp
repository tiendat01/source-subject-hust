#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct birthday{
    int date;
    int month;
    int year;
};

int main() {
    char hoten[50];
    char gt[5];
    birthday b;
    char mssv[10];
    float diem;

    FILE *data = fopen("data.txt", "r");
    while (feof(data) == 0) {
        fgets(hoten, 100, data);
        fscanf(data, "%s\n%d/%d/%d\n%s\n%f\n", gt, &b.date, &b.month, &b.year, mssv, &diem);
        printf("%s%s\n%d/%d/%d\n%s\n%f\n", hoten, gt, b.date, b.month,b.year,mssv, diem);
    }
    

    fclose(data);
}