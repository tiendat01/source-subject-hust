// #include <bits/stdc++.h>

// using namespace std;

// struct my_type
// {
//     int i_step; // row
//     int j_step; // col
// };

// vector<my_type> steps = { {+1, 0}, {-1, 0}, {0, +1}, {0, -1} };
// int n, m;
// int maze[1000][1000];
// bool mark[1000][1000];
// int i0, j0;
// my_type path[1000];
// int count_steps = 0, min_steps = INT_MAX;
// bool can_escape = false; // update this if find the way to escape the maze

// void input() {
//     cin >> n >> m;
//     cin >> i0 >> j0;
//     i0--, j0--;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> maze[i][j]; 
//         }
//     }

//     // for (int i = 0; i < n; i++) {
//     //     for (int j = 0; j < m; j++) {
//     //         cout << maze[i][j] << ' '; 
//     //     }
//     //     cout << endl;
//     // }
// }

// bool is_next_cell(int kth_cell, int index_of_steps) {
//     // neu jump cac buoc trong steps
//     int i_test = path[kth_cell-1].i_step + steps[index_of_steps].i_step;
//     int j_test = path[kth_cell-1].j_step + steps[index_of_steps].j_step;
//     // neu quay tro lai cell da di qua, vi phai tim duong di ngan nhat va tranh lap vo han trong TH ko co duong thoat
//     if (mark[i_test][j_test])
//         return false;
//     // encounter obstacle cell
//     if (maze[i_test][j_test]) 
//         return false;
//     return true;
// }

// void back_track(int kth_cell) {
//     for (int i = 0; i < steps.size(); i++) {
//         if (is_next_cell(kth_cell, i)) {
//             path[kth_cell].i_step = path[kth_cell-1].i_step + steps[i].i_step;
//             path[kth_cell].j_step = path[kth_cell-1].j_step + steps[i].j_step;
//             int i_cur = path[kth_cell].i_step;
//             int j_cur = path[kth_cell].j_step;
//             mark[i_cur][j_cur] = true;
//             count_steps++;

//             // neo de quy, find the path to get out of the maze by reaching to the edge of the maze
//             if (i_cur == 0 || i_cur == n-1 || j_cur == 0 || j_cur == m-1) {
//                 can_escape = true;
//                 min_steps = min_steps > count_steps ? count_steps : min_steps;
//             }
//             else 
//                 back_track(kth_cell+1);

//             count_steps--;
//             mark[i_cur][j_cur] = false;
//             path[kth_cell].i_step -= steps[i].i_step;
//             path[kth_cell].j_step -= steps[i].j_step;
            
//         }
//     }
// }

// int main() {
//     input();
//     path[0] = {i0, j0};
//     mark[i0][j0] = true;
//     back_track(1);
//     if (can_escape) cout << min_steps+1; // from the edge to outside
//     else cout << -1;
//     return 0;
// }


// bfs
#include <bits/stdc++.h>

using namespace std;

short n, m;
short maze[1000][1000];
bool mark[1000][1000];
short i0, j0;

void input() {
    cin >> n >> m;
    cin >> i0 >> j0;
    i0--, j0--;
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            cin >> maze[i][j]; 
        }
    }
}

bool is_next_cell(short i, short j) {
    return i >= 0 && i < n && j >= 0 && j < m && !mark[i][j] && maze[i][j] == 0;
}


int escape_min_steps() {
    short di[4] = {+1, -1, 0, 0};
    short dj[4] = {0, 0, +1, -1};
    queue < pair<short, pair<short, short>> > q;
    q.push({0, {i0, j0}});
    mark[i0][j0] = true;
    // int steps = 0;

    while (!q.empty()) {
        auto cell = q.front();
        q.pop();


        for (short index = 0; index < 4; index++) {
            short x = cell.second.first + di[index];
            short y = cell.second.second + dj[index];
            short steps = cell.first;


            if (x < 0 || x > n-1 || y < 0 || y > m-1) 
                return steps+1;

            if (is_next_cell(x, y)) {
                mark[x][y] = true;
                int tmp = steps + 1;
                cout << x << ' ' << y << ' ' << tmp << endl;
                q.push({tmp, {x, y}});
            }

        }
    }
    return -1;
}

int main() {
    input();
    cout << escape_min_steps();
    return 0;
}







// bfs solution: tham khao (giong loi giai tren)
// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1000;

// bool visited[MAX][MAX];
// int  N,M,r,c;
// int a[MAX][MAX];

// void input(){
//     cin >> N >> M >> r >> c;
//     for(int i = 1; i <= N; i++)
//         for(int j = 1; j <= M; j++)
//             cin >> a[i][j];
// }
// bool check(int r, int c){
//     return r >= 1 && r <= N && c >= 1 && c <= M && a[r][c] == 0 && ! visited[r][c];
// }
// void solve(){
//     int dr[4] = {1,-1,0,0};
//     int dc[4] = {0,0,1,-1};

//     map<pair<int,int>, int> d; // khoang cach tu vi tri xuat phat den vi tri hien tai
//     queue<pair<int,int> > Q;

//     // map<pair<int,int>, pair<int,int> > pred; // vi tri truoc cua pred[i]
//     pair<int,int> start = pair<int,int>(r,c);
//     pair<int,int> finish;
//     Q.push(start);
//     visited[r][c] = true;
//     d[start] = 0;
//     bool found = false;
//     while(!Q.empty()){
//         pair<int,int> p = Q.front(); Q.pop();


//         for (int k = 0; k < 4; k++){
//             int nr = p.first + dr[k];
//             int nc = p.second + dc[k];
//             // can get out
//             if(nr < 1 || nr > N || nc < 1 || nc > M){
//                 cout << d[p] + 1 << endl;
//                 finish = pair<int,int>(nr,nc);
//                 // pred[finish] = p;
//                 found = true;
//                 break;
//             }
//             if(check(nr,nc)){
//                 pair<int,int> np = pair<int,int>(nr,nc);
//                 Q.push(np);
//                 visited[nr][nc] = true;
//                 d[np] = d[p] + 1;
//                 // pred[np] = p;
//             }

//         }
//         if(found) break;
//     }

//     // print path
//     // stack<pair<int,int> > path;
//     // if(found){
//     //     pair<int,int> p = finish;
//     //     while(p != start){
//     //         path.push(p);
//     //         p = pred[p];
//     //     }
//     //     cout << "(" << start.first << "," << start.second << ") ";
//     //     while(!path.empty()){
//     //         p = path.top(); path.pop();
//     //         cout << "(" << p.first << "," << p.second << ") ";
//     //     }
//     // }
// }
// int main(){
//     input();
//     solve();
// }
