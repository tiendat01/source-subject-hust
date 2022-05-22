#include <stdio.h>
#include <string.h>
#include <conio.h>

int i, j, n = 0;
char ds[500][30], tg[30];
void bosung();
void sapxep();
void inds();

int main() {
    bosung();
    bosung();
    bosung();
    bosung();
    bosung();
    sapxep();
    inds();
}

int NamePos(char *ht) {
    i = strlen(ht) - 1;
    while (ht[i] == ' ' && i > -1) i--;
    while (ht[i] != ' ' && i > -1) i--;
    return i+1;
}

void sapxep() {
// int i,j,k;
// for(i=0;i<n-1;i++) {
//     k=i;
//     for(j=i+1;j<n;j++)
//         if (strcmp(ds[k]+NamePos(ds[k]), ds[j]+NamePos(ds[j])) >0) k=j;
//         else if (strcmp(ds[k]+NamePos(ds[k]),ds[j]+NamePos(ds[j])) ==0)
// 	        if (strcmp(ds[k],ds[j]) >0) k=j;
//     if (k!=i) {
//         strcpy(tg,ds[i]);
//         strcpy(ds[i],ds[k]);
//         strcpy(ds[k],tg);
//     }    
//   }
//   printf("\n Danh sach da duoc sap xep !!!");
//   getch();

int i,j,k;
  for(i=0;i<n-1;i++) {
    k=i;
    for(j=i+1;j<n;j++)
      if (strcmp(ds[k]+NamePos(ds[k]),      
                  ds[j]+NamePos(ds[j])) >0) k=j;
      else if (strcmp(ds[k]+NamePos(ds[k]),    
                       ds[j]+NamePos(ds[j])) ==0)
	      if (strcmp(ds[k],ds[j]) >0) k=j;
	if (k!=i) {
               strcpy(tg,ds[i]);
               strcpy(ds[i],ds[k]);
               strcpy(ds[k],tg);
    }    
  }
  printf("\n Danh sach da duoc sap xep !!!");
  getch();

}

void bosung() {
    printf("Nhap ho ten: "); gets(ds[n]);
    n++;
}

void inds() {
    for (int i = 0; i < n; i++) {
        puts(ds[i]);
        printf("\n");
    }
}