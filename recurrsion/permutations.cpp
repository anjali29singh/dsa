
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> temp, vector<vector<int>> &ans)
{

    if (temp.size() == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    else
    {

        for (int i = 0; i < nums.size(); i++)
        {

            if (find(temp.begin(), temp.end(), nums[i]) != temp.end())
                continue;

            temp.push_back(nums[i]);
            solve(nums, temp, ans);
            temp.pop_back();
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> ans;
    vector<int> temp;
    solve(nums, temp, ans);

        return 0;
}