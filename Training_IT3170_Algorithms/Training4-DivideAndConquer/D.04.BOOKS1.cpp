#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull m, k; // m books and k scibers
vector<ull> pages;
ull ans;

void input() {
    cin >> m >> k;
    pages.resize(m);
    for (ull i = 0; i < m; i++) {
        cin >> pages[i];
    }
}

bool check(ull maxsum) {
    ull count_scibers = 0;
    ull count_cur_pages = 0;
    for (ull i = 0; i < m; i++) {
        if (pages[i] > maxsum) // 1 book chỉ gán cho 1 scriber => maxsum phai tang len
            return true;
        if (count_cur_pages + pages[i] > maxsum) {
            count_scibers++;
            count_cur_pages = 0;
            i--;
        }
        else {
            count_cur_pages += pages[i];
        }
    }
    count_scibers++; // scriber cuối    
    return count_scibers > k; // đúng nếu với maxsum: tất cả k scribers được gán ít nhất 1 books
                                // nếu số scribers tính được > k => maxsum chưa đủ lớn
}

ull maxsum_binary_search(ull low, ull high) {
    if (low >= high) 
        return ans;
    else {
        ull mid = (low + high) >> 1;
        // cout << low << ' ' << high << endl;
        if (check(mid)) {
            return maxsum_binary_search(mid+1, high);
        }
        else {
            ans = mid;
            return maxsum_binary_search(low, mid);
        }
    }
}

// hàm khó nhất
void print(int pos , int k , ull maxsum){
    ull count = 0;
    int pos_till = -1;
    // gán từ cuối lên
    for(int i = pos ; i>= 0 ; i--){
        // gán cho 1 scriber:
        if(count + pages[i] > maxsum || i == k-2){
            print(i , k-1  , maxsum); // chuyển sang scriber tiếp theo
            pos_till = i;
            break;
        }
        count += pages[i];
    }

    // neo đệ quy
    // TH đầu tiên i = 0, k = 1 => pos_till = -1
    if(pos_till >= 0)
        cout << "/ ";
    for(int i = pos_till + 1; i <= pos; i++)
        cout << pages[i] << " ";
}

int main() {
    int N; // test case
    cin >> N;
    ull low = 0, high = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        input();
        // page.size()-1 sẽ là chỉ số cuối của mảng pages
        print(pages.size()-1, k, maxsum_binary_search(low, high));
        cout << endl;
    }
    return 0;
}

// 3
// 9 3
// 100 200 300 400 500 600 700 800 900
// 5 4
// 100 100 100 100 100
// 5 3
// 30 60 80 50 20