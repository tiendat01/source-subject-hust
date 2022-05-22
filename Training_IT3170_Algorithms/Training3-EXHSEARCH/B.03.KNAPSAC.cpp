// backtrack TLE : 75 points

// #include <bits/stdc++.h>

// using namespace std;

// int n, b;
// vector< pair<int, int> > items; // pair {aj, cj} voi aj, cj > 0, aj_weight, cj_usedvalue => sigma(cj) max
// bool mark[32];
// int max_usedval = 0;
// int cur_usedval = 0;
// int cur_weight = 0;

// void input() {
//     items.push_back({-1,-1}); // bo phan tu thu 0, bat dau tu thu 1
//     cin >> n >> b;
//     for (int i = 1; i <= n; i++) {
//         int aj, cj;
//         cin >> aj >> cj;
//         items.push_back({aj, cj});
//     }
// }

// bool isUCV(int next_item) {
//     if (mark[next_item])
//         return false;
//     return true;
// }

// void Try(int kth_sol) {
//     for (int i = 1; i <= n; i++) {
//         if (isUCV(i)) {
//             cur_weight += items[i].first;
//             cur_usedval += items[i].second;
//             mark[i] = true;
//             if (cur_weight > b || kth_sol == n) {
//                 int tmp = cur_usedval - items[i].second;
//                 max_usedval = max(tmp, max_usedval);
//             }
//             else {
//                 Try(kth_sol+1);
//             }
//             cur_weight -= items[i].first;
//             cur_usedval -= items[i].second;
//             mark[i] = false;
//         }
//     }
// }

// int main() {
//     input();
//     Try(1);
//     cout << max_usedval;
//     return 0;
// }





// modify sth before backtracking
// Nhan thay, muon chon duoc max val: ta nen chon nhung items weight nho && val cao
// tuc la weight va val ti le nghich
// xet ti so val / weight

#include <bits/stdc++.h>
using namespace std;
struct dovat {
    float a; // weight
    float c; // value
};

int n, b;
vector<dovat> ds;
int load; // load lưu tổng khối lượng hiện tại
int f, f_best; // f lưu tong giá trị hiện tại

bool myFunc(dovat a, dovat b) {
    float x = (float)(a.c/a.a);
    float y = (float)(b.c/b.a);
    return x > y;
}

void input() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        dovat v;
        cin >> v.a >> v.c;
        ds.push_back(v);
    }
    sort(ds.begin(), ds.end(), myFunc); // sap xep giam dan
    ds.push_back({0,0}); // để ds[k+1].a != 0
}

bool check(int k) {
    return true;
}

void updateBest(int k) {
    f -= ds[k].c;
    f_best = max(f_best, f);
    f += ds[k].c;
}

void Try(int k) {
    // 1 hoặc 0 tương đương với lấy vào túi và ko lấy vào túi
    // mỗi loại đồ vật chỉ có số lượng là 1 (knapsac 0/1)
    for (int i = 0; i <= 1; i++) {
        if (check(k)) {
            if (i != 0) {
                load += ds[k].a;
                f += ds[k].c;
            }
            // cout << load << endl;
            if (load > b || k == n) updateBest(k);
            else {
                int g = 0;
                if (k != n-1)
                    g = (ds[k+1].c / ds[k+1].a) * (b-load);
                if (f + g > f_best) {
                    Try(k+1);
                }
            }
            if (i != 0) {
                load -= ds[k].a;
                f -= ds[k].c;
            }
        }
    }
}

int main() {
    input();
    Try(0);
    cout << f_best;
    return 0;
}