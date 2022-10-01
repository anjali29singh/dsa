#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int j = 1; j < n; j++)
    {
        bool swapped = false;
        for (int k = 0; k < n - j - 1; k++) // last j elements are already sorted
        {
            if (a[k] > a[k + 1])
            {
                swap(a[k], a[k + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    for (int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}