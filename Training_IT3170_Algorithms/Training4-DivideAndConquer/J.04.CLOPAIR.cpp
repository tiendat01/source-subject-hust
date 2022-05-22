#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    int index;
};

// tăng dần theo Ox
bool myFunctorX(Point a, Point b) {
    return a.x < b.x;
}
// tăng dần theo Oy
bool myFunctorY(Point a, Point b) {
    return a.y < b.y;
}

int N;
vector<Point> tapdiem;
vector<Point> tapdiem_y;

void input() {
    cin >> N;
    tapdiem.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> tapdiem[i].x >> tapdiem[i].y;
        tapdiem[i].index = i;
    }
    tapdiem_y.assign(tapdiem.begin(), tapdiem.end());
    sort(tapdiem.begin(), tapdiem.end(), myFunctorX);
    sort(tapdiem_y.begin(), tapdiem_y.end(), myFunctorY);
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x)
              + (a.y - b.y) * (a.y - b.y));
}

// using this if the number of points <= 3
double min_dist(int left, int right, int& istart, int& iend) {
    double mindist = FLT_MAX;
    for (int i = left; i < right; i++) {
        for (int j = i+1; j <= right; j++) {
            double tmp = distance(tapdiem[i], tapdiem[j]);
            if (mindist > tmp) {
                mindist = tmp;
                istart = tapdiem[i].index;
                iend = tapdiem[j].index;
            }
        }
    }
    return mindist;
}

