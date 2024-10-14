#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    unordered_map<int, int> freq;

    vector<int> suffix(n, 0); // suffix of frequency of c
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    if (arr[n - 1] == c)
        suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {

        if (arr[i] == c)
            suffix[i] = 1 + suffix[i + 1];
        else
            suffix[i] = suffix[i + 1];
    }

    int maxFreq = 0, ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        freq[arr[i]]++;
        maxFreq = max(maxFreq, freq[arr[i]]);
        ans = max(ans, maxFreq + suffix[i + 1]);
    }
    cout << ans << endl;
}