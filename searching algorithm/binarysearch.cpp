#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[20] = {1, 2, 3, 4, 6, 11, 23, 45, 78, 0, 17, 43, 55, 65, 99, 51, 87, 19,
                 20, 41};
    sort(a, a + 20);
    int x;
    cin >> x;
    int l = 0, r = 19;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (a[m] < x)
            l = m + 1;
        else if (a[m] > x)
            r = m - 1;
        else
        {
            cout << "found" << endl;
            break;
        }
    }
    if (l == r || l > r)
        cout << "the number you are searching is not present" << endl;
    return 0;
}