// [left, right] <=> [0, n-1]
// tapdiem[left, right] : sắp xếp tăng dần theo Ox
// y_tapdiem[left, right] : sắp xếp tăng dần theo Oy
// chú ý: y_tapdiemm.size() == right-left+1
double divide_and_merge(int left, int right, int &istart, int &iend, vector<Point> y_tapdiem) {
    if (right - left <= 2)
        return min_dist(left, right, istart, iend); // O(1)
    else {
        int mid = (left + right) >> 1;
        int isl, iel; // index start left, index end left
        int isr, ier; // index start right, index end right
        vector<Point> l_tapdiem_y; // rut gọn y_tapdiem theo left : [left, mid]
        vector<Point> r_tapdiem_y; // rut gọn y_tapdiem theo right: [mid+1, right]

        // rut gon y_tapdiem => O(n)
        // i < right-left+1
        int cnt = 0;
        for (int i = 0; i < y_tapdiem.size(); i++) {
            // if (l_tapdiem_y.size() <= mid-left) {
            //     if (y_tapdiem[i].x < tapdiem[mid].x)
            //         l_tapdiem_y.push_back(y_tapdiem[i]);
            //     else if (y_tapdiem[i].x == tapdiem[mid].x) {
            //         if (y_tapdiem[i].y < tapdiem[mid].y)
            //             l_tapdiem_y.push_back(y_tapdiem[i]);
            //     }
            //     else 


            //         r_tapdiem_y.push_back(y_tapdiem[i]);
            // }
            // else
            //     r_tapdiem_y.push_back(y_tapdiem[i]);

            if (cnt < mid-left+1 && ( (y_tapdiem[i].x < tapdiem[mid].x) || (y_tapdiem[i].x == tapdiem[mid].x && y_tapdiem[i].y <= tapdiem[mid].y) ) ) {
                l_tapdiem_y.push_back(y_tapdiem[i]);
                cnt++;
            }
            else 
                r_tapdiem_y.push_back(y_tapdiem[i]);
        }

        double dl = divide_and_merge(left, mid, isl, iel, l_tapdiem_y);
        double dr = divide_and_merge(mid+1, right, isr, ier, r_tapdiem_y);
        double d = min(dl, dr); // cận trên của min
        if (dl < dr) {istart = isl, iend = iel;}
        else {istart = isr, iend = ier;}

        // merge solution left and right half
        // tìm tập điểm sao cho cách điểm mid 1 khoảng < d theo Ox

        // vector<Point> chosen;
        // for (int i = 0; i < N; i++) {
        //     if (abs(tapdiem[i].x - tapdiem[mid].x) < d)
        //         chosen.push_back(tapdiem[i]);
        // }
        // sort(chosen.begin(), chosen.end(), myFunctorY); // O(nlognlogn)

        vector<Point> chosen;

        for (int i = 0; i < N; i++) {
            if (abs(y_tapdiem[i].x - tapdiem[mid].x) < d)
                chosen.push_back(y_tapdiem[i]); // don't need sort
        }
        // cout << d << endl;
        // cout << 'c' << endl;
        // for (int i = 0; i < chosen.size(); i++) cout << chosen[i].x << ' ' << chosen[i].y << endl;

        // độ phức tạp = ?
        for (int i = 0; i < chosen.size()-1; i++) {
            for (int j = i+1; j < chosen.size(); j++) {
                if (chosen[j].y - chosen[i].y < d) {
                    double tmp = distance(chosen[i], chosen[j]);
                    if (d > tmp) {
                        d = tmp;
                        istart = chosen[i].index;
                        iend = chosen[j].index;
                    }
                }
            }
        }
        return d;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << fixed;
    int istartmin, iendmin;
    double ans = divide_and_merge(0, N-1, istartmin, iendmin, tapdiem_y);
    if (istartmin < iendmin)
        cout << istartmin << ' ' << iendmin << ' ';
    else    
        cout << iendmin << ' ' << istartmin << ' ';
    cout << setprecision(6) << ans;
    return 0;
}





// 55 points
// #include <bits/stdc++.h>
// using namespace std;

// struct Point {
//     int x;
//     int y;
//     int index;
// };

// // tăng dần theo Ox
// bool myFunctorX(Point a, Point b) {
//     return a.x < b.x;
// }
// // tăng dần theo Oy
// bool myFunctorY(Point a, Point b) {
//     return a.y < b.y;
// }

// int N;
// vector<Point> tapdiem;
// vector<Point> tapdiem_y;

// void input() {
//     cin >> N;
//     tapdiem.resize(N);
//     for (int i = 0; i < N; i++) {
//         cin >> tapdiem[i].x >> tapdiem[i].y;
//         tapdiem[i].index = i;
//     }
//     tapdiem_y.assign(tapdiem.begin(), tapdiem.end());
//     sort(tapdiem.begin(), tapdiem.end(), myFunctorX);
//     sort(tapdiem_y.begin(), tapdiem_y.end(), myFunctorY);
// }

// double distance(Point a, Point b) {
//     return sqrt((a.x - b.x) * (a.x - b.x)
//               + (a.y - b.y) * (a.y - b.y));
// }

// // using this if the number of points <= 3
// double min_dist(int left, int right, int& istart, int& iend) {
//     double mindist = FLT_MAX;
//     for (int i = left; i < right; i++) {
//         for (int j = i+1; j <= right; j++) {
//             double tmp = distance(tapdiem[i], tapdiem[j]);
//             if (mindist > tmp) {
//                 mindist = tmp;
//                 istart = tapdiem[i].index;
//                 iend = tapdiem[j].index;
//             }
//         }
//     }
//     return mindist;
// }

// // [left, right] <=> [0, n-1]
// double divide_and_merge(int left, int right, int &istart, int &iend) {
//     if (right - left <= 2)
//         return min_dist(left, right, istart, iend); // O(1)
//     else {
//         int mid = (left + right) >> 1;
//         int isl, iel; // index start left, index end left
//         int isr, ier; // index start right, index end right
//         double dl = divide_and_merge(left, mid, isl, iel);
//         double dr = divide_and_merge(mid+1, right, isr, ier);
//         double d = min(dl, dr); // cận trên của min
//         if (dl < dr) {istart = isl, iend = iel;}
//         else {istart = isr, iend = ier;}

//         // merge solution left and right half
//         // tìm tập điểm sao cho cách điểm mid 1 khoảng < d theo Ox
//         // vector<Point> chosen;
//         // for (int i = 0; i < N; i++) {
//         //     if (abs(tapdiem[i].x - tapdiem[mid].x) < d)
//         //         chosen.push_back(tapdiem[i]);
//         // }
//         // sort(chosen.begin(), chosen.end(), myFunctorY); // O(nlognlogn)

//         vector<Point> chosen;
//         for (int i = 0; i < N; i++) {
//             if (abs(tapdiem_y[i].x - tapdiem[mid].x) < d)
//                 chosen.push_back(tapdiem_y[i]); // don't need sort
//         }        

//         for (int i = 0; i < chosen.size(); i++) {
//             for (int j = i+1; j < i+1+7; j++) {
//                 if (j < chosen.size()) {
//                     if (chosen[j].y - chosen[i].y < d) {
//                         double tmp = distance(chosen[i], chosen[j]);
//                         if (d > tmp) {
//                             d = tmp;
//                             istart = chosen[i].index;
//                             iend = chosen[j].index;
//                         }
//                     }
//                 }
//                 else break;
//             }
//         }
//         return d;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     input();
//     cout << fixed;
//     int istartmin, iendmin;
//     double ans = divide_and_merge(0, N-1, istartmin, iendmin);
//     if (istartmin < iendmin)
//         cout << istartmin << ' ' << iendmin << ' ';
//     else    
//         cout << iendmin << ' ' << istartmin << ' ';
//     cout << setprecision(6) << ans;
//     return 0;
// }