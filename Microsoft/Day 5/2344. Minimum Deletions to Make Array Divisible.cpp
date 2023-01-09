#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int comm = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++)
        {
            comm = __gcd(comm, numsDivide[i]);
        }
        map<int, int> mp;
        int com = comm;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (comm % nums[i] == 0)
            {
                com = min(com, nums[i]);
            }
        }
        int ans = 0, Min = INT_MAX;
        if (mp.find(com) == mp.end())
        {
            return -1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < com)
            {
                ans++;
            }
        }
        return ans;
    }
};