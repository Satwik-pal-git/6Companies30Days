#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rev(int n)
    {
        int x = n;
        int ans = 0;
        string t = to_string(n);
        int base = t.size() - 1;
        reverse(t.begin(), t.end());
        int i = 0;
        while (i < t.size())
        {
            ans += ((t[i] - '0') * pow(10, base));
            base--;
            i++;
        }
        return ans;
    }
    int countNicePairs(vector<int> &nums)
    {
        long long int Mod = 1e9 + 7;
        unordered_map<long long int, long long int> mp;
        for (auto it : nums)
        {
            int val = it - rev(it);
            mp[val]++;
        }
        int ans = 0;
        for (auto it : mp)
        {
            long long int x = it.second;

            int v = (x * (x - 1) / 2) % Mod;
            ans = (ans + v) % Mod;
        }
        return ans;
    }
};