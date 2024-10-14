#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
// a -> 100
// b -> 4

int find_min_power(int p, int au, int bu, unordered_map<int, int> &dp)
{
    if (p <= 0)
        return 0;

    if (dp.find(p) != dp.end())
        return dp[p];

    int a = au + find_min_power(p - 100, au, bu, dp);
    int b = bu + find_min_power(p - 4, au, bu, dp);

    return dp[p] = min(a, b);
}

int main()
{
}