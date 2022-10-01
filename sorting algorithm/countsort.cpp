#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {7, 5, 3, 1, 4, 5, 1, 3, 2, 3};
    int count[10] = {0};
    int sorted[10] = {0};
    for (int i = 0; i < 10; i++)
        // number of occurence of each item
        count[arr[i]] = count[arr[i]] + 1;

    // find prefix sum
    for (int i = 1; i < 10; i++)

        count[i] = count[i - 1] + count[i];
    // rotating array clockwise one times to get starting index
    for (int j = 9; j >= 0; j--)

        count[j] = count[j - 1];
    for (int i = 0; i < 10; i++)
    {
        sorted[count[arr[i]]] = arr[i];
        count[arr[i]]++;
    }

    for (int j = 0; j < 10; j++)
        cout << sorted[j] << endl;

    return 0;
}