#include <iostream>
#include <string.h>

using namespace std;

struct NhanVien {
    int maNhanVien;
    char *tenNhanVien; // cap phat dong
    struct NgayThang {
        unsigned int date;
        unsigned int month;
        unsigned int year;
    } namSinh;
    int gioiTinh;
    float luong;

    NhanVien & operator= (const NhanVien &b);
};

// copy from b to *this
NhanVien & NhanVien::operator= (const NhanVien &b) {
    if (this->tenNhanVien != NULL) delete[] this->tenNhanVien;
    this->tenNhanVien = new char[strlen(b.tenNhanVien)];
    strcpy(tenNhanVien, b.tenNhanVien);
    maNhanVien = b.maNhanVien;
    namSinh.date = b.namSinh.date;
    namSinh.month = b.namSinh.month;
    namSinh.year = b.namSinh.year;
    gioiTinh = b.gioiTinh;
    luong = b.luong;

    // delete[] b.tenNhanVien;

    return *this;
}

static int soLuong = 0; // neu them/xoa ptu cua mang

void input(NhanVien *&arr) {
    if (soLuong != 0) {
        soLuong++;
        NhanVien* t = new NhanVien[soLuong];
        for (int i = 0; i < soLuong-1; i++) {
            t[i].tenNhanVien = NULL;
            t[i] = arr[i];
            delete[] arr[i].tenNhanVien;
        }
        delete[] arr;
        // user input
        cout << "Nhap ma nhan vien: ";
        cin >> ((t+soLuong-1)->maNhanVien); cin.ignore();

        cout << "Nhap ten nhan vien (khong qua 50 ky tu): ";
        char tmp[50];
        fgets(tmp, 50, stdin);
        // cap phat bo nho cho xau dong
        (t+soLuong-1)->tenNhanVien = new char[strlen(tmp)];
        strcpy((t+soLuong-1)->tenNhanVien, tmp);

        cout << "Nhap ngay thang nam: ";
        cin >> t[soLuong-1].namSinh.date >> t[soLuong-1].namSinh.month >> t[soLuong-1].namSinh.year; cin.ignore();
        cout << "Nhap gioi tinh (1:nam 0:nu): ";
        cin >> (t+soLuong-1)->gioiTinh; cin.ignore();
        cout << "Nhap Luong: ";
        cin >> (t+soLuong-1)->luong; cin.ignore();

        arr = t;    
    }
    
    else {
        soLuong++;
        arr = new NhanVien[soLuong];
        cout << "Nhap ma nhan vien: ";
        cin >> ((arr)->maNhanVien); cin.ignore();

        cout << "Nhap ten nhan vien (khong qua 50 ky tu): ";
        char tmp[50];
        fgets(tmp, 50, stdin);
        // cap phat bo nho cho xau dong
        arr->tenNhanVien = new char[strlen(tmp)];
        strcpy(arr->tenNhanVien, tmp);

        cout << "Nhap ngay thang nam: ";
        cin >> (arr->namSinh).date >> (arr->namSinh).month >> (arr->namSinh).year; cin.ignore();
        cout << "Nhap gioi tinh (1:nam 0:nu): ";
        cin >> ((arr)->gioiTinh); cin.ignore();
        cout << "Nhap Luong: ";
        cin >> ((arr)->luong); cin.ignore();
    }
}

void output(const NhanVien *arr) {
    cout << "Danh sach nhan vien: " << endl;
    for (int i = 0; i < soLuong; i++) {
        printf("\n%d.\tTen nhan vien: %s", i, arr[i].tenNhanVien);
        printf("\n\tMa nhan vien: %d", arr[i].maNhanVien);
        printf("\n\tNgay/thang/nam sinh: %d/%d/%d", arr[i].namSinh.date, arr[i].namSinh.month, arr[i].namSinh.year);
        cout << "\n\tGioi tinh: " << (arr[i].gioiTinh ? "Nam" : "Nu");
        printf("\n\tLuong: %f", arr[i].luong);
    }
}

void printTT(const NhanVien *arr) {
    printf("\n\tTen nhan vien: %s", arr->tenNhanVien);
    printf("\n\tMa nhan vien: %d", arr->maNhanVien);
    printf("\n\tNgay/thang/nam sinh: %d/%d/%d", arr->namSinh.date, arr->namSinh.month, arr->namSinh.year);
    cout << "\n\tGioi tinh: " << (arr->gioiTinh ? "Nam" : "Nu");
    printf("\n\tLuong: %f", arr->luong);
}

NhanVien* sapXepLuongGiam(const NhanVien *arr) {
    NhanVien *res = new NhanVien[soLuong];
    for (int i = 0; i < soLuong; i++) {
        res[i].tenNhanVien = NULL;
        res[i] = arr[i];
    }
    for (int i = soLuong-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            if (res[i].luong > res[j].luong) {
                NhanVien tmp; 
                tmp.tenNhanVien = NULL; 
                tmp = res[i]; delete[] res[i].tenNhanVien;
                res[i].tenNhanVien = NULL;
                res[i] = res[j]; delete[] res[j].tenNhanVien;
                res[j].tenNhanVien = NULL;
                res[j] = tmp; delete[] tmp.tenNhanVien;
            }
        }
    }
    return res;
    // dung xong nho giai phong res!!!
}


// cac ham sau: xau dua vao phai duoc chuan hoa!!
char* substr(const char* s, size_t pos, size_t length) {
    // 1 th ngoai le: pos > strlen(s) va pos < 0
    char *res = new char[length+1];
    for (int i = 0; i < length; i++) 
        res[0] = s[pos+i];
    return res;
    // dung xong nho giai phong res!!!
} 

size_t find(const char *src, const char *des) {
    int pos = 0;
    bool flag;
    for (int i = 0; i <= strlen(src)-strlen(des); i++) {
        flag = true;
        for (int j = 0; j < strlen(des); j++) {
            if(src[i+j] != des[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            pos = i;
            break;
        }
    }
    if (flag) return pos;
    else return -1;
}

void tachTen(const NhanVien *arr) {

}

void tuDaiNhat(const NhanVien *arr) {

}

int main() {
    NhanVien *dsnv; // bien struct cap phat dong
    input(dsnv);
    input(dsnv);
    input(dsnv);
    output(dsnv);

    cout << endl << "Danh sach sau khi sap xep: \n";

    NhanVien *ds_sort = sapXepLuongGiam(dsnv);  
    output(ds_sort);
    cout << endl;
    output(dsnv);

    // giai phong tp mang dong cua bien struct trc roi moi giai phong bien struct 
    for (int i = 0; i < soLuong; i++) {
        delete[] dsnv[i].tenNhanVien;
        delete[] ds_sort[i].tenNhanVien;
    }
    delete[] dsnv;
    delete[] ds_sort;
    return 0;
}