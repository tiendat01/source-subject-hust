// n client
// d[i] (i=1->n): weight of package to client i
// Q capacity of K trucks
// 1 truck visit at lease 1 client, tuc la ko co xe ranh
// => so loi giai

// ý tưởng:
// - Duyệt client đầu tiên cho K xe: mỗi xe thứ k sẽ có client đầu tiên (còn lại n-K client)
// - Với mỗi lần hoàn thành duyệt trên,
// duyệt các client còn lại cho K xe đó

#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int n, K, Q;
int d[MAX];

bool visited[MAX];
int load[MAX]; // lưu load của mỗi xe
int firstclient[MAX]; // lưu client đầu tiên của mỗi xe => size = K
int nextclient[MAX]; // lưu client tiếp theo của client hiện tại => nextclient[v]: client tiếp theo của client v
int segment;
int ans;

void input() {
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) 
        cin >> d[i];
    d[0] = 0;
    firstclient[0] = 0;
}


void Try_next_client(int k, int cur_client);

bool check_first_client(int client, int k) {
    // if (visited[client]) return false; // ko cần dòng này
    if (load[k] + d[client] > Q) return false;
    return true;
}


// lời giải cuối cùng là mỗi xe sẽ có client đầu tiên, ds client đầu tiên
// lưu vao firstclient[k]
void Try_first_client(int k) {
    // i là client, bắt đầu từ client của xe k-1 trước + 1 để tránh lặp lại do các xe có vai trò như nhau
    for (int i = firstclient[k-1] + 1; i <= n; i++) {
        if (check_first_client(i, k)) {
            firstclient[k] = i;
            visited[i] = true;
            segment++;
            load[k] += d[i];

            // nếu tất cả K xe đã gán client đầu tiên
            if (k == K) 
                Try_next_client(1, firstclient[1]);
            else {
                Try_first_client(k+1); // xe tiếp theo
            }

            visited[i] = false;
            segment--;
            load[k] -= d[i];
        }
    }
}


void solution() {
    // K xe di toi n client va quay ve 0
    if (segment == n + K) {
        ans++;
        // in kết quả:
        for (int k = 1; k <= K; k++) {
            cout << "route[" << k << "] = " << 0 << ' '; // bắt đầu la 0
            for (int i = firstclient[k]; i != 0; i = nextclient[i]) {
                cout << i << ' ';
            }
            cout << 0 << endl; // kết thúc là 0
        }
    }
}

bool check_next_client(int client, int k) {
    if (client == 0) return true;
    if (visited[client]) return false;
    if (load[k] + d[client] > Q) return false;
    return true;
}

void Try_next_client(int k, int cur_client) {
    // i là client tiếp theo
    for (int i = 0; i <= n; i++) {
        if (check_next_client(i, k)) {
            nextclient[cur_client] = i;
            visited[i] = true;
            load[k] += d[i];
            segment++;

            // nếu xe k chưa về điểm xuất phát (điểm 0)
            if (i != 0) Try_next_client(k, nextclient[cur_client]);
            // nếu i = 0, xe k về đích
            else {
                if (k == K) solution(); // tất cả các xe đều về đích
                else Try_next_client(k+1, firstclient[k+1]); // duyệt tiếp với xe tiếp theo k+1
            }

            visited[i] = false;
            load[k] -= d[i];
            segment--;
        }
    }
}

int main() {
    input();
    Try_first_client(1);
    cout << ans;
    return 0;
}


// Example
// input
// 3 2 4
// 3 2 1
// output
// 4

// Note
// There are 4 solutions

// route[1] = 0 -> 1 -> 0 and route[2] = 0 -> 2 -> 3 -> 0
// route[1] = 0 -> 1 -> 3 -> 0 and route[2] = 0 -> 2 -> 0
// route[1] = 0 -> 1 -> 0 and route[2] = 0 -> 3 -> 2 -> 0
// route[1] = 0 -> 2 -> 0 and route[2]= 0 -> 3 -> 1 -> 0