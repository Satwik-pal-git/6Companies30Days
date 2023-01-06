#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(vector<int> nums, vector<int> &ans, int ind, int prev, vector<int> &t, vector<int> &dp)
    {
        if (ans.size() < t.size())
        {
            ans = t;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            int x = t.size();
            if ((x > dp[i]) && (nums[i] % prev == 0))
            {
                dp[i] = x;
                t.push_back(nums[i]);
                f(nums, ans, i + 1, nums[i], t, dp);
                t.pop_back();
            }
        }
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> ans, temp;
        vector<int> dp(nums.size(), -1);
        sort(nums.begin(), nums.end());
        f(nums, ans, 0, 1, temp, dp);
        return ans;
    }
};