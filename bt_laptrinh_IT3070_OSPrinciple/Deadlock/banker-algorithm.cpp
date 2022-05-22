#include <iostream>
#include <vector>

using namespace std;

vector<int> Available = {10, 5, 7};      // tai nguyen ban dau trong he thong
vector< vector<int> > Max = { {7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3} };  // tai nguyen toi da ma TT can de nhan CPU
vector< vector<int> > Allocation = {{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}};   // tai nguyen da cap cho TT
vector< vector<int> > Need;                                                         // tai nguyen TT can de CPU = Max - Allocation

int n = Max.size(); // so TT: P0, P1, P2 ....
int m = Available.size(); // so kieu TN : R0, R1, R2....

bool operator<= (vector<int> a, vector<int> b) {
    unsigned int size;
    if ((size = a.size()) != b.size()) return false;
    for (unsigned int i = 0; i < size; i++) 
        if (a.at(i) > b.at(i))
            return false;
    return true;
}

bool operator< (vector<int> a, vector<int> b) {
    unsigned int size;
    if ((size = a.size()) != b.size()) return false;
    for (unsigned int i = 0; i < size; i++) 
        if (a.at(i) >= b.at(i))
            return false;
    return true;
}

vector<int> operator+ (vector<int> a, vector<int> b) {
    unsigned int size;
    vector<int> res;
    if ((size = a.size()) != b.size()) { cout << "Khong cong duoc!!" << endl; }
    else {
        for (unsigned int i = 0; i < size; i++)  
            res.push_back(a.at(i) + b.at(i));
    }
    return res;
}

vector<int> operator- (vector<int> a, vector<int> b) {
    unsigned int size;
    vector<int> res;
    if ((size = a.size()) != b.size()) { cout << "Khong tru duoc!!" << endl; }
    else {
        for (unsigned int i = 0; i < size; i++)  
            res.push_back(a.at(i) - b.at(i));
    }
    return res;
}


void calNeed() {
    vector<int> need_of_process;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need_of_process.push_back((Max.at(i).at(j) - Allocation.at(i).at(j))); // co the dung - da nang hoa cho 2 vector
        }
        Need.push_back(need_of_process);
        need_of_process.erase(need_of_process.begin(), need_of_process.end());
    }
}

vector<int> calCurrentResource() {
    vector<int> sumAllocation (m, 0);
    for (int i = 0; i < n; i++)
        sumAllocation = sumAllocation + Allocation.at(i);
    return (sumAllocation <= Available ? (Available - sumAllocation) : vector<int>() ); // null vector
}

// Thuat toan kiem tra tinh an toan cua he thong
bool isSafe(vector<int> CurrentResource) {
    vector<bool> finish;
    finish.assign(n, false);
    
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < n; i++) 
            if(finish.at(i) == false && Need.at(i) <= CurrentResource) {
                finish.at(i) = true;
                CurrentResource = Allocation.at(i) + CurrentResource;
                flag = true;
            }
    }

    for (int i = 0; i < n; i++) 
        if (!finish.at(i))  
            return false;
    return true;
}

// struct request {
//     int TT;
//     int soTN;
// };

// Thuat toan kiem tra yeu cau TN co dap ung duoc khong
bool canAlloc(vector<int> currentResource, vector<int> request, int TT) {
    if (Need.at(TT) < request) {
        cout << "Error: Vuot qua khai bao so tai nguyen toi da cua TT" << endl;
        return false;
    }
    if (currentResource < request) {
        cout << "Block: Yeu cau nay phai cho doi do ko du tai nguyen cho TT" << endl;
        return false;
    }
    // thu chap nhan yeu cau:
    currentResource = currentResource - request;
    Need.at(TT) = Need.at(TT) - request;
    Allocation.at(TT) = Allocation.at(TT) + request;

    // check
    if (isSafe(currentResource)) {
        cout << "Yeu cau cap phat duoc dap ung!" << endl;
        return true;
    }

    else {
        cout << "Yeu cau cap phat chua the dap ung =====> Block do he thong co the nguy hiem!!" << endl;
        // khoi phuc trang thai
        currentResource = currentResource + request;
        Need.at(TT) = Need.at(TT) + request;
        Allocation.at(TT) = Allocation.at(TT) - request;

        return false;
    }
}

int main() {
    calNeed();

    cout << "Kiem tra tinh an toan cua he thong: " ;
    if (isSafe(calCurrentResource())) 
        cout << "He thong an toan!" << endl;
    else 
        cout << "He thong co nguy co be tac!" << endl;


    vector<int> request1 = {1, 0, 2};
    vector<int> request4 = {3, 0, 3};
    vector<int> request0 = {0, 2, 0};

    canAlloc(calCurrentResource(), request1, 1);
    canAlloc(calCurrentResource(), request4, 4);
    canAlloc(calCurrentResource(), request0, 0);

    return 0;
}