#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    int Arr[N];
    for (int i = 0; i < N; i++)
        cin >> Arr[i];
    sort(Arr, Arr + N);
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        int long long left = 0, right = N - 1;
        while (left + 1 < N - 1)
        {
        }
    }
    return 0;
}