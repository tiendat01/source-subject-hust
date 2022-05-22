#include <iostream>

using namespace std;

#define MAX 100000

void pruferCode (int n, int cay[MAX][2]) {
    int deg[MAX];                                                   // mang luu so bac cua moi nhan dan
    int prufer_code[MAX];                                           // mang luu ma prufer
    int nhan[MAX];                                                  // mang luu gia tri nhan cua moi dinh
    int nhan_min = 1;
    int deg_min = 1;

    // Tinh so bac cua cac nhan
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            for (int k = 0; k < 2; k++) {
                if (cay[j][k] == i) deg[i]++;
            }
        }
    }

    // luu gia tri cac nhan vao 1 mang
    for (int i = 0; i < n; i++) nhan[i] = i;


    for (int i = 1; i < n; i++) {
        // theo tinh chat cua cay luon ton tai it nhat 2 dinh = 1 nen deg_min luon = 1.
        // tim nhan co gia tri nho nhat khac 0 co bac la nho nhat = 1.
        for (int j = 1; j < n; j++) {
            if (nhan[j] > 0 && deg[j] == deg_min) {
                nhan_min = nhan[j];
                break;
            }
        }
        // tim nhan ke cua nhan_min tim duoc.
        // sau do ha bac cua nhan_min va nhan ke, dong thoi xoa bo gia tri cua nhan_min (thay bang -1) va
        // gan nhan ke cua nhan_min vao mang luu ma prufer.
        for (int j = 0; j < n; j++) {
            if (cay[j][0] == nhan_min && deg[cay[j][1]] != 0) {
                deg[nhan[cay[j][1]]]--;
                deg[nhan[cay[j][0]]]--;
                nhan[cay[j][0]] = -1;
                prufer_code[i-1] = nhan[cay[j][1]];
                break;
            }
            if (cay[j][1] == nhan_min && deg[cay[j][0]] != 0) {
                deg[nhan[cay[j][0]]]--;
                deg[nhan[cay[j][1]]]--;
                nhan[cay[j][1]] = -1;
                prufer_code[i-1] = nhan[cay[j][0]];
                break;
            }
        }
    }
    cout << endl;
    // in ra ma prufer cua cay
    for (int i = 0; i < n-2; i++) cout << prufer_code[i] << " ";

}

int main()
{
    int e, n, cay[MAX][2];                                                         // khai bao so canh e, so dinh n, cay theo ds canh, ma prufer
    cout << "Input (so canh va danh sach canh cua cay):" << endl;
    cin >> e;                                                                      // nhap vao so canh cua cay
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < 2; j++)
            cin >> cay[i][j];
    }
    n = e + 1;

    //int n = 10, cay[MAX][2] = {{0,2},{0,3},{2,4},{2,6},{2,9},{6,1},{6,5},{9,7},{9,8}};
    //int n = 10, cay[100][2] = {{8,4},{9,7},{7,6},{6,4},{4,2},{2,1},{1,5},{5,3},{3,0}};
    //int n = 20, cay[100][2] = {{3,2},{4,18},{5,2},{2,9},{12,11},{13,7},{7,6},{14,8},{8,10},{10,6},{16,1},{1,15},{15,6},{17,6},{18,6},{6,0},{19,11},{11,9},{9,0}};
    pruferCode(n,cay);
    return 0;
}


// Tren kia chac chan ko phai la code toi uu. Thay hoac cac ban khac co y tuong hay hon, nhat la de toi uu code, thi em mong nhan duoc
// y tuong tu thay va cac ban khac a. Em cam on.
