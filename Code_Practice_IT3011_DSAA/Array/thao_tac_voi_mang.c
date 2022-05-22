// #include<stdio.h>
 
// void change(int *num) {
//     *num = *num + 1;
// }
 
// int main() {
//     int x = 100;
//     printf("Truoc khi goi phuong thuc x = %d \n", x);
//     change(&x); // truyen tham chieu vao phuong thuc
//     printf("Sau khi goi phuong thuc x = %d \n", x);
//     return 0;
// }



// **** //
// Thao tac voi mang bang con tro
 
#include <stdio.h>
#include <stdlib.h>
 
void NhapMang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        // Do giá trị con trỏ là địa chỉ rồi. Nên bạn sẽ không thấy dấu & quen thuộc nữa
        scanf("%d", (arr + i));
    }
}
 
void XuatMang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
}
 
void ThemPhanTu(int *a, int *n, int val, int pos)
{
    // Phân bổ lại bộ nhớ đã cấp phát cho con trỏ.
    // Ta cần thêm 1 ô nhớ cho nó => dùng realloc()
    a = (int *)realloc(a, (*n + 1) * sizeof(int));
    // Neu pos <= 0 => Them vao dau
    if (pos < 0)
    {
        pos = 0;
    }
    // Neu pos >= n => Them vao cuoi
    else if (pos > *n)
    {
        pos = *n;
    }
    // Dich chuyen mang de tao o trong truoc khi them.
    for (int i = *n; i >= pos; i--)
    {
        *(a + i) = *(a + i - 1);
    }
    // Chen val tai pos
    *(a + pos) = val;
    // Tang so luong phan tu sau khi chen.
    ++(*n);
}
 
void XoaPhanTu(int *a, int *n, int pos)
{
    // Mang rong, khong the xoa.
    if (*n <= 0)
    {
        return;
    }
    // Neu pos <= 0 => Xoa dau
    if (pos < 0)
    {
        pos = 0;
    }
    // Neu pos >= n => Xoa cuoi
    else if (pos >= *n)
    {
        pos = *n - 1;
    }
    // Dich chuyen mang
    for (int i = pos; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    // Cấp phát lại vùng nhớ, giờ ta chỉ cần n - 1 ô nhớ
    a = (int *)realloc(a, (*n - 1) * sizeof(int));
 
    // Giam so luong phan tu sau khi xoa.
    --(*n);
}
 
int main()
{
    int *arr;
    int n;
    do
    {
        printf("Nhap so luong n = ");
        scanf("%d", &n);
    } while (n < 1);
 
    // cấp phát đủ sài cho n o nho lien tiep
    arr = (int *)malloc(n * sizeof(int));
 
    if (arr == NULL)
    {
        printf("Khong the cap phat!");
        exit(0);
    }
 
    NhapMang(arr, n);
    printf("\nMang vua nhap la:\n");
    XuatMang(arr, n);
 
    printf("\n=======THEM PHAN TU======\n");
    int val, pos;
    printf("\nNhap so can them: ");
    scanf("%d", &val);
    printf("\nNhap vi tri muon chen: ");
    scanf("%d", &pos);
    ThemPhanTu(arr, &n, val, pos);
    printf("\nMang sau khi them:\n");
    XuatMang(arr, n);
 
    printf("\n=======XOA PHAN TU======\n");
    printf("\nNhap vi tri muon xoa: ");
    scanf("%d", &pos);
    XoaPhanTu(arr, &n, pos);
    printf("\nMang sau khi xoa:\n");
    XuatMang(arr, n);
    // giải phóng khi ket thuc chuong trinh
    free(arr);
}



