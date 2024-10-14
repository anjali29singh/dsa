#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{

    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    int largest = i;

    if (l < n && arr[largest] < arr[l])
        largest = l;
    if (r < n && arr[largest] < arr[r])
        largest = r;

    if (largest != i)
    {

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        heapify(arr, n, i);
    }
    // remove largest node from heap , append it to sorted heap array
    // then heapify the remaining heap

    // for (int i = n - 1; i > 0; i--)
    // {

    //     swap(arr[0], arr[i]);
    //     // reduce heap
    //     heapify(arr, i, 0);
    // }
}
int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}