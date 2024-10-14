#include <bits/stdc++.h>

using namespace std;

void construct_min_heap(vector<int> &arr, int i, int n)
{

    int smallest = i;

    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && arr[smallest] > arr[l])
        smallest = l;
    if (r < n && arr[smallest] > arr[r])
        smallest = r;

    if (smallest != i)
    {

        swap(arr[smallest], arr[i]);
        construct_min_heap(arr, smallest, n);
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        construct_min_heap(arr, i, n);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}