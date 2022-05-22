#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#define MAX 100  

int cmin = INT_MAX; //# chi phí di l?i nh? nh?t gi?a hai thành ph? khác nhau | du thua???

int n, r, c[MAX][MAX]; //# so thành pho, so khach và ma tran chi phí
int best = INT_MAX; //# t?ng chi phí nh? nh?t c?n tìm, ban d?u d?t b?ng giá tr? vô cùng l?n INT_MAX = 2^31-1
int curr = 0; //# t?ng chi phí t?i th?i di?m hi?n t?i

int mark[MAX]; //# dánh d?u nh?ng thành ph? dã di
int x[MAX]; //# luu gi? các thành ph? dã di
vector<int> place;
int start, des, num_place; // luu thanh pho dau, cuoi va so thanh pho muon di


//# Ð?c d? li?u vào
void input(){
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
        }
    
}

bool isUCV(int k, int j) {
	if (mark[j] == 1) return false;
	if (c[x[k-1]][j] == 0) return false;
	return true;
}

//# Thu?t toán quay lui
void TRY(int k){
	// i la chi so cua vector place
    for(int i = 2; i < num_place; i++){
		// code here
        if (isUCV(k,place[i])) {
        	x[k] = place[i];
        	mark[place[i]] = 1;
			curr += c[x[k-1]][x[k]];
			// loi giai bo phan cap cuoi, 
			// tinh chi phi den tp cuoi cung de so sanh lay best
			if (k == num_place-1) {
				if (c[x[k]][des] != 0) {
					curr += c[x[k]][des];
					best = (best > curr ? curr : best);
					curr -= c[x[k]][des];
				}
				
			}
			else TRY(k+1);
			
			// thuc hien xog 1 loi giai khoi phuc trang thai ban dau
			mark[place[i]] = 0;
			curr -= c[x[k-1]][x[k]];
		}
    }
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    input();
    
    string str; getline(cin,str);
    
    while (r>0) {
    	best = INT_MAX;
    	curr = 0;
    	getline(cin, str);
    place.push_back(-1);
    while (!str.empty()){
        stringstream convert(str.substr(0, str.find(" ")));
        int tmp = 0;
        convert >> tmp;
        place.push_back(tmp);

        if (str.find(" ") > str.size()){
            break;
        } else {
            str.erase(0, str.find(" ") + 1); // Update string
        }
    }
    
    start = place[1];
    des = place[place.size()-1];
    num_place = place.size()-1;
    x[1] = start;
    x[num_place] = des;
    for(int i=0; i<MAX; i++) mark[i] = 0;
    
    // cout << start << " " << des << " " << num_place << endl;
    // for (int i = 1; i <= num_place; i++) cout << place[i] << " ";
    
    TRY(2);
    if(best == INT_MAX) cout << "0" << endl;
    else cout << best << endl;
    
    place.erase(place.begin(), place.end());
    r--;
    	
	} 
    
    return 0;
}
