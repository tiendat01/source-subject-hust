#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
// y tuong la dung priority queue, moi lan pop ra la 1 linh

// ai la so ke dich cua 1 doan tuong i : pair.first
// ki la kha nang chong dich cua 1 doan tuong i: pair.second

struct compare {
    bool operator() (pair<int, int> lhs, pair<int, int> rhs) {
        int l, r;
        // do ai va ki triet tieu cho nhau nen chon phan tu nho hon!!!
        if (lhs.first < lhs.second) l = lhs.first;
        else l = lhs.second;
        if (rhs.first < rhs.second) r = rhs.first;
        else r = rhs.second;

        return l < r; // less -> sx priority queue giam dan, cang cao cang uu tien
    }
};

int n, s;
vector <pair<int, int>> in;
priority_queue < pair<int, int>, vector <pair<int, int>>, compare > pq;
int total_enemy = 0, killed_enemy = 0;

void input() {
    cin >> n >> s;
    int ai, ki;
    for (int i = 0; i < n; i++) {
        cin >> ai >> ki;
        in.push_back({ai, ki});
        pq.push({ai, ki});
        total_enemy += ai;
    }
}

void solve() {
    while (!pq.empty() && s > 0) {
        auto it = pq.top(); pq.pop();
        // neu 1 linh chap het ki giac 
        if (it.first < it.second) killed_enemy += it.first;
        else {
            killed_enemy += it.second * 1; // 1 linh ok?
            int enemy_conlai = it.first - it.second * 1; // tinh so giac con lai
            pq.push({enemy_conlai, it.second}); // so giac con lai cho vao cuoi hang doi, neu con linh thi xu ly tiep
        }
        s--; // dung 1 linh trong 1 lan lap
    }
}

int main() {
	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    input();
    solve();
    cout << (total_enemy - killed_enemy);
}
