#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int n = 0, ts = 1;
char **ds, ht_tmp[100];

void bosung();
void sapxep_vn();
void indssv();
int vitriTen(char *str);


int main() {
    ds = new char* [ts];

    printf("        CHUONG TRINH QUAN LY SINH VIEN:");
    printf("    \nMenu: ");
    printf("\n 1. Bo sung danh sach.");
    printf("\n 2. Sap xep danh sach theo kieu Viet Nam.");
    printf("\n 3. In danh sach.");
    printf("\n Bam phim 1,2,3 de chon. Bam phim bat ky # de ket thuc.");

    while (1) {
        char choice;
        printf("\n\nLuc chon cua ban: "); scanf("%c", &choice); getchar();
        if (choice != '1' && choice != '2' && choice != '3') {
            printf("Chuong trinh ket thuc");
            break;
        }
        switch (choice)
        {
        case '1':
            bosung();
            break;
        
        case '2':
            sapxep_vn();
            break;

        case '3':
            indssv();
            break;
        }
    }
    for (int i = 0; i < n; i++) delete[] ds[i];
    delete[] ds;
}

void bosung() {
    while (1) {
        printf("\nNhap vao ho ten sinh vien thu %d: ", n+1);
        gets(ht_tmp);
        if (ht_tmp[0] == '\0') break;

        ds[n] = new char[strlen(ht_tmp)+1]; // mang rang cua
        strcpy(ds[n], ht_tmp);              // strcpy() chi copy noi dung o nho
                                            // neu ds[n] = ht_tmp: khi do con tro ds[n] se bi thay doi !!! => nguy hiem
        n++;

        // neu muon mo rong ds => tai cap phat bo nho
        if (n >= ts) {
            ts++;
            char **ds_trung_gian = new char* [ts];
            for (int i = 0; i < n; i++) ds_trung_gian[i] = ds[i];
            delete[] ds;
            ds = ds_trung_gian;              // khi do ds da tang len 1
        }

    }
}

int vitriTen(char *str) {
    int i = strlen(str)-1;
    // i > -1 : "nguyentiendat"
    while ((i > -1) && (str[i] == ' ')) i--; // "nguyen tien dat___" , str[i] la ky tu 'd
    while ((i > -1) && (str[i] != ' ')) i--; // "__________________"
    return i+1;
}

void sapxep_vn() {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp((ds[i] + vitriTen(ds[i])), (ds[j] + vitriTen(ds[j]))) > 0) {
                char *tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
            // truong hop 2 sv cung ten khac ho
            if (strcmp((ds[i] + vitriTen(ds[i])), (ds[j] + vitriTen(ds[j]))) == 0) {
                if (strcmp(ds[i], ds[j]) > 0) {
                    char *tmp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = tmp;
                }
            }
        }
    }
    cout << "Danh sach da duoc sap xep xong!";
}

void indssv() {
    printf("DANH SACH SINH VIEN: ");
    for (int i = 0; i < n; i++) {
        printf("\n%d. %s", i+1, ds[i]);
    }
}