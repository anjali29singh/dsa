#include <bits/stdc++.h>
using namespace std;
void merge_sort(int arr[], int n)
{

    if (n > 1)
    {
        int mid = n / 2;
        int left_arr[mid], right_arr[n - mid];

        for (int i = 0; i < mid; i++)

            left_arr[i] = arr[i];

        for (int j = 0; j < n - mid; j++)

            right_arr[j] = arr[mid + j];

        merge_sort(left_arr, mid);

        merge_sort(right_arr, n - mid);

        int i = 0, j = 0, k = 0;

        while (i < mid && j < n - mid)
        {
            if (left_arr[i] < right_arr[j])
            {
                arr[k] = left_arr[i]; // overwriting in array
                i = i + 1;
            }
            else
            {
                arr[k] = right_arr[j];
                j = j + 1;
            }
            k = k + 1;
        }
        while (i < mid)
        {
            arr[k] = left_arr[i];
            i = i + 1;
            k = k + 1;
        }
        while (j < n - mid)
        {
            arr[k] = right_arr[j];
            j = j + 1;
            k = k + 1;
        }
    }
}
int main()
{
    int arr[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(arr, 8);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << endl;
    return 0;
}