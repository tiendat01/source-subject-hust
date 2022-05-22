#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   map<T, double> res;
   for (auto i : a) {
       bool flag = false;
       for (auto j : b) {
           if (i.first == j.first) {
               flag = true;
               res.insert({i.first, max(i.second, j.second)});
                break;
           }
       }
       if (!flag) res.insert({i.first, i.second});
   }

   for (auto i : b) {
       bool flag = false;
       for (auto j : a) {
           if (i.first == j.first) {
               flag = true;
               res.insert({i.first, max(i.second, j.second)});
                break;
           }
       }
       if (!flag) res.insert({i.first, i.second});
   }

   return res;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   map<T, double> res;
   for (auto i : a) {
       for (auto j : b) {
           if (i.first == j.first) {
               res.insert({i.first, min(i.second, j.second)});
           }
       }
   }
   return res;
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
