#include <bits/stdc++.h>

using namespace std;

struct task {
    long long x;  // distance
    long long m;  // amount of goods
};

struct myComparation {
        bool operator()(const task& x, const task& y) {
            return x.x < y.x;
        }
};

void print_queue(priority_queue<task, vector<task>, myComparation> pq)
{
	while (!pq.empty())
		{
			cout << pq.top().x << ' ' << pq.top().m << endl;
			pq.pop();
		}
}

// apply only to pq_pos
long long finish_time(priority_queue<task, vector<task>, myComparation> pq, int n, int k) {
    if (n == 0) return 0;
    long long res = pq.top().x;
    int cur = k;

    while (!pq.empty()) {
        task work = pq.top();
        // 3 cases:
        if (work.m < cur) {
            cur -= work.m; // work.m = 0 => clear this task 
            pq.pop();
            if (!pq.empty())
                res += (work.x - pq.top().x); // and cur continue the next task in the previous distance
            else 
                res += work.x; // finish and back to 0
        } 
        else if (work.m > cur) {
            work.m -= cur;
            // come back to 0 and fulfill
            res += work.x;
            cur = k;
            // continue
            res += work.x;
            if (work.m > cur) {
                long long repeat = work.m / k; // cur == k
                long long exceed = work.m % k;
                if (work.m % k) {
                    res += (repeat*2*work.x); // ca di va ve + lan tiep theo la hoan thanh task
                    cur = k*(repeat+1) - work.m; // so luong hang con lai  
                }
                // vua khit
                else {
                    res += ((repeat-1)*2*work.x); // bo qua lan dau tien (x2), bo qua len lan 2, bo qua xuong lan cuoi
                    cur = 0;
                }
                 
            }
            else {
                cur -= work.m;
            }
            pq.pop(); 
            if (cur > 0) {
                if (!pq.empty())
                    res += (work.x - pq.top().x); // and cur continue the next task in the previous distance
                else 
                    res += work.x; // finish and back to 0 
            }
            // cur = 0 => come back
            else {
                if (!pq.empty()) {
                    cur = k;
                    res += work.x + pq.top().x; // cur come back and continue the next task
                }
                else 
                    res += work.x; // finish and come back to 0            
            } 
        }
        else {
            // cur = 0; // clear this task and cur = 0
            pq.pop();
            res += work.x; // cur come back to 0
            cur = k; //  and fulfill
            if (!pq.empty()) res += pq.top().x; // and continue to the next work after fulfilling
        }
    }

    return res;
}

int main() {
    int n, k;
    priority_queue<task, vector<task>, myComparation> pq_pos, pq_neg;

    cin >> n >> k;
    int count = 0;
    for (int i = 0; i < n; i++) {
        task input;
        cin >> input.x >> input.m;
        if (input.x > 0) 
            pq_pos.push(input);
        else {
            count++;
            input.x *= (-1);
            pq_neg.push(input);
        }
    } 

    // print_queue(pq_neg);

    // cout << finish_time(pq_neg, count, k);

    cout << finish_time(pq_pos, n-count, k) + finish_time(pq_neg, count, k);
    return 0;
}