// #include <bits/stdc++.h>

// using namespace std;

// struct key {
//     int i;
//     int j;
//     bool operator<(const key& other) const {
//         return this->i < other.i 
//                 || (!(other.i < this->i) && this->j < other.j);
//     }
// };

// struct mapped
// {
//     int mapped_val = 0; // gia tri mac dinh cua cac ptu trong map
// };


// int main() {
//     int T;
//     cin >> T;
//     for (int t = 0; t < T; t++) {
//         int L, C;
//         // map<pair<int, int>, mapped> mymap;
//         // vector<pair<int,int>> img1, img2;
//         map<key, mapped> mymap;
//         vector<key> img1, img2;
//         cin >> L >> C;
//         // img1
//         for (int i = 0; i < L; i++) {
//             for (int j = 0; j < C; j++) {
//                 int input; // 0 or 1
//                 cin >> input;
//                 if (input) img1.push_back({i, j}); // lay toa do cua cac phan tu 1 (diem anh)
//             }
//         }
//         // img2
//         for (int i = 0; i < L; i++) {
//             for (int j = 0; j < C; j++) {
//                 int input; // 0 or 1
//                 cin >> input;
//                 if (input) img2.push_back({i, j}); // lay toa do cua cac phan tu 1 (diem anh)
//             }
//         }

//         int max_pixel = 0;
//         for (int i = 0; i < img1.size(); i++) {
//             for (int j = 0; j < img2.size(); j++) {
//                 // int a = img1[i].first - img2[j].first;
//                 // int b = img1[i].second - img2[j].second;
//                 // cout << a << b << endl;
//                 // mymap[{a,b}].mapped_val++;
//                 // max_pixel = max(mymap[{a,b}].mapped_val,max_pixel);
//                 int i_ordinate = img1[i].i - img2[j].i;
//                 int j_ordinate = img1[i].j - img2[j].j;
//                 // cout << i_ordinate << j_ordinate << endl;
//                 mymap[{i_ordinate, j_ordinate}].mapped_val++;
//                 max_pixel = max(max_pixel, mymap[{i_ordinate, j_ordinate}].mapped_val);

//             }
//         }

//         cout << max_pixel << endl;
//     }
//     return 0;
// }



#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int L, C;
        // map<pair<int, int>, mapped> mymap;
        // vector<pair<int,int>> img1, img2;
        map<pair<int,int>, int> mymap;
        vector<pair<int, int>> img1, img2;
        cin >> L >> C;
        // img1
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                int input; // 0 or 1
                cin >> input;
                if (input) img1.push_back({i, j}); // lay toa do cua cac phan tu 1 (diem anh)
            }
        }
        // img2
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                int input; // 0 or 1
                cin >> input;
                if (input) img2.push_back({i, j}); // lay toa do cua cac phan tu 1 (diem anh)
            }
        }

        int max_pixel = 0;
        int img1_size = img1.size();
        int img2_size = img2.size();
        for (int i = 0; i < img1_size; i++) {
            for (int j = 0; j < img2_size; j++) {
                int a = img1[i].first - img2[j].first;
                int b = img1[i].second - img2[j].second;
                mymap[{a,b}]++;
                max_pixel = max(mymap[{a,b}],max_pixel);

            }
        }

        cout << max_pixel << endl;
    }
    return 0;
}













// 60 points ??? vi với map, moi thao tac mat chi phi O(logn)
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(); cout.tie();
    int T;
    cin >> T;
    while(T>0){
        int L, C;
        cin >> L >> C;

        vector<pair<int,int> > pre,last;
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) pre.push_back({i,j});
            }

        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) last.push_back({i,j});
            }

        int maxSl = 0;
        map<pair<int,int>, int> m;
        int lensPre = pre.size();
        int lensLast = last.size();
        for(int i=0; i<lensPre; i++)
            for(int j=0; j<lensLast; j++){
                int a = last[j].first - pre[i].first + N;
                int b = last[j].second - pre[i].second + N;
                m[{a,b}]++;
                maxSl = max(m[{a,b}],maxSl);
            }

        cout << maxSl << endl;
        T--;
    }

    return 0;
}




// 100 points ???
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(); cout.tie();
    int T;
    cin >> T;
    while(T>0){
        int L, C;
        cin >> L >> C;
        vector<vector<int>> m (2001, vector<int>(2001, 0)); // mang 2 chieu
        vector<pair<int,int> > pre,last;
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) pre.push_back({i,j});
            }

        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) last.push_back({i,j});
            }

        int maxSl = 0;
        int lensPre = pre.size();
        int lensLast = last.size();
        for(int i=0; i<lensPre; i++)
            for(int j=0; j<lensLast; j++){
                int a = last[j].first - pre[i].first + N;
                int b = last[j].second - pre[i].second + N;
                m[a][b]++;
                maxSl = max(maxSl, m[a][b]);
            }

        cout << maxSl << endl;
        T--;
    }

    return 0;
}