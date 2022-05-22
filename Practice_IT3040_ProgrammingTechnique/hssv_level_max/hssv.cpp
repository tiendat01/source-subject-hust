#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct SinhVien {
    char *hoten;
    char gioitinh[5]; // nam, nu, khac
    char mssv[10];
    struct Birthday { int ngay; int thang; int nam;} sinhnhat;
    float diem;

    //SinhVien & operator= (const SinhVien &sv2);
};

struct Node {
    SinhVien *data;
    Node *next;
};

struct ListSV {
    Node *first;
};

// Khoi tao danh sach sinh vien:
void initList(ListSV *&listsv) {
    listsv = new ListSV;
    listsv->first = NULL;
}

SinhVien* inputInfo() {
    SinhVien *sv = new SinhVien;
    if (sv == NULL) {
        cout << "Het bo nho. Khong the khoi tao!";
        return NULL;
    }
    char tmp[100];

    cout << "Nhap ho ten sinh vien: ";
    //gets(tmp);
    fgets(tmp, 100, stdin);
    sv->hoten = new char[strlen(tmp)+1];
    strcpy(sv->hoten, tmp);

    cout << "Nhap gioi tinh: "; gets(sv->gioitinh);

	cout << "Nhap ngay sinh: "; cin >> sv->sinhnhat.ngay; getchar();
	cout << "Nhap thang sinh: "; cin >> sv->sinhnhat.thang; getchar();
	cout << "Nhap nam sinh: "; cin >> sv->sinhnhat.nam; getchar();

    cout << "Nhap ma so sinh vien: "; gets(sv->mssv);

    cout << "Nhap diem mon KTLT: "; cin >> sv->diem; getchar();

    FILE *input = fopen("data.txt", "a");
    fprintf(input, "%s\n", sv->hoten);
    fprintf(input, "%s\n", sv->gioitinh);
    fprintf(input, "%d/%d/%d\n", sv->sinhnhat.ngay, sv->sinhnhat.thang, sv->sinhnhat.nam);
    fprintf(input, "%s\n", sv->mssv);
    fprintf(input, "%f\n", sv->diem);
    fclose(input);

    return sv;
}

Node* createNode(SinhVien *sv) {
    Node *new_node = new Node;
    if (new_node == NULL) {
        cout << "Het bo nho. Khong the khoi tao them!";
        return NULL;
    }
    new_node->data = sv;
    new_node->next = NULL;
    return new_node;
}

void outputDS(ListSV *list) {
    FILE *save = fopen("output.txt", "w");

    Node *tmp = list->first;
    if (tmp == NULL) {
        cout << "Danh sach rong!" << endl;
        fprintf(save, "Danh sach rong!\n");
        return ;
    }
    int stt = 1;

    cout << "Danh sach sinh vien: " << endl;
    fprintf(save, "Danh sach sinh vien: \n");

    while (tmp != NULL) {
        cout << stt << ". ";
        cout << "Ho ten: " << tmp->data->hoten;
        cout << "Gioi tinh: " << tmp->data->gioitinh << endl;
        cout << "Ngay thang nam sinh: " << tmp->data->sinhnhat.ngay << "/" << tmp->data->sinhnhat.thang << "/" << tmp->data->sinhnhat.nam << endl;
        cout << "Ma so sinh vien: " << tmp->data->mssv << endl;
        cout << "Diem mon KTLT: " << tmp->data->diem << endl;

        fprintf(save, "%d. ", stt);
        fprintf(save, "Ho ten: %s", tmp->data->hoten);
        fprintf(save, "Gioi tinh: %s\n", tmp->data->gioitinh);
        fprintf(save, "Ngay thang nam sinh: %d/%d/%d\n", tmp->data->sinhnhat.ngay, tmp->data->sinhnhat.thang, tmp->data->sinhnhat.nam);
        fprintf(save, "Ma so sinh vien: %s\n", tmp->data->mssv);
        fprintf(save, "Diem mon KTLT: %f\n", tmp->data->diem);

        tmp = tmp->next;
        stt++;
    }
    fclose(save);


}

int vitriTen(char *str) {
    int i = strlen(str)-1;
    // i > -1 : "nguyentiendat"
    while ((i > -1) && (str[i] == ' ')) i--; // "nguyen tien dat___" , str[i] la ky tu 'd
    while ((i > -1) && (str[i] != ' ')) i--; // "__________________"
    return i+1;
}

void addNode(Node *new_node, ListSV *&listsv) {
    if (listsv->first == NULL) {
        listsv->first = new_node;
    }
    else {
        Node *ptr_pos = listsv->first;
        Node *ptr_pre_pos = listsv->first;

        // insert to head:
        // so sanh neu khac ten
        if (strcmp((new_node->data->hoten + vitriTen(new_node->data->hoten)),
        (listsv->first->data->hoten + vitriTen(listsv->first->data->hoten))) < 0) {

            new_node->next = listsv->first;
            listsv->first = new_node;
            return ;
        }

        // neu trung ten => so sanh ho
        if (strcmp((new_node->data->hoten + vitriTen(new_node->data->hoten)),
        (listsv->first->data->hoten + vitriTen(listsv->first->data->hoten))) == 0) {

            if (strcmp(new_node->data->hoten, listsv->first->data->hoten) < 0) {
                new_node->next = listsv->first;
                listsv->first = new_node;
                return ;
            }
        }

        // find postion
        while (ptr_pos->next != NULL &&
        strcmp((new_node->data->hoten + vitriTen(new_node->data->hoten)),
        (ptr_pos->data->hoten + vitriTen(ptr_pos->data->hoten))) > 0 ) {
            ptr_pre_pos = ptr_pos;
            ptr_pos = ptr_pos->next;
        }

        // neu ten trung nhau phai so sanh ho
        if (strcmp((new_node->data->hoten + vitriTen(new_node->data->hoten)),
        (ptr_pos->data->hoten + vitriTen(ptr_pos->data->hoten))) == 0) {
            while (ptr_pos->next != NULL &&
            strcmp(new_node->data->hoten, ptr_pos->data->hoten) > 0) {
                ptr_pre_pos = ptr_pos;
                ptr_pos = ptr_pos->next;
            }
        }

        // insert last
        if (ptr_pos->next == NULL) {
            ptr_pos->next = new_node;
            return ;
        }

        // con lai la insert middle
        new_node->next = ptr_pre_pos->next;
        ptr_pre_pos->next = new_node;
        return ;
    }
}

