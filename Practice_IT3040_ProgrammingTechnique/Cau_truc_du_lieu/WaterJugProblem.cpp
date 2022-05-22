// water jug problem using BFS
// co 3 thao tac:
// 1. full a jug
// 2. empty a jug
// 3. pour a jug to another until it 's empty or the another 's full

#include <iostream>
#include <queue>
#include <utility>


using namespace std;

int _count[1000][1000] = {};
int a, b, c;
queue<pair<int, int>> q;

// 1 lan push la 1 buoc
void push_and_count(int x, int y, int cur_steps) {
    if (x < 0 || y < 0 || x > a || y > b) return ;
    // neu trang thai (x, y) chua ton tai
    if (!_count[x][y]) {
        q.push({x, y});
        cur_steps++;
        _count[x][y] = cur_steps;
    }
}

void water_jug() {
    int x, y;
    q.push({a, b}); _count[a][b] = 1;
    while (!q.empty())
    {
        auto front = q.front(); q.pop();
        x = front.first; y = front.second;

        if (x == c || y == c) {
            cout << _count[x][y] - 1;
            return ;
        }

        // tu trang thai (x,y) co the chuyen sang 1 trong 8 trang thai sau bang 1 trong 3 thao tac neu tren
        // xet tat ca 8 kha nang co the xay ra
        push_and_count(x, 0, _count[x][y]);
        push_and_count(0, y, _count[x][y]);
        push_and_count(x, b, _count[x][y]);
        push_and_count(a, y, _count[x][y]);
        push_and_count(a, x + y - a, _count[x][y]);
        push_and_count(x + y - b, b, _count[x][y]);
        push_and_count(x + y, 0, _count[x][y]);
        push_and_count(0, x + y, _count[x][y]);
    }
        
}

int main() {
    a = 6, b = 8, c = 4;
    water_jug();
    return 0;
}