#include <stdio.h>
#include <stdlib.h>

#define NO -1
#define YES 1
#define NOT_YET 0 // da tham nhung nhg chua duyet xong

// graph ban chat la tong hop cac danh sach ke
// voi moi danh sach ke la 1 ds lien ket noi don

typedef int datatype;
// cau truc cua moi nut trg ds ke:
typedef struct _adjListNode {
    datatype inf;
    struct _adjListNode *next;
} adjListNode;

// cau truc cua graph
typedef struct _graph {
    int V; // so dinh cua do thi
    int *visited; // mang luu trang thai NO, NOT_YET, YES
    int *pre, *post; 
    adjListNode **array; // mang chua cac ds ke : mang con tro
} graph;

adjListNode *makeNewAdjListNode(int x) {
    adjListNode *new_node = (adjListNode*)malloc(sizeof(adjListNode));
    new_node->inf = x;
    new_node->next = NULL;
    return new_node;
}

graph *makeNewGraph(int v) {
    graph *new_graph = (graph*)malloc(sizeof(graph));
    new_graph->V = v;
    new_graph->array = (adjListNode*)malloc(v * sizeof(adjListNode)); // co v danh sach lket don
    new_graph->visited = (int*)malloc(v * sizeof(int));
    new_graph->pre = (int*)malloc(v * sizeof(int));
    new_graph->post = (int*)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        new_graph->array[i] = NULL;
        new_graph->visited[i] = NO;
    }
    return new_graph;
}

void addEdge(graph *g, datatype from, datatype to) {
    // insert to head vao cac ds noi don
    adjListNode *new_node = makeNewAdjListNode(to);
    new_node->next = g->array[from];
    g->array[from] = new_node;

    // // them doan ma nay neu do thi la vo huong
    // new_node = makeNewAdjListNode(from);
    // new_node->next = g->array[to];
    // g->array[to] = new_node;

}

void printGraph(graph *g) {
    for (int v = 0; v < g->V; v++) {
        adjListNode *first = g->array[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (first) {
            printf("-> %d", first->inf);
            first = first->next;
        }
        printf("\n");
    }
}

int time = 0;

void DFS_visit(graph *g, int u) {
    g->visited[u] = NOT_YET;
    time++;
    g->pre[u] = time;
    printf("visit not check %d, pre = %d\n", u, g->pre[u]);

    adjListNode *temp_node = g->array[u];
    while (temp_node!=NULL) {
        int v = temp_node->inf;
        if (g->visited[v] == NO) DFS_visit(g, v);
        temp_node = temp_node->next;
    }
    
    g->visited[u] = YES;
    time++;
    g->post[u] = time;
    printf("visit and check %d, post = %d\n", u, g->post[u]);
}

void DFS(graph *g) {
    for (int v = 0; v < g->V; v++) {
        if (g->visited[v] == NO) DFS_visit(g, v); // dem so thanh phan lien thong la dem so lan goij ham DFS_visit
    }
}

int main() 
{ 
    int V = 5; 
    graph* dothi = makeNewGraph(V); 
    addEdge(dothi, 0, 1); 
    addEdge(dothi, 0, 4); 
    addEdge(dothi, 1, 2); 
    addEdge(dothi, 1, 3); 
    addEdge(dothi, 1, 4); 
    addEdge(dothi, 2, 3); 
    addEdge(dothi, 3, 4); 
  
    
    printGraph(dothi); 

    //DFS_visit(dothi, 0);

    DFS(dothi);

    return 0; 
} 