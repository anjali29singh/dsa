#include <bits/stdc++.h>
using namespace std;
void countingsort(int arr[], int n, int exp)
{
    int count[10] = {0};
    int tempsort[n] = {0};
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] / exp;
        count[x % 10] = count[x % 10] + 1;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    // finding starting index
    for (int j = 9; j > 0; j--)
        count[j] = count[j - 1]; // number of elements that comes before j
    for (int j = 0; j < 10; j++)
    {
        cout << count[j] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int d = 3, exp = 1;

    while (d--)
    {
        countingsort(arr, n, exp);
        exp = exp * 10;
    }

    return 0;
}