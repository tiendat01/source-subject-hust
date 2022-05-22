// ver 1 : O(n^3)
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int n;
// vector<int> in;
// int maxArea = 0;

// void input() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int tmp;
//         cin >> tmp;
//         in.push_back(tmp);
//     }
// }

// void solve() {
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             vector<int> tmp;
//             for (int k = i; k <= j; k++) {
//                 tmp.push_back(in[k]);
//             }
//             int max_tmp = tmp.size() * (*min_element(tmp.begin(), tmp.end()));
//             if (maxArea < max_tmp) maxArea = max_tmp;
//         }
//     }
// }

// int main() {
//     input();
//     solve();
//     cout << maxArea;
//     return 0;
// }

// ver2: O(n^2)
//  #include <iostream>
//  #include <vector>
//  using namespace std;

//  vector<int> in;
//  int n;
//  int area = 0;
//  int max_area = 0;

//  void input() {
//  	cin >> n;
//  	int tmp;
//  	for (int i = 0; i < n; i++) {
//  		cin >> tmp;
//  		in.push_back(tmp);
//  	}
//  }

//  void solve() {
//  	for (int i = 0; i < n; i++) {
//  		int j = i, k = i;
//  		while (in[j-1] >= in[i] && j > 0) j--;
//  		while (in[k+1] >= in[i] && k < n-1) k++;
//  		area = in[i] * (k-j+1); 
//  		if (area > max_area) max_area = area;
//  	}
//  }

//  int main() {
//  	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
//  	input();
//  	solve();
//  	cout << max_area;
//  	return 0;
//  }



// ver : su dung stack => hack nao???
#include <iostream>
#include <stack>
#include<vector>
using namespace std;

int i;
int top;
int maxArea = 0;
int area = 0;

int maxS(vector <int> a, int n) {
    // int tmp;
	// for (int i = 0; i < n; i++) {
	// 	cin >> tmp;
	// 	a.push_back(tmp);
	// }
	stack <int> s;
	for (i = 0; i < a.size(); ) {
		if (s.empty() || a[i] >= a[s.top()]) {
			s.push(i);
            i++;
        }
		else {
			top = s.top();
			s.pop();
			if (s.empty()) {
				area = i * a[top];
			cout << endl << "area = " << area << endl;
			}
			else {
				area = a[top] * (i - s.top() - 1);
			cout << endl << "area = " << area << endl;

			}
			if (area > maxArea)
				maxArea = area;
		}
	}
	while (!s.empty()) {
		top = s.top();
		s.pop();
		if (s.empty()) {
			area = i * a[top];
		}
		else {
			area = a[top] * (i - s.top() - 1);
		}
		if (area > maxArea)
			maxArea = area;
	}
	return maxArea;
}
int main() {
	vector<int> a {6, 2, 5, 4, 5, 1, 6};
	int n = 7;	
	// cin >> n;
	cout << maxS(a, n);
}
