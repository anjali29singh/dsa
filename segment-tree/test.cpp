#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{

    vector<int> T;

public:
    SegmentTree(int n)
    {

        T.resize(4 * n);
    }

    void build(int l, int r, int v, vector<int> arr)
    {
        if (l == r)
            T[v] = arr[l];

        int mid = (l + r) / 2;

        build(l, mid, 2 * v + 1, arr);
        build(mid + 1, r, 2 * v + 2, arr);

        T[v] = min(T[2 * v + 1], T[2 * v + 2]);
    }
};

// three condition for searching

// 1. partial overalp -> call left and right and then compute from left and right

// 2. if no overlap  return INT_MAX for min number searching in range

// 3. if completely overlap   return T[v]

int main()
{

    return 0;
}