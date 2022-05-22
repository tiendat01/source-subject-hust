#include <stdio.h>
#include <string.h>

#define MAX_HS 100
#define MAX_NAME 30

// hoan doi 2 con tro
void swap(char **p1, char **p2) {
    char *temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    char ds[MAX_HS][MAX_NAME];
    char *ptr[MAX_HS], *temp;
    int count = 0;
    char lenh;
    while (1)
    {
        printf("\nMenu lenh: \n1. Bo sung ds\n2. Sap xep ds\n3. In ds\nKhac. Ket thuc\n");
        scanf("%c", &lenh);
        getchar();
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
                gets(ds[count]);
                //if (strlen(ds[count]) == 0) break;
                ptr[count] = ds + count;
                count++;
            //}
                break;

            case '2':
            // chuc nang sap xep ds theo thu tu abc
                for (int i = 0; i < count-1; i++) {
                    for (int j = i+1; j < count; j++) {
                        if (strcmp(ptr[i], ptr[j]) > 0) { // ten truoc lon hon ten sau
                            // temp = ptr[i]; ptr[i] = ptr[j]; ptr[j] = temp; // chu y: day la con tro. Neu gan bang chuoi ta phai dung ham strcpy
                            swap(ptr[i], ptr[j]);
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
                    printf("%d. %s\n", i+1, ptr[i]);
                }
                break;
        }
    }
    return 0;
}