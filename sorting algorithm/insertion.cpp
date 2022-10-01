#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = arr[i];
        while (j >= 0 && key < arr[j])
        {
            // shifting elements from 0 to i-1 that are greater than arr[key]
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}