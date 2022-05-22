// #include <iostream> 
// #include <vector>

// using namespace std;

// vector <int> result;

// vector<int> input() {
// 	vector<int> rVector;
// 	int n; cin >> n;
// 	for (int i = 0; i <= n; i++) {
// 		int tmp;
// 		cin >> tmp;
// 		rVector.push_back(tmp);
// 	}
// 	return rVector;
// }

// int sum (vector<int> a) {
// 	int sum = 0;
// 	for (int i = 0; i < a.size(); i++) {
// 		sum += a[i];
// 	}
// 	return sum;
// }

// void multi(vector<int> a, vector<int> b) {
// 	vector < vector<int> > all(a.size() + b.size() - 1);
// 	for (int i = 0; i < a.size(); i++) {
// 		for (int j = 0; j < b.size(); j++) {
// 			int tmp = a[i] * b[j];
// 			all.at(i+j).push_back(tmp);
// 		}
// 	}

// 	// for (const auto &v : all) {
//     //     for (int it : v) {
//     //         cout << it << ' ';
//     //     }
//     //     cout << endl;
//     // }

// 	for (int i = 0; i < all.size(); i++) {
// 		result.push_back(sum(all.at(i)));
// 		// cout << result.at(i) << " ";
// 	}
// 	// cout << endl;

	
// }



// int main() {
// 	vector<int> a = input(), b = input();
	
// 	multi(a,b);

// 	int out = (int)(result.at(0)+ 0.5);
	
// 	for (int i = 1; i < result.size(); i++) {
// 		out ^= (int)(result.at(i)+0.5);
//  	}
	
// 	cout << out;
// }

#include <iostream>

using namespace std;

struct Poly {
	int bac;
	int *heso;
};

void input(Poly &poly) {
	cin >> poly.bac;
	poly.heso = new int[poly.bac + 1];
	for (int i = 0; i <= poly.bac; i++) {
		cin >> poly.heso[i];
	}
}

void multi(Poly poly1, Poly poly2, Poly &res) {
	res.bac = poly1.bac + poly2.bac;
	res.heso = new int[res.bac + 1];
	for (int i = 0; i <= res.bac; i++) {
		res.heso[i] = 0;
		for (int j = 0; j <= poly1.bac; j++) {
			if (i-j >= 0 && i-j <= poly2.bac) res.heso[i] += poly1.heso[j] * poly2.heso[i-j];
		}
	}
}

int main() {
	Poly p1, p2, result;
	input(p1);
	input(p2);
	multi(p1,p2,result);
	
	int out = result.heso[0];
	for (int i = 1; i <= result.bac; i++) out ^= result.heso[i];
	cout << out;
}