void deleteNode(ListSV *&listsv) {
    if (listsv->first == NULL) {
        cout << "Danh sach rong!";
        return ;
    }
    char mssv_del[100];
    cout << "Nhap ma so cua sinh vien can xoa: ";
    gets(mssv_del);

    Node *ptr_pos = listsv->first, *ptr_pre_pos = listsv->first;
    while (ptr_pos != NULL && (strcmp(ptr_pos->data->mssv, mssv_del) != 0)) {
        ptr_pre_pos = ptr_pos;
        ptr_pos = ptr_pos->next;
    }
    if (ptr_pos == NULL) {
        cout << "Khong co ma so sinh vien nay!";
        return ;
    }
    else if (ptr_pos == listsv->first) {
        listsv->first = listsv->first->next;
        delete ptr_pos;
        return ;
    }
    else if (ptr_pos->next == NULL) {
        ptr_pre_pos->next = NULL;
        delete ptr_pos;
        return ;
    }
    ptr_pre_pos->next = ptr_pos->next;
    delete ptr_pos;
}


void outputNode(Node *tmp) {
    cout << "Ho ten: " << tmp->data->hoten << endl;
    cout << "Gioi tinh: " << tmp->data->gioitinh << endl;
    cout << "Ngay thang nam sinh: " << tmp->data->sinhnhat.ngay << "/" << tmp->data->sinhnhat.thang << "/" << tmp->data->sinhnhat.nam << endl;
    cout << "Ma so sinh vien: " << tmp->data->mssv << endl;
    cout << "Diem mon KTLT: " << tmp->data->diem << endl;
}

void search(ListSV *listsv) {
    char input[100];
    cout << "Nhap ho ten hoac ma so cua sinh vien can tim: "; gets(input);
    Node *ptr_pos = listsv->first;
    while (ptr_pos != NULL) {
        if (strcmp(ptr_pos->data->hoten, input) == 0) break;
        if (strcmp(ptr_pos->data->mssv, input) == 0) break;
        ptr_pos = ptr_pos->next;
    }
    if (ptr_pos == NULL) {
        cout << "Khong co sinh vien nay!";
        return ;
    }
    outputNode(ptr_pos);
}

void freeMem(ListSV *&listsv) {
    Node *tmp = NULL;
    while (listsv->first != NULL) {
        tmp = listsv->first;
        listsv->first = listsv->first->next;
        delete tmp->data->hoten;
        delete tmp->data;
        delete tmp;
    }
}

int main() {
    ListSV *dssv;
    initList(dssv);

    while (1) {
        system("cls");
        printf("        CHUONG TRINH QUAN LY SINH VIEN:");
        printf("    \nMenu: ");
        printf("\n 1. Bo sung 1 sinh vien vao danh sach (tu dong sap xep theo kieu Viet Nam).");
        printf("\n 2. In danh sach (da sap xep) va luu vao file \"output.txt\".");
        printf("\n 3. Xoa 1 sinh vien.");
        printf("\n 4. Tim kiem thong tin 1 sinh vien.");
        printf("\n 5. Import du lieu tu file \"data.txt\".");
        printf("\n Bam phim 1,2,3,4,5 de chon. Bam phim bat ky # de ket thuc.");

        char choice;
        printf("\n\nLua chon cua ban: "); scanf("%c", &choice); getchar();
        if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5') {
            printf("Chuong trinh ket thuc");
            break;
        }
        switch (choice) {
            case '1': {
                addNode(createNode(inputInfo()), dssv); }
                break;

            case '2': {
                outputDS(dssv);
                system("pause"); }
                break;

            case '3': {
                deleteNode(dssv);
                system("pause"); }
                break;

            case '4': {
                search(dssv);
                system("pause"); }
                break;

            case '5': {
                char hoten[50];
                float diem;

                FILE *imple_data = fopen("data.txt", "r");
                    while (feof(imple_data) == 0) {
                        SinhVien *new_node = new SinhVien;
                        if (new_node == NULL) {
                            cout << "Het bo nho. Khong the khoi tao!";
                            return NULL;
                        }
                        fgets(hoten, 100, imple_data);
                        new_node->hoten = new char[strlen(hoten) + 1];
                        strcpy(new_node->hoten, hoten);
                        fscanf(imple_data, "%s\n%d/%d/%d\n%s\n%f\n", 
                        new_node->gioitinh, &(new_node->sinhnhat.ngay), &(new_node->sinhnhat.thang), &(new_node->sinhnhat.nam), 
                        new_node->mssv, &(new_node->diem));
                        // printf("%s%s\n%d/%d/%d\n%s\n%f\n", new_node->hoten, new_node->gioitinh,
                        // new_node->sinhnhat.ngay, new_node->sinhnhat.thang, new_node->sinhnhat.nam,
                        // new_node->mssv, new_node->diem);
                        addNode(createNode(new_node), dssv);
                    }
                fclose(imple_data);

                system("pause");

                }
                break;

        }
    }

    freeMem(dssv);

    delete dssv;
}
