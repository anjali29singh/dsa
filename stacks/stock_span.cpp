/*The stock span problem is a financial problem where
 we have a series of n daily price quotes for a stock
 and we need to calculate the span of the stock’s price for all n days.
 The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day,
 for which the price of the stock on the current day is less than its price on the given day. */

#include <bits/stdc++.h>
#include <stack>
using namespace std;
void firstgreatest(int price[], int N, int span[])
{
    stack<int> st;
    st.push(0);
    for (int i = 1; i < N; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        span[i] = (st.empty() ? i + 1 : (i - st.top()));
        st.push(i);
    }
}
int main()
{
    int N;
    cin >> N;
    int arr[N];
    int span[N] = {1};
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    span[0] = 1;
    firstgreatest(arr, N, span);
    for (int i = 0; i < N; i++)
        cout << span[i] << " ";
    cout << endl;
    return 0;
}