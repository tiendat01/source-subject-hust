// #include <iostream>
// #include <stdio.h>
// #include <string>
// #include <string.h>
// #include <math.h>
// #include <queue>
// #include <algorithm>
// const int inf=0x3f3f3f3f;
// const int maxx=1000010;
// using namespace std;
// int a[maxx],b[maxx];
// int x[maxx],p[maxx];
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1; i<=n; i++)
//         scanf("%d",&a[i]);
//     int sum=0;
//     for(int i=n; i>=1; i--)
//     {
//         if(sum==0 || x[sum-1]>=a[i])
//         {
//             x[sum]=a[i];
//             p[sum++]=i;
//             b[i]=-1;
//         }
//         else
//         {
//             int k,l=0,r=sum-1;
//             while(l<=r)
//             {
//                 int mid=(l+r)>>1;
//                 if(x[mid]<a[i])
//                 {
//                     k=mid;
//                     r=mid-1;
//                 }
//                 else l=mid+1;
//             }
//             b[i]=p[k]-i-1;
//         }
//     }
//     printf("%d",b[1]);
//     for(int i=2; i<=n; i++)
//         printf(" %d",b[i]);
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N = 1005;


int main(){
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T>0){
        int L, C;
        cin >> L >> C;

        vector<pair<int,int> > pre,last;
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) pre.push_back({i,j});
            }

        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) last.push_back({i,j});
            }

        int maxSl = 0;
        map<pair<int,int>, int> m;
        int lensPre = pre.size();
        int lensLast = last.size();
        for(int i=0; i<lensPre; i++)
            for(int j=0; j<lensLast; j++){
                int a = last[j].first - pre[i].first + N;
                int b = last[j].second - pre[i].second + N;
                m[{a,b}]++;
                maxSl = max(m[{a,b}],maxSl);
            }

        cout << maxSl << endl;
        T--;
    }

    return 0;
}