#include <bits/stdc++.h>
#include "UNION-FIND.cpp"

int main() {
    Union_Find disjoint_set = Union_Find(6+1); // 1->6

    disjoint_set.Union(4,1);
    disjoint_set.Union(3,6);
    disjoint_set.Union(6,5);

    //
    disjoint_set.Union(4,2);
    //
    disjoint_set.Union(3,6);
    disjoint_set.cout_find(6); cout << endl;
    //
    Union_Find tmp = disjoint_set;
    disjoint_set.Union(1,6);

    disjoint_set.cout_find(6); cout << endl;

    disjoint_set = tmp;
    disjoint_set.cout_find(6);
}