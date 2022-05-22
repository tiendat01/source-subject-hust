#include <bits/stdc++.h>
using namespace std;

int N;
bool visited[10];
char c[] = {' ', 'I', 'C', 'T', 'H', 'U', 'S', 'K'};
int assign[10];
int ans = 0;

int ICT() {
    return assign[1] * 100 + assign[2] * 10 + assign[3];
}

int HUST() {
    return assign[4] * 1000 + assign[5] * 100 + assign[6] * 10 + assign[3];
}

int K62() {
    return assign[7] * 100 + 62;
}

bool check(int i) {
    if (visited[i]) return false;
    return true;
}

void solution() {
    if (ICT() - K62() + HUST() == N)
        ans++;
}

void Try(int k) {
    for (int i = 1; i <= 9; i++) {
        if (check(i)) {
            assign[k] = i;
            visited[i] = true;

            if (k == 7) solution();
            else Try(k+1);

            visited[i] = false;
        }
    }
}

int main() {
    cin >> N;
    Try(1);
    cout << ans;
    return 0;
}
