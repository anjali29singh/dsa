#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < (n - 1); i++)
    {
        int ind_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[ind_min])
                ind_min = j;
        }
        swap(arr[i], arr[ind_min]);
    }
    for (int j = 0; j < n; j++)
    {
        cout << arr[j];
    }

    return 0;
}