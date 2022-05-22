#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//void swap(char &(*p1), char &(*p2)) {

//}

int main() {
    int soHs, soKyTuTen = 30;
    printf("Nhap vao so hoc sinh: ");
    cin >> soHs;

    char *temp;

    // char **ptr = new char*[soHs];
    
    char **ds = new char* [soHs];
    for (int i = 0; i < soHs; i++) 
        ds[i] = new char[soKyTuTen];

    int count = 0;
    char lenh; 
    while (1)
    {
        printf("\nMenu lenh: \n1. Bo sung ds\n2. Sap xep ds\n3. In ds\nKhac. Ket thuc\n");
        // scanf("%c", &lenh);
        // getchar();
        cin >> lenh;
        if (lenh != '1' && lenh != '2' && lenh != '3') {
            printf("Ket thuc chuong trinh.");
            break;
        }
        switch (lenh)
        {
        case '1':
            // chuc nang bo sung ds:
            //while (count < MAX_HS) {
                printf("Enter the name of students %d: ", count);
                cin >> ds[count];
                //if (strlen(ds[count]) == 0) break;
                // ptr[count] = (*ds) + count;
                count++;
            //}
            break;

        case '2':
            // chuc nang sap xep ds theo thu tu abc
            for (int i = 0; i < count-1; i++) {
                for (int j = i+1; j < count; j++) {
                    if (strcmp(ds[i], ds[j]) > 0) { // ten truoc lon hon ten sau
                        temp = ds[i]; ds[i] = ds[j]; ds[j] = temp; // chu y: day la con tro. Neu gan bang chuoi ta phai dung ham strcpy  
                    }
                }
            }
            break;
    
    case '3': 
            // chuc nang in ra man hinh ds:
            // printf("\n%d\n", strlen(ds[1]));
            // printf("\n%s\n", ds[0]);
            printf("DANH SACH HOC SINH:\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s\n", i, ds[i]);
            }
            break;
        }
    }
    for (int i = 0; i < soHs; i++) {
        delete[] ds[i];
    }
    delete[] ds;
    // delete[] ptr;
}