#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
using namespace std;
#define M_PI		3.14159265358979323846
long long N, F;  // N pies and F friends
vector<double> radii;

vector<double> size_of_pie;
double ans;
double maxpie = 0.0;

void input() {
    cin >> N >> F;
    radii.assign(N, 0);
    size_of_pie.assign(N, 0);
    for (long long i = 0; i < N; i++) {
        cin >> radii[i];
        size_of_pie[i] = (M_PI * radii[i] * radii[i] * 1); // height = 1
        maxpie = max(size_of_pie[i], maxpie);
    }
}

// volumn is the largest size of pies for everyone
bool check(double volumn) {
    long long friends_after_divide = 0;
    for (long long i = 0; i < N; i++) {
        friends_after_divide += (long long)floor(size_of_pie[i] / volumn);
    }
    return F < friends_after_divide; // đúng nếu chia đủ/thừa cho F friends and me
}

// chia so thuc => ko bao gio low >= high được
// O(nlog(n))
double ans_binary_search(double low, double high) {
    if (high - low < 1e-7) 
        return ans;
    else {
        double mid = (low + high) / 2.0;
        if (check(mid)) {
            ans = mid;
            return ans_binary_search(mid, high);
        }
        else {
            return ans_binary_search(low, mid);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        input();
        cout << fixed;
        cout << setprecision(6) << ans_binary_search(0.0, maxpie) << endl;
        // printf("%.6lf", ans_binary_search(0.0, maxpie));
    }
    return 0;
}


// có nhiều pie: nhiều size, nhiều taste nhg có chung hình dáng là hình trụ, chiều cao  = 1
// phải tìm 1 max size sao cho
// 1 pie (các pie khác nhau nhg đều tròn) 
// có thể chia thành Vpie/maxsize miếng bánh dành cho (long long)Vpie/maxsize người bạn
