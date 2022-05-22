// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// #define MAX 1000

// typedef struct graph {
//     int v, e;
//     vector<int> ke[MAX];
//     int visit[MAX];
//     int del[MAX];
// } g, h;

// stack<int> s; // luu vi tri cac dinh sau lan dfs dau tien

// void dfs(graph g, int v) {
//     g.visit[v] = 1;
//     for (int i = 0; i < g.ke[v].size(); i++) {
//         int u = g.ke[v][i];
//         if (g.visit[u] == 0) dfs(g, u);
//     }
//     s.push(v);
// }

// void dfsAndPrint(graph h, int v) {
//     cout << v << " ";
//     h.del[v] = 1;
//     for (int i = 0; i < h.ke[v].size(); i++) {
//         int u = h.ke[v][i];
//         if (h.del[u] == 0) dfsAndPrint(h, u);
//     }
// }

// void printConnectedComponent(graph h) {
//     for (int i = 0; i < h.v; i++) h.del[i] = 0;
//     int v = s.top();
//     int count = 1;
//     while (s.size() != 0 ) {
//         s.pop();
//         if (h.del[v] == 0) {
//             cout << "Thanh phan lien thong manh thu " << count << " : ";
//             dfsAndPrint(h, v);
//             cout << endl;
//             count++;
//         }
//     }
// }

// void Kosaraju(graph g, graph h) {
//     for (int i = 0; i < g.v; i++) g.visit[i] = 0;
//     for (int i = 0; i < g.v; i++) {
//         if (g.visit[i] == 0) dfs(g, i);
//     }
//     printConnectedComponent(h);
// }


// int main() {
//     graph g, h;
//     g.v = h.v = 9;
//     g.e = h.e = 16;
//     g.ke[0] = {1,2,4};
//     g.ke[1] = {3};
//     g.ke[2] = {4,5};
//     g.ke[3] = {0,2,7,8};
//     g.ke[4] = {5};
//     g.ke[5] = {6,8};
//     g.ke[6] = {4};
//     //g.ke[7] = {NULL};
//     g.ke[8] = {2,7};
//     // h la do thi nguoc
//     h.ke[0] = {3};
//     h.ke[1] = {0};
//     h.ke[2] = {0,3,8};
//     h.ke[3] = {1};
//     h.ke[4] = {0,2,6};
//     h.ke[5] = {2,4};
//     h.ke[6] = {5};
//     h.ke[7] = {3,8};
//     h.ke[8] = {3,5};

//     Kosaraju(g, h);
// }


/*
 Petar 'PetarV' Velickovic
 Algorithm: Kosaraju's Algorithm
*/

// #include <stdio.h>
// #include <math.h>
// #include <string.h>
#include <iostream>
#include <vector>
// #include <list>
// #include <string>
#include <algorithm>
#include <queue>
#include <stack>
// #include <set>
// #include <map>
// #include <complex>

#define MAX_N 20001

typedef long long lld;
typedef unsigned long long llu;
using namespace std;

/*
 Kosaraju's algorithm aims to find all strongly connected components (SCCs) of
 a given input graph. It does so using two depth-first searches, and as such is
 less efficient than Tarjan's SCC algorithm, but is more intuitive.
 
 Complexity:    O(V + E)
*/

int n, m;
struct Node
{
    vector<int> adj;
    vector<int> rev_adj;
};
Node graf[MAX_N];

stack<int> S;
bool visited[MAX_N];

int component[MAX_N];
vector<int> components[MAX_N];
int numComponents;

void kosaraju_dfs_1(int x)
{
    visited[x] = true;
    for (int i=0;i<graf[x].adj.size();i++)
    {
        if (!visited[graf[x].adj[i]]) kosaraju_dfs_1(graf[x].adj[i]);
    }
    S.push(x);
}

void kosaraju_dfs_2(int x)
{
    printf("%d ", x);
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i=0;i<graf[x].rev_adj.size();i++)
    {
        if (!visited[graf[x].rev_adj[i]]) kosaraju_dfs_2(graf[x].rev_adj[i]);
    }


}

void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;
 
// Extract top of the stack
    int x = s.top();
 
    // Pop the top element
    s.pop();
 
    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';
 
    // Proceed to print
// remaining stack
    PrintStack(s);
 
    // Push the element back
    s.push(x);
}

void Kosaraju()
{
    for (int i=0;i<n;i++)
    {
        if (!visited[i]) kosaraju_dfs_1(i);
    } // chay dfs lan 1 cho do thi xuoi de lay ra vi tri duyet luu vao stack S
    
    for (int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    PrintStack(S);
    while (!S.empty())
    {
        int v = S.top(); S.pop();
        if (!visited[v])
        {
            printf("Component %d: ", numComponents);
            kosaraju_dfs_2(v);
            numComponents++;
            printf("\n");
        }
    }


}

int main()
{
    n = 8, m = 14;
    graf[0].adj.push_back(1);
    graf[1].adj.push_back(2);
    graf[1].adj.push_back(4);
    graf[1].adj.push_back(5);
    graf[2].adj.push_back(3);
    graf[2].adj.push_back(6);
    graf[3].adj.push_back(2);
    graf[3].adj.push_back(7);
    graf[4].adj.push_back(5);
    graf[5].adj.push_back(6);
    graf[6].adj.push_back(5);
    graf[7].adj.push_back(3);
    graf[7].adj.push_back(6);
    
    // making the reverse graph immediately
    graf[1].rev_adj.push_back(0);
    graf[2].rev_adj.push_back(1);
    graf[4].rev_adj.push_back(1);
    graf[5].rev_adj.push_back(1);
    graf[3].rev_adj.push_back(2);
    graf[6].rev_adj.push_back(2);
    graf[2].rev_adj.push_back(3);
    graf[7].rev_adj.push_back(3);
    graf[5].rev_adj.push_back(4);
    graf[6].rev_adj.push_back(5);
    graf[5].rev_adj.push_back(6);
    graf[3].rev_adj.push_back(7);
    graf[6].rev_adj.push_back(7);
    
    Kosaraju();
    
    printf("Total number of components: %d\n", numComponents);

    for (int i = 0 ; i < components[component[7]].size(); i++) cout << components[component[7]][i] << " ";
    
    return 0;
}