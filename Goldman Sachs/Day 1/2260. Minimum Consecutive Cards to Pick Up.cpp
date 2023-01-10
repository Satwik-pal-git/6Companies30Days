#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int ans = INT_MAX;
        unordered_map<int, int> mp;

        for (int i = 0; i < cards.size(); i++)
        {
            if (mp[cards[i]] == 0)
            {
                mp[cards[i]] = i + 1;
            }
            else
            {
                ans = min(ans, i + 1 - mp[cards[i]]);
                mp[cards[i]] = i + 1;
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans + 1;
    }
};