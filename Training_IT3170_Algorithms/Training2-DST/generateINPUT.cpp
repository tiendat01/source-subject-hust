#include <bits/stdc++.h>

using namespace std;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

// PROBLEM I
// int main() {
//     srand(time(NULL));
//     ofstream os ("input.txt");
//     int n = 50;
//     os << n << endl;
//     for (int i = 0; i < n; i++) {
//         int rand = random(1,4);
//         switch (rand)
//         {
//         case 1:
//             os << '(';
//             break;
//         case 2:
//             os << ')';
//             break;
//         case 3:
//             os << '[';
//             break;
//         case 4:
//             os << ']';
//             break;
//         default:
//             break;
//         }
//     }
//     os << endl;
//     os.close();
//     return 0;
// }


int main() {
    srand(time(NULL));
    ofstream os("input.txt");
    int n = random(2, 100);
    os << n << endl;
    for (int i = 0; i < n; i++) {
        long long in = random(1, 100);
        os << in << ' ';
    }
    os.close();
    return 0;
}