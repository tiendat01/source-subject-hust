#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX 10000


bool visit[MAX]; // ktra da tham dinh chua?
int dist[MAX]; // khoang cach tu dinh ban dau s den dinh bat ky
int pre[MAX]; // prev[u] luu dinh lien truoc u trong duong di ngan nhat


struct CauTruc {
    vector<int> adj; // luu ds ke cua do thi xuoi
    vector<int> reverse_adj; // luu ds ke cua do thi nguoc
} graph[MAX];

int v, e; // so dinh va so canh cua 2 do thi la giong nhau
stack<int> S; // luu thu tu duyet sau khi dfs lan 1

int component[MAX]; // luu vi tri thanh phan lien thong ma x thuoc vao
vector<int> components[MAX]; // luu cac dinh thuoc thanh phan lien thong manh thu i
int count_components = 0; // so thanh phan lien thong manh

string data[MAX];

void dfs_1(int x) {
    // dfs lan 1 cho do thi xuoi
    visit[x] = true;
    for (int i = 0; i < graph[x].adj.size(); i++) {
        if (!visit[graph[x].adj[i]]) {
            dfs_1(graph[x].adj[i]);
        }
    }
    S.push(x);
}

void dfs_2(int x) {
    // dfs lan 2 cho do thi nguoc
    component[x] = count_components;
    components[count_components].push_back(x);
    visit[x] = true;
    for (int i = 0; i < graph[x].reverse_adj.size(); i++) {
        if (!visit[graph[x].reverse_adj[i]]) {
            dfs_2(graph[x].reverse_adj[i]);
        }
    }
}

void dfs() {
    for (int i = 0; i < v; i++) {
        if (!visit[i]) dfs_1(i);
    }
    for (int i = 0; i < v; i++) visit[i] = false;

    while (!S.empty()) {
        int a = S.top(); S.pop();
        if (!visit[a]) {
            dfs_2(a); // chay dfs lan 2 cho do thi nguoc, thu tu theo top cua stack S
            count_components++; // duyet het 1 tplt tang so tplt len.
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

        for (int i = 0; i < graph[u].adj.size(); i++) {
            int t = graph[u].adj[i];
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
            cout << data[path[i]] << " --> ";
        }
        cout << "ket thuc!!!";
    }
}


int check(string s1, string s2) {
    if ((s1.size() != s2.size()) || (s1 == s2)) return 0;
    else {
        int count = 0;
        bool possible[10]; 
        for (int i = 0; i < 5; i++) {
            possible[i] = true;
        } 

        for (int i = 4; i >= 1; i--) {
            for (int j = 0; j < 5; j++) {
                if (possible[j]) {
                    if (s1[i] == s2[j]) {
                        count++;
                        possible[j] = false;
                        break;
                    }
                }
            }
        }
        if (count == 4) return 1; 
        else return 0;
    }
    
    return 1;
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
        for (int j = 0; j < v; j++) {
            if (check(data[i], data[j]) == 1) {
                graph[i].adj.push_back(j); // data[i] --> data[j]
                graph[j].reverse_adj.push_back(i);
            }
        }
    }

    // for (int i = 0; i < v; i++) {
    //     e += graph[i].adj.size();
    // }
    // cout << e << endl;
    // cout << check("dross", "words");
    // for (int i = 0; i < a[7].size(); i++) cout << data[a[7][i]] << " ";
    dfs();
    cout << "So thanh phan lien thong manh cua do thi: " << count_components << endl;

    string u; int index = 0; // tri so cua u trong mang data[] 
    cout << "Nhap tu u: "; cin >> u;
    for(int i = 0; i < v; i++) if (u==data[i]) index = i;
    cout << "Cac tu thuoc thanh phan lien thong manh voi " << u << " la:" << endl;
    for (int i = 0; i < components[component[index]].size(); i++) {
        cout << data[components[component[index]][i]] << " ";
    }

    string start, finish;
    cout << endl;
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

}