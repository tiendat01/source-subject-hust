#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10000

int cc = 0; // so thanh phan lien thong
int visit[MAX]; // ktra da tham dinh chua?
int dist[MAX]; // khoang cach tu dinh ban dau s den dinh bat ky
int pre[MAX]; // prev[u] luu dinh lien truoc u trong duong di ngan nhat

int v = 0, e = 0;
vector<int> a[MAX]; // a[u] luu cac hang xom cua u
string data[MAX];

void explore(int u) {
    visit[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int t = a[u][i]; // cac hang xom cua u
        if (visit[t] == 0) { explore(t);}
    }
}

void dfs() {
    for (int i = 0; i < v; i++) visit[v] = 0;
    for (int i = 0; i < v; i++) {
        if (visit[i] == 0) {
            cc++;
            explore(i);
        }
    }
}

void bfs(int s, int f) { // start and finish
    int u;
    queue<int> q;
    for (int i = 0; i < v; i++) {
        dist[i] = -1;
        pre[i] = -1;
    }
    dist[s] = 0;
    q.push(s);

    while(q.size() != 0) {
        u = q.front();
        q.pop();

        for (int i = 0; i < a[u].size(); i++) {
            int t = a[u][i];
            if (dist[t] == -1) {
                dist[t] = dist[u] + 1;
                pre[t] = u;
                q.push(t);
            }
        }
    }


    // truy vet
    if (dist[f] == -1) cout << "Khong co duong di tu " << data[s] << " toi " << data[f] << endl;
    else {
        vector<int> path;
        while (f != s) {
            path.push_back(f);
            f = pre[f];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        cout << "Duong di ngan nhat :" << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << data[path[i]] << " ";
        }
    }
}


int check(string s1, string s2) {
    int count = 0;

    if (s1.size() != s2.size()) return 0;
    
    else {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) count++;
        }
    }
    if (count == 4) return 1;
    else return 0;
}

int main() {
    fstream f;                    
	f.open("data.txt", ios::in); 
    if (f.fail()) cout << "Cannot read file!";
    else {   
        while (!f.eof())        
        {
            getline(f, data[v]);
            v++;
        }
    }
    f.close();


    for (int i = 0; i < v; i++) {
        for (int j = i+1; j < v; j++) {
            if (check(data[i], data[j]) == 1) {
                a[j].push_back(i);
                a[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < v; i++) {
        e += a[i].size();
    }
    e/=2;


    dfs();
    cout << "So thanh phan lien thong cua do thi vo huong la: " << cc << endl;

    string start, finish;
    cout << "Nhap vao tu bat dau: "; 
    cin >> start;
    cout << endl << "Nhap vao tu ket thuc: ";
    cin >> finish;
    cout << endl;
    int index_s = 0, index_f = 0;
    for(int i = 0; i < v; i++) {
        if (start == data[i]) index_s = i;
        if (finish == data[i]) index_f = i;
    }
    bfs(index_s, index_f);
    return 1;
}