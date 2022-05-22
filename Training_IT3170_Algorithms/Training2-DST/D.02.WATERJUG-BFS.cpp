#include <bits/stdc++.h>

using namespace std;

using type = pair<int, int>;

int a, b, c;
vector< vector<int> > count_step(1000, vector<int>(1000)); // initialize 2d vector with 0;
queue<type> q;

void push_and_count (int state_a, int state_b, int cur_count) {
    if (state_a < 0 || state_b < 0 ||state_a > a || state_b > b) return ;
    
    if (!count_step[state_a][state_b]) {
        cur_count++;
        count_step[state_a][state_b] = cur_count;
        q.push({state_a, state_b});
    }
}

int main() {
    cin >> a >> b >> c;
    int state_a, state_b;
    q.push({0, 0}); count_step[0][0] = 1; // ban dau 2 binh nuoc rong = 0(l)

    // bfs:
    while (!q.empty()) {
        state_a = q.front().first; 
        state_b = q.front().second;
        q.pop();
        if (state_a == c || state_b == c) {
            cout << count_step[state_a][state_b] - 1;
            return 0; // endl;
        }
        // tu trang thai (state_a, state_b) => cac thao tac:
        push_and_count(0, state_b, count_step[state_a][state_b]); // empty a
        push_and_count(state_a, 0, count_step[state_a][state_b]); // empty b
        push_and_count(0, state_a + state_b, count_step[state_a][state_b]);
        push_and_count(state_a + state_b, 0, count_step[state_a][state_b]);
        push_and_count(a, state_b, count_step[state_a][state_b]);
        push_and_count(state_a, b, count_step[state_a][state_b]);
        push_and_count(a, state_a + state_b - a, count_step[state_a][state_b]);
        push_and_count(state_a + state_b - b, b, count_step[state_a][state_b]);
    }

    // neu ko tim thay
    cout << -1 << endl;
    return 0;
}