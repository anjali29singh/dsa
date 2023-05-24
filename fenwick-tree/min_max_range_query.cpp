// finding min in range(0,r);

#include <bits/stdc++.h>
using namespace std;
struct fenwickMin
{

    int N;
    const int INF = (int)1e9;
    vector<int> T;
    fenwickMin(int n)
    {
        this->N = n + 1;
        T.assign(N, INF);
    }
    fenwickMin(vector<int> arr) : fenwickMin(arr.size())
    {
        for (int i = 0; i < arr.size(); i++)
            update(i, arr[i]);
    }

    void update(int i, int x)
    {

        for (++i; i < N; i = i + (i & (-i)))
        {
            T[i] = min(T[i], x);
        }
    }

    int getmin(int r)
    {
        int ans = INF;
        for (++r; r > 0; r = r - (r & (-r)))
            ans = min(ans, T[r]);
        return ans;
    }
};
// fenwick tree to get the maximum element in a range
struct fenwickMax
{

    int N;
    vector<int> T;
    fenwickMax(int n)
    {
        this->N = n + 1;
        T.assign(N, 0);
    }
    fenwickMax(vector<int> arr) : fenwickMax(arr.size())
    {
        for (int i = 0; i < arr.size(); i++)
            update(i, arr[i]);
    }

    void update(int i, int x)
    {

        for (++i; i < N; i = i + (i & (-i)))
        {
            T[i] = max(T[i], x);
        }
    }

    int getmax(int r)
    {
        int ans = 0;
        for (++r; r > 0; r = r - (r & (-r)))
            ans = max(ans, T[r]);
        return ans;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    fenwickMin fenMin = fenwickMin(arr);
    fenwickMax fenMax = fenwickMax(arr);

    // find minimum element in the range (0,q);
    cout << fenMin.getmin(q) << '\n';
    cout << fenMax.getmax(q) << '\n';

    return 0;
}