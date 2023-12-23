#include <bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int> &arr)
{

    vector<int> temp;

    int l = low, r = mid + 1;

    while (l <= mid && r <= high)
    {
        if (arr[l] <= arr[r])
        {

            temp.push_back(arr[l]);
            l++;
        }
        else
        {
            temp.push_back(arr[r]);
            r++;
        }
    }
    while (l <= mid)
    {
        temp.push_back(arr[l]);
        l++;
    }
    while (r <= high)
    {
        temp.push_back(arr[r]);
        r++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}
void merge_sort(int low, int high, vector<int> &arr)
{

    if (low >= high)
        return;

    int mid = (low + high) / 2;

    merge_sort(low, mid, arr);

    merge_sort(mid + 1, high, arr);

    merge(low, mid, high, arr);
}
int main()
{

    vector<int> arr = {1, 3, 5, 7, 4, 2, 6, 8};
    merge_sort(0, 8, arr);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << endl;
    return 0;
}