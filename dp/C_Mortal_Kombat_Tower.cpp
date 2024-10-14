#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int i, int ch, vector<vector<int>> &dp, int points)
{

    if (i >= arr.size())
        return points;

    if (dp[i][ch] != -1)
        return dp[i][ch];
    int killOne = INT_MAX, killTwo = INT_MAX;
    if (ch == 0)
    {

        // kill one

        killOne = solve(arr, i + 1, 1, dp, points + arr[i]);
        // kill two
        if (i + 1 < arr.size())
            killTwo = solve(arr, i + 2, 1, dp, points + arr[i] + arr[i + 1]);
    }

    else
    {
        killOne = solve(arr, i + 1, 0, dp, points);

        killTwo = solve(arr, i + 2, 0, dp, points);
    }

    return dp[i][ch] = min(killOne, killTwo);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<vector<int>> dp(n, vector<int>(2, -1));
        solve(arr, 0, 0, dp, 0);
        cout << min(dp[0][0], dp[0][1]) << endl;
    }
    return 0;
}