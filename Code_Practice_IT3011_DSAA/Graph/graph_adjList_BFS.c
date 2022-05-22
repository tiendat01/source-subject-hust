#include <stdio.h>
#include <stdlib.h>

#define NO -1
#define YES 1
#define NOT_YET 0 // da tham nhung nhg chua duyet xong

//// Hang doi Q

typedef int elementype;
typedef struct _node {
    elementype element;
    struct _node *next;
} node;
// boc 2 con tro front va rear
typedef struct {
    node *front;
    node *rear;
} queue;

queue *makeNewQueue() {
    queue *q = (queue*)malloc(sizeof(queue));
    if (q == NULL) return NULL;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(queue *q) {
    if (q == NULL || q->front == NULL) return 1;
    return 0;
}

void enQueue(queue *q, elementype x) { // giong ham InserToLast cua ds noi don!!!
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) return ;
    new_node->element = x;
    new_node->next = NULL;
    // truong hop q ban dau rong
    if (q->front == NULL) { 
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

elementype deQueue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty! Cannot dequeue!");
        return NULL;
    }
    elementype delete_item;
    node *temp_node = q->front;

    delete_item = q->front->element;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL; // dequeue khi queue chi con 1 ptu, gan rear la NULL luon
    free(temp_node);
    return delete_item;
}

void print(queue *q) {
    if (q->rear == NULL) {
        printf("Queue is empty! Cannot dequeue!");
        return NULL;
    }
    for (node *i = q->front; i != NULL; i = i->next) {
        printf("%d ", i->element);
    }
}




typedef int element_type;
typedef struct NodeType {
    element_type value;
    struct NodeType *next;
} StackNode;
typedef struct _Stack {
    StackNode *top;
} Stack;

Stack *makeNewStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return NULL; // het bo nho ko the malloc cho s
    s->top = NULL;
    return s;
}

// Khi cai dat ngan xep bang ds lienket, chi khi het bo nho thi ngan xep moi full
int isFull(Stack *s) {

}

int isEmptyS(Stack *s) {
    if (s == NULL) return 1;
    if (s->top == NULL) return 1;
    return 0;
}

void duyetStack(Stack *s) {
    StackNode *temp_node = s->top;
    while (temp_node != NULL) {
        printf("%d -> ", temp_node->value);
        temp_node = temp_node->next;
    } 
}

int stackSize(Stack *s) {
    if (s == NULL) return 0;
    if (s->top == NULL) return 0;
    StackNode *temp_node = s->top; int count = 0;
    while (temp_node != NULL) {
        count++;
        temp_node = temp_node->next;
    }
    return count;
}

// inssert to head
void push(Stack *s, element_type x) {
    if (s == NULL) printf("NO MEMORY! Cannot push anything."); 
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) printf("NO MEMORY for new elements! Cannot push into stack.");
    new_node->value = x;
    new_node->next = s->top;
    s->top = new_node;
}

// delete head
element_type pop(Stack *s) {
    if (isEmptyS(s) == 1) {
        printf("Stack is empty! Cannot pop anything.");
        return 0;
    }
    StackNode *temp_node = s->top;
    element_type x = temp_node->value;
    s->top = s->top->next;
    free(temp_node);
    return x;
}





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
    int *visited;
    int *pre; // nut trc cua nut trong duong di ngan nhat
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
    new_graph->visited = (int*)malloc(v * sizeof(int));
    new_graph->pre = (int *)malloc(v * sizeof(int));
    new_graph->array = (adjListNode*)malloc(v * sizeof(adjListNode)); // co v danh sach lket don
    for (int i = 0; i < v; i++) {
        new_graph->array[i] = NULL;
        new_graph->visited[i] = NO;
        new_graph->pre[i] = -1;
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


void BFS_visit(graph *g, int s) {
    // s la diem mooif thooi
    g->visited[s] = YES;
    queue *Q = makeNewQueue();
    enQueue(Q, s);

    while (!isEmpty(Q)) {
        int u = deQueue(Q);
        printf("visit not check %d\n", u);

        adjListNode *temp_node = g->array[u];
        while (temp_node) {
            int v = temp_node->inf;
            if (g->visited[v] == NO) {
                g->visited[v] = YES;
                enQueue(Q, v);
            }
            temp_node = temp_node->next;        
        }
        
        g->visited[u] = YES;
        printf("visit and check %d\n", u);
    }

}

void BFS(graph *g) {
    for (int i = 0; i < g->V; i++) {
        if (g->visited[i] == NO) BFS_visit(g, i);
    }
}

int count_BFS_visit(graph *g, int s, int d) { // ham chi dung neu do thi ko co chu trinh
    int count = 0;
    // s la diem mooif thooi
    queue *Q = makeNewQueue();
    enQueue(Q, s);

    while (!isEmpty(Q)) {
        int u = deQueue(Q);
        adjListNode *temp_node = g->array[u];
        while (temp_node) {
            int v = temp_node->inf;
            if (v == d) count++;
            enQueue(Q, v);
            temp_node = temp_node->next;        
        }
    }

    return count;
}

void shortestPath_BFS(graph *g, int s, int d) {
    Stack *S = makeNewStack();
    queue *Q = makeNewQueue();
    enQueue(Q, s);

    while (!isEmpty(Q)){
        int u = deQueue(Q);
        adjListNode *temp_node = g->array[u];
        while (temp_node) {
            int v = temp_node->inf;
            if (g->visited[v] == NO) {
                g->visited[v] = YES;
                g->pre[v] = u;
                if (v==d) {
                    break;
                }           
            }
            
            enQueue(Q, v);
            temp_node = temp_node->next;
        }
    }

    while (d != s) {
        push(S, d);
        d = g->pre[d];
    } 

    printf("Duong di ngan nhat tu %d den %d : %d -> ", s, d, s);
    duyetStack(S);
    printf("end");

}

int main() 
{ 
    int V = 5; 
    graph* dothi = makeNewGraph(V); 
    addEdge(dothi, 0, 4); 
    addEdge(dothi, 0, 1); 
    addEdge(dothi, 1, 2); 
    addEdge(dothi, 1, 3); 
    addEdge(dothi, 1, 4); 
    addEdge(dothi, 2, 3); 
    addEdge(dothi, 3, 4); 
  
    
    printGraph(dothi); 

    //BFS_visit(dothi, 0);

    // printf("\n%d", count_BFS_visit(dothi, 0, 4));

    shortestPath_BFS(dothi, 2, 4);
  
    return 0; 
} 