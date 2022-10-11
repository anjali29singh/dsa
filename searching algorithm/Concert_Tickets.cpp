#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int H[n], T[m];
    set<pair<int, int>> sortedTick;
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
        sortedTick.insert({H[i], i});
    }
    for (int j = 0; j < m; j++)
        cin >> T[j];
    for (int i = 0; i < m; i++)
    {
        auto match = sortedTick.lower_bound({T[i] + 1, 0});
        if (match == sortedTick.begin())
            cout << -1 << endl;
        else
        {
            match--;
            cout << (*match).first << endl;
            sortedTick.erase(match);
        }
    }

    return 0;
}