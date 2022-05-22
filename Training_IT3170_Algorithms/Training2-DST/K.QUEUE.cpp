// #include <bits/stdc++.h>

// using namespace std;

// int pos_furthest(const vector<long long>& q, int start, int end, long long val) {
//     int i = end;
//     for (; i >= start; i--) {
//         if (q[i] < val)
//             return i;
//     }
//     return 0;
// }

// int main() {
//     int n;
//     vector <long long> queue;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         long long input;
//         cin >> input;
//         queue.push_back(input);
//     }
//     for (int i = 0; i < n-1; i++) {
//         int res = pos_furthest(queue, i+1, n-1, queue[i]);

//         if (res) cout << (res - i - 1) << ' ';
//         else cout << -1 << ' ';
//     }
//     cout << -1;
//     return 0;
// }


// O(nlogn)
#include <bits/stdc++.h>

using namespace std;

struct my_type {
    int index;
    unsigned long long value;
};

int n;
vector<unsigned long long> hangdoi;

// find element
// v is decrease
int b_search_index(const vector<my_type>& v, int i_start, int i_end, unsigned long long target) {
    if (i_start >= i_end) {
        if (hangdoi[v[i_start].index] >= target) 
            return v[i_start+1].index;
        else 
            return v[i_start].index;
    } 
    else {
        int mid = (i_start + i_end) >> 1;
        if (v[mid].value >= target) {
            return b_search_index(v, mid+1, i_end, target);
        }
        else {
            return b_search_index(v, i_start, mid-1, target);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        unsigned long long input;
        cin >> input;
        hangdoi.push_back(input);
    }
    vector<int> res;
    vector<my_type> decrease_values; 

    // duyet tu cuoi mang <=> dau hang doi
    decrease_values.push_back({n-1, hangdoi[n-1]});
    res.push_back(-1);
    for (int i = n-2; i >= 0; i--) {
        // value nho hon add vao cuoi mang decrease
        if (hangdoi[i] <= decrease_values.back().value) {
            res.push_back(-1);
            decrease_values.push_back({i, hangdoi[i]});
        }
        // neu ko thuc hien tim chi so cua value co gia tri nho hon 'vua du' hangdoi[i] trong mang decrease
        else {
            int index = b_search_index(decrease_values, 0,  decrease_values.size()-1, hangdoi[i]);
            res.push_back(index - i - 1);
        }
    }
    reverse(res.begin(), res.end());
    cout << res.front();
    for (int i = 1; i < res.size(); i++) {
        cout << ' ' << res[i];
    }
    return 0;
}



/*
13
18 9 8 9 23 20 18 18 33 25 31 37 36
=>
2 0 -1 -1 2 1 -1 -1 1 -1 -1 0 -1 
*/