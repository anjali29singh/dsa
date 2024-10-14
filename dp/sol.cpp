#include <bits/stdc++.h>
using namespace std;

int getVowelNo(char c)
{

    if (c == 'a')
        return 0;
    if (c == 'e')
        return 1;
    if (c == 'i')
        return 2;
    if (c == 'o')
        return 3;
    if (c == 'u')
        return 4;

    return -1;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(5, 0));

    if (s[0] == 'a')
        dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {

        int x = getVowelNo(s[i]);

        if (x == -1)
            dp[i] = dp[i - 1];
        else
        {
            dp[i] = dp[i - 1];
            if (x > 0)
                dp[i][x] = max(dp[i][x], dp[i - 1][x - 1] + 1);

            dp[i][x] = max(dp[i][x], dp[i - 1][x] + 1);
        }
    }

    cout << dp[n - 1][4] << endl;

    return 0;
}