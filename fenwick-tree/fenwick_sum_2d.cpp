// zero based
#include <bits/stdc++.h>
using namespace std;

struct fenwick2D
{
    int N, M;
    vector<vector<int>> T;

    fenwick2D(int n, int m)
    {
        this->N = n;
        this->M = m;
        T.resize(N);
        for (int i = 0; i < N; i++)
            T[i].resize(M, 0);
    }

    fenwick2D(vector<vector<int>> &arr) : fenwick2D(arr.size(), arr[0].size())
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                update(i, j, arr[i][j]);
        }
    }

    void update(int x, int y, int val)
    {

        for (int i = x; i < N; i = i + (i & (-i)))
        {
            for (int j = y; j < M; j = j + (j & (-j)))
            {
                T[i][j] = T[i][j] + val;
            }
        }
    }

    int getSum(int r, int c)
    {
        int ans = 0;
        for (int i = r; i >= 0; i = i - (i & (-i)))
        {
            for (int j = c; j >= 0; j = j - (j & (-j)))
                ans = ans + T[i][j];
        }

        return ans;
    }

    // get sum in the range of (r1,c1) (r2,c2)

    int getSum(int r1, int c1, int r2, int c2)
    {

        return (getSum(r2, c2) - getSum(r1 - 1, c2) - getSum(r2, c1 - 1) + getSum(r1, c1 - 1));
    }
};
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> arr{
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };

    fenwick2D F = fenwick2D(arr);
    cout << F.getSum(3, 3) << '\n';

    return 0;
}