// De bai: Liet ke cac tap con cua 1 mang

//#include <iostream>
//using namespace std;
//int* Arr;
// 
//void quayLui(int n, int k, int X[], int i, int j)
//{
//    for(j; j < n - k + i + 1; j++)   
//    {
//        X[i] = Arr[j];  // i là v? tr? dang gán giá tr?
// 
//        if(i == (k-1))
//        {
//            int temp;
//            for(temp = 0; temp < k; temp++)
//            {
//                cout << X[temp] << " ";
//            }
//            cout << "\n";
//        }
// 
//        else
//        {
//            quayLui(n, k, X, i + 1, j + 1);  // th?c hi?n gán ti?p giá tr? chi v? trí i + 1
//        }
//    }
//}
// 
//int main()
//{
//    int n;
//    cin >> n;
//    Arr = new int [n];
//    for(int i = 0; i < n; i++)
//        cin >> Arr[i];
// 
//    int X[n];   
//    for(int k = 1; k <= n; k++)
//         quayLui(n, k, X, 0, 0);  
//    return 0;
//}


// De bai: phan tich so nguyen duong n thanh tong cac so nguyen duong,
// cac ket hopj la hoan vi cua nhau chi tinh la 1 cach

#include <iostream> 
using namespace std;
int x[101], // mang luu hang tu 
	t[101], // mang luu hieu sau khi tru
	n;
void print_sol(int i) 
{
	for (int a = 1; a <= i; a++) cout << x[a] << " ";
	cout << endl;
}

void cal(int i, int j) {
	while (j < t[i-1]) { // dk ung cu vien j
		int sub = t[i-1] - j;
		if (sub >= j) {
			x[i] = j;
			x[i+1] = sub;
			t[i] = sub;
			print_sol(i+1);
			cal(i+1,j);
			j++;
		}
		else return; // neu ko se xay ra tinh trang bi lap
	}
}

int main() {
	cin >> n;
	t[0] = n; // co so de quy
	cal(1,1);
	return 0;
}
