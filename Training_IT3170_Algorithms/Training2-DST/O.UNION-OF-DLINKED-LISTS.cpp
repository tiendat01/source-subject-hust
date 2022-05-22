#include <bits/stdc++.h>

using namespace std;

struct cell {
    int val;
    int l;
    int r;
};

int main() {
    int n;
    cin >> n;
    vector<cell> input;
    input.push_back({0,0,0});
    vector<int> first_cell_val; // luu value cua cell dau moi dl_list ban dau
    vector<int> alone_cell_val; // luu value cua cell 'tu do'
    for (int i = 1; i <= n; i++) {
        int rinput, linput;
        cin >> linput >> rinput;
        input.push_back({i, linput, rinput});
        if (linput == 0 && rinput) first_cell_val.push_back(i);
        if (linput == 0 && rinput == 0) alone_cell_val.push_back(i);
    }

    if (!first_cell_val.empty()) {
        vector<cell> end_lists;
        // end_lists luu tru cell cuoi cua dl_list ban dau
        for (int i = 0; i < first_cell_val.size(); i++) {
            cell last_cell = input[first_cell_val[i]];
            int next = last_cell.r;
            while (next != 0) {
                last_cell = input[next];
                next = last_cell.r;
            }
            end_lists.push_back(last_cell);
        }

        // khi do end_lists.size() == first_cell_val.size()

        // noi cac dl_list lai voi nhau
        for (int i = 0; i < first_cell_val.size()-1; i++) {
            input[end_lists[i].val].r = first_cell_val[i+1];
            input[first_cell_val[i+1]].l = end_lists[i].val;
        }
            
        // noi cac cell 'tu do' vao vi tri dau cua list_result
        // list_result chinh la input sau khi noi 
        cell first_cell = input[first_cell_val[0]];
        for (int i = 0; i < alone_cell_val.size(); i++) {
            input[first_cell.val].l = alone_cell_val[i];
            input[alone_cell_val[i]].r = first_cell.val;
            first_cell = input[alone_cell_val[i]]; 
        }
    }

    // contain only alone_cells
    else {
        cell last_cell;
        for (int i = 0; i < alone_cell_val.size()-1; i++) {
            input[alone_cell_val[i]].r = input[alone_cell_val[i+1]].val;
            input[alone_cell_val[i+1]].l = input[alone_cell_val[i]].val;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << input[i].l << ' ' << input[i].r << endl;
    }
    return 0;
}