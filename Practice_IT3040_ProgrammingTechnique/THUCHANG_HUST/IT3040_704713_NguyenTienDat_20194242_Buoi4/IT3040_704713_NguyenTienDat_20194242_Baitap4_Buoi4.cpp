#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct greaters {
//     bool operator()(const int& a, const int& b) const
//     {
//         return a > b;
//     }
// };


void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

bool isEven(int i) { return ((i%2) == 0); }

void delete_even(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) {
        if (*i % 2 == 0) {
            a.erase(i);
            i--;
        }
    }
}

bool isDecrease(int l, int r) { return l > r;}

void sort_decrease(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   sort(a.begin(), a.end(), isDecrease);
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   vector<int> c;
   // merge(a.begin(), a.end(), b.begin(), b.end(), c.begin(), greaters());
    for(int v : a){
        c.push_back(v);
    }

    for(int v : b){
        c.push_back(v);
    }

    sort(c.begin(), c.end(), isDecrease);
   return c;
}

int main() {
	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
