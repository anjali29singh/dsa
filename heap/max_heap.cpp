#include <bits/stdc++.h>

using namespace std;

void construct_max_heap(vector<int> &arr, int i, int n)
{

    int largest = i;

    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && arr[largest] < arr[l])
        largest = l;
    if (r < n && arr[largest] < arr[r])
        largest = r;

    if (largest != i)
    {

        swap(arr[largest], arr[i]);
        construct_max_heap(arr, largest, n);
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

        construct_max_heap(arr, i, n);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}