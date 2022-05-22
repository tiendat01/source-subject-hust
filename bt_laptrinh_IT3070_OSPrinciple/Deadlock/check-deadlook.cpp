#include <iostream>
#include <vector>

using namespace std;

vector<int> Available = {7, 2, 6};      // tai nguyen ban dau trong he thong
vector< vector<int> > Max = { {0,1,0}, {4,0,2}, {3,0,3}, {3,1,1}, {6,0,4} };  // tai nguyen toi da ma TT can de nhan CPU
vector< vector<int> > Allocation = {{0,1,0}, {2,0,0}, {3,0,3}, {2,1,1}, {0,0,2}};   // tai nguyen da cap cho TT
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

bool operator!= (vector<int> a, int number) {
    for (unsigned int i = 0; i < a.size(); i++) {
        if (a.at(i) != 0) 
            return false;
    }
    return true;
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

bool isDeadlock(vector<int> CurrentResourse) {
    vector<bool> finish (n, false); // TT da finished chua???


    // do he thong cho phep cac TT yeu cau thoai mai den khi CurrentResiource = 0 thi kiem tra be tac
    // vong for nay khac voi thuat giai isSafe (banker algorithm)
    // co nghia la ....
    for (int i = 0; i < n; i++) {
        if (Allocation.at(i) != 0)
            finish.at(i) = false; // dang doi TN
        else    
            finish.at(i) = true; // chua cap phat cho TT, TT moi ko trong hang doi
        
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; i++) 
                // check cac TT chua hoan thanh dang yeu cau TN
                if (finish.at(i) == false && Need.at(i) <= CurrentResourse) {
                    // TT co du TN => thuc hien xog va giai phong
                    finish.at(i) = true;
                    CurrentResourse = CurrentResourse + Allocation.at(i);
                    flag = true;
                } // endif
        } // endwhile

    }
    
    for (int i = 0; i < n; i++) 
        if (finish.at(i) == false) return true; // bi deadlock
        
    return false; // he thong an toan
}

int main() {
    calNeed();
    cout << "Kiem tra deadlock cua he thong: " ;
    if (isDeadlock(calCurrentResource()))
        cout << "He thong gap be tac!" << endl;
    else 
        cout << "He thong an toan!" << endl;

    return 0;
}