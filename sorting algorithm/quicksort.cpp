#include <bits/stdc++.h>
using namespace std;

// first element as pivot
// int partition(int arr[], int low, int high)
// {

//     int pivot = arr[low];
//     int j = high;

//     for (int i = high; i > low; i--)
//     {

//         if (pivot < arr[i])
//         {

//             swap(arr[j], arr[i]);
//             j--;
//         }
//     }

//     swap(arr[low], arr[j]);

//     return j;
// }

// partition when last element is pivot

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];

    int j = low;

    for (int i = low; i < high; i++)
    {

        if (arr[i] < pivot)
        {

            swap(arr[i], arr[j]);
            j++;
        }
    }

    swap(arr[j], arr[high]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{

    if (low >= high)
        return;

    int ind = partition(arr, low, high);
    quick_sort(arr, low, ind - 1);
    quick_sort(arr, ind + 1, high);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}