#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(vector<vector<int>> &ans, int target, int k, int ind, int t, vector<int> &temp)
    {
        if (k < 0 || target < 0)
        {
            return;
        }
        if (temp.size() == t && target == 0 && k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (temp.size() >= t && target != 0)
            return;
        for (int i = ind; i <= 9; i++)
        {
            if (i > target)
                ;
            temp.push_back(i);
            f(ans, target - i, k - 1, i + 1, t, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        int t = (k * (k + 1)) / 2;
        if (t > n || n >= 46)
            return ans;
        vector<int> temp;
        f(ans, n, k, 1, k, temp);
        return ans;
    }
};