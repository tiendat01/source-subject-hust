#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct datatype{
    int value;
    int key;
};

vector<datatype> a;

void print() {
    for (const datatype &v : a) {
        cout << v.key << " " << v.value << endl;
    }
}

void input() {
    int key_tmp, value_tmp;
    while (cin >> key_tmp && cin >> value_tmp) {
        datatype tmp;
        tmp.key = key_tmp;
        tmp.value = value_tmp;
        a.push_back(tmp);
    }
}

int main() {
    input();
    sort(a.begin(), a.end(), [] (datatype left, datatype right) {
        if (left.value != right.value) return left.value > right.value;
        else return left.key >= right.key;
    });
    print();
}