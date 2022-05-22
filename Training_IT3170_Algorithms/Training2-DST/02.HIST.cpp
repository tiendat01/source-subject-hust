// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     unsigned long long n;
//     while ((cin >> n) && n != 0) {
//         vector<unsigned long long> histogram;
//         for (unsigned long long i = 0; i < n; i++) {
//             unsigned long long input;
//             cin >> input;
//             histogram.push_back(input);
//         }

//         // algorithm here:
//         unsigned long long area = 0, max_area = 0;
//         for (unsigned long long i = 0; i < n; i++) {
//             unsigned long long left = i, right = i;
//             while (left > 0 && histogram[left-1] >= histogram[i]) left--;
//             while (right < n-1 && histogram[right+1] >= histogram[i]) right++;
//             area = histogram[i] * (right-left+1);
//             max_area = max_area < area ? area : max_area;
//         }
//         cout << max_area << endl;
//     }
//     return 0;
// }





// A Divide and Conquer Program to find maximum rectangular area in a histogram
// #include <bits/stdc++.h>
// using namespace std;
 
// // A utility function to find minimum of three integers
// int max(int x, int y, int z)
// {  return max(max(x, y), z); }
 
// // A utility function to get minimum of two numbers in hist[]
// int minVal(int *hist, int i, int j)
// {
//     if (i == -1) return j;
//     if (j == -1) return i;
//     return (hist[i] < hist[j])? i : j;
// }
 
// // A utility function to get the middle index from corner indexes.
// int getMid(int s, int e)
// {   return s + (e -s)/2; }
 
// /*  A recursive function to get the index of minimum value in a given range of
//     indexes. The following are parameters for this function.
 
//     hist   --> Input array for which segment tree is built
//     st    --> Pointer to segment tree
//     index --> Index of current node in the segment tree. Initially 0 is
//              passed as root is always at index 0
//     ss & se  --> Starting and ending indexes of the segment represented by
//                  current node, i.e., st[index]
//     qs & qe  --> Starting and ending indexes of query range */
// int RMQUtil(int *hist, int *st, int ss, int se, int qs, int qe, int index)
// {
//     // If segment of this node is a part of given range, then return the
//     // min of the segment
//     if (qs <= ss && qe >= se)
//         return st[index];
 
//     // If segment of this node is outside the given range
//     if (se < qs || ss > qe)
//         return -1;
 
//     // If a part of this segment overlaps with the given range
//     int mid = getMid(ss, se);
//     return minVal(hist, RMQUtil(hist, st, ss, mid, qs, qe, 2*index+1),
//                   RMQUtil(hist, st, mid+1, se, qs, qe, 2*index+2));
// }
 
// // Return index of minimum element in range from index qs (query start) to
// // qe (query end).  It mainly uses RMQUtil()
// int RMQ(int *hist, int *st, int n, int qs, int qe)
// {
//     // Check for erroneous input values
//     if (qs < 0 || qe > n-1 || qs > qe)
//     {
//         cout << "Invalid Input";
//         return -1;
//     }
 
//     return RMQUtil(hist, st, 0, n-1, qs, qe, 0);
// }
 
// // A recursive function that constructs Segment Tree for hist[ss..se].
// // si is index of current node in segment tree st
// int constructSTUtil(int hist[], int ss, int se, int *st, int si)
// {
//     // If there is one element in array, store it in current node of
//     // segment tree and return
//     if (ss == se)
//        return (st[si] = ss);
 
//     // If there are more than one elements, then recur for left and
//     // right subtrees and store the minimum of two values in this node
//     int mid = getMid(ss, se);
//     st[si] =  minVal(hist, constructSTUtil(hist, ss, mid, st, si*2+1),
//                      constructSTUtil(hist, mid+1, se, st, si*2+2));
//     return st[si];
// }
 
// /* Function to construct segment tree from given array. This function
//    allocates memory for segment tree and calls constructSTUtil() to
//    fill the allocated memory */
// int *constructST(int hist[], int n)
// {
//     // Allocate memory for segment tree
//     int x = (int)(ceil(log2(n))); //Height of segment tree
//     int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
//     int *st = new int[max_size];
 
//     // Fill the allocated memory st
//     constructSTUtil(hist, 0, n-1, st, 0);
 
//     // Return the constructed segment tree
//     return st;
// }
 
// // A recursive function to find the maximum rectangular area.
// // It uses segment tree 'st' to find the minimum value in hist[l..r]
// int getMaxAreaRec(int *hist, int *st, int n, int l, int r)
// {
//     // Base cases
//     if (l > r)  return INT_MIN;
//     if (l == r)  return hist[l];
 
//     // Find index of the minimum value in given range
//     // This takes O(Logn)time
//     int m = RMQ(hist, st, n, l, r);
 
//     /* Return maximum of following three possible cases
//        a) Maximum area in Left of min value (not including the min)
//        a) Maximum area in right of min value (not including the min)
//        c) Maximum area including min */
//     return max(getMaxAreaRec(hist, st, n, l, m-1),
//                getMaxAreaRec(hist, st, n, m+1, r),
//                (r-l+1)*(hist[m]) );
// }
 
// // The main function to find max area
// int getMaxArea(int hist[], int n)
// {
//     // Build segment tree from given array. This takes
//     // O(n) time
//     int *st = constructST(hist, n);
 
//     // Use recursive utility function to find the
//     // maximum area
//     return getMaxAreaRec(hist, st, n, 0, n-1);
// }
 
// // Driver program to test above functions
// int main()
// {
//     int hist[] =  {6, 1, 5, 4, 5, 2, 6};
//     int n = sizeof(hist)/sizeof(hist[0]);
//     cout << "Maximum area is " << getMaxArea(hist, n);
//     return 0;
// }




// O(n) : stack
#include <bits/stdc++.h>

using namespace std;

struct StackType {
    unsigned long long index;
    unsigned long long value;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    unsigned long long n;
    while ((cin >> n) && n != 0) {
        vector<unsigned long long> histogram;
        for (unsigned long long i = 0; i < n; i++) {
            unsigned long long input;
            cin >> input;
            histogram.push_back(input);
        }
 
        // algorithm here:
        stack<StackType> s;
        unsigned long long i = 0;
        unsigned long long area = 0, max = 0;
        // O(n)
        while (i < n) {
            if (s.empty() || s.top().value <= histogram[i]) {
                StackType st {i, histogram[i]};
                s.push(st);
                i++;
            }
            else {
                StackType top = s.top();
                s.pop();
                // cal area:
                area = top.value * (i - top.index);
                max = max < area ? area : max;
                // check again, sau khi da pop thanh dai hon thanh[i], neu thanh[i] t/m dk s.push()
                if (s.empty() || s.top().value <= histogram[i]) {
                    StackType st {top.index, histogram[i]}; // thay doi index cua thanh vua bi s.pop()
                    s.push(st);
                    i++;
                }
            }
        } // end while: sau vong lap nay: stack co the empty hoac ko. Neu ko, cac value cua cac ptu trong stack sap xep giam dan tu dau stack

        
        while (!s.empty()) {
            StackType top = s.top();
            s.pop();
            area = top.value * (i - top.index);
            max = max < area ? area : max;
        }

        cout << max << endl;
    }
    return 0;
}