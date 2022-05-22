#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10000

#define NO false
#define YES true

typedef struct {
    int n; // so dinh
    int m; // so canh
    int x[MAX], y[MAX];
    int nhan[MAX], deg[MAX]; // nhan cua dinh va bac cua dinh
    int coloring[MAX];
} graph; // dieu kien cua do thi graph la lien thong

// ktra tat ca dinh da to mau chua
int CheckAllColored(int bac[MAX], int n) {
    for (int i = 1; i <= n; i++) {
        if (bac[i] != 0) return 1;
    }
    return 0;
}

// to mau do thi
void coloring(graph g) {
    for (int i = 1; i <= g.n; i++) g.nhan[i] = i; // luu nhan cua cac dinh

    // tinh so bac cua moi dinh
    for (int i = 1; i <= g.n; i++) g.deg[g.nhan[i]] = 0;
    for (int i = 1; i <= g.n; i++) {
        for (int j = 1; j <= g.m; j++) {
            if (g.nhan[i] == g.x[j] || g.nhan[i] == g.y[j]) g.deg[i]++;
        }
    }

    for (int i = 1; i <= g.n; i++) g.coloring[i] = 0; // ban dau chua dinh nao duoc to mau.

    // khoi tao tap mau gom k+1 mau dung de to mau do thi 
    int k = 1;
    for (int i = 1; i <= g.n; i++) 
        if (k < g.deg[i]) k = g.deg[i];

    int tap_mau[MAX];
    for (int i = 1; i <= k+1; i++) tap_mau[i] = i;


    int j = 1; // la chi so cho mang tap_mau
    int last = 0; // la mau to cho cac dinh con lai ma bac cua no = 0
    while (CheckAllColored(g.deg, g.n)) {
        int deg_max = 1, imax = 0; // imax la chi so cua bac lon nhat.
        // tim dinh co bac lon nhat
        for (int i = 1; i <= g.n; i++) {
            if (deg_max < g.deg[i]) {
                deg_max = g.deg[i];
                imax = i;
            }
        }

        // to mau j cho dinh co bac lon nhat
        g.coloring[imax] = tap_mau[j]; 
        g.deg[imax] = 0; // to xong xoa luon dinh nay bang cach gan bac 0 cho no

        bool do_possible[MAX]; // check xem dinh co phu hop de to mau j ko?
        for (int i = 1; i <= g.n; i++) do_possible[i] = YES; 

        for (int i = 1; i <= g.m; i++) {
            if (g.nhan[imax] == g.x[i] && g.deg[g.y[i]] != 0) {
                do_possible[g.nhan[g.y[i]]] = NO;
                g.deg[g.nhan[g.y[i]]]--; // do g.nhan[imax] bi xoa nen bac dinh hang xom giam 1
            }
            if (g.nhan[imax] == g.y[i] && g.deg[g.x[i]] != 0) {
                do_possible[g.nhan[g.x[i]]] = NO;
                g.deg[g.nhan[g.x[i]]]--; // do g.nhan[imax] bi xoa nen bac dinh hang xom giam 1
            }
        }

        // to mau cho cac dinh phu hop voi mau j
        for (int i = 1; i <= g.n; i++) {
            if (do_possible[g.nhan[i]] == YES && g.deg[g.nhan[i]] != 0) {
                g.coloring[g.nhan[i]] = tap_mau[j]; 
                g.deg[g.nhan[i]] = 0;
                // sau do ha bac cua cac dinh la hang xom cua dinh vua to
                for (int j = 1; j <= g.m; j++) {
                    if (g.nhan[i] == g.x[j] && g.deg[g.nhan[g.y[j]]] != 0) {
                        g.deg[g.nhan[g.y[j]]]--;
                        do_possible[g.nhan[g.y[j]]] = NO;
                    }
                    if (g.nhan[i] == g.y[j] && g.deg[g.nhan[g.x[j]]] != 0) {
                        g.deg[g.nhan[g.x[j]]]--;
                        do_possible[g.nhan[g.x[j]]] = NO;
                    }
                }
                
            }
        }
        j++; // mau tiep theo
    }

    for (int i = 1; i <= g.n; i++) {
        if (g.deg[g.nhan[i]] == 0 && g.coloring[g.nhan[i]] == 0) g.coloring[g.nhan[i]] = j;
    }
    


    // doc ten mau tu file color_name.txt gan vao mang color_name
    char color_name[148][50];
    FILE *color;
    color = fopen("color_name.txt", "r");
    for (int i = 1; i <= 147; i++) {
        fgets(&color_name[i], 50, color);
    }
    fclose(color);
    for (int i = 1; i <= 147; i++) {
        color_name[i][strlen(color_name[i])-1] = '\0';
    }
    

    printf("\nNhan:| Mau:\n");
    for (int i = 1; i <= g.n; i++) printf("%d    |   %s\n", g.nhan[i], color_name[g.coloring[i]]);


    // ghi file dothitomau.dot
    FILE *file;
    file = fopen("dothitomau.dot", "w");
    fprintf(file, "graph dothi\n");
    fprintf(file, "{\n");
    for (int i = 1; i <= g.n; i++) {
        fprintf(file, "%d [fillcolor=%s, style=filled];\n", i, color_name[g.coloring[i]]);
    }
    for (int i = 1; i <= g.m; i++) {
        fprintf(file, "%d -- %d;\n", g.x[i], g.y[i]);
    }
    fprintf(file, "}");
    fclose(file);

}


// // Nhap du lieu vao file dothi.txt bang ban phim
// void Input(graph g) {
//     FILE* f;
//     printf("Nhap so dinh, so canh va danh sach canh cua do thi:\n");
//     scanf("%d%d", &g.n, &g.m);
//     for (int i = 0; i < g.m; i++) {
//         scanf("%d%d", &g.x[i], &g.y[i]);
//     }
//     f = fopen("dothi.txt", "w");
//     fprintf(f, "%d %d\n", g.n, g.m);
//     for (int i = 0; i < g.m; i++) {
//         fprintf(f,"%d %d\n", g.x[i], g.y[i]);
//     }
//     fclose(f);
// }

int main() {
    graph graph;
    // Doc du lieu tu file van ban dothi.txt
    FILE* f;
    f = fopen("dothi.txt", "r");
    fscanf(f, "%d%d", &graph.n, &graph.m);
    for(int i = 1; i <= graph.m; i++) {
        fscanf(f, "%d%d", &graph.x[i], &graph.y[i]);
    }
    fclose(f);

    // to mau do thi
    coloring(graph);
    return 1;
}