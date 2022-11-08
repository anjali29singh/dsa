#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d; // d is the position by which array is rotated
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int temp[n];
    int k = 0;
    for (int i = d; i < n; i++)
    {
        temp[k] = arr[i];
        k = k + 1;
    }
    for (int i = 0; i < d; i++)
    {
        temp[k] = arr[i];
        k = k + 1;
    }
    for (int j = 0; j < n; j++)
    {
        arr[j] = temp[j];
        cout << arr[j] << endl;
    }

    return 0;
}