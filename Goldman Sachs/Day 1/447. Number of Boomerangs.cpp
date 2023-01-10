#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            map<int, int> mp;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                int d = ((points[i][0] - points[j][0]) * (points[i][0] - points[j][0])) + ((points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
                // cout<<d<<" ";
                mp[d]++;
            }
            for (auto it : mp)
            {
                if (it.second >= 2)
                {
                    ans += (it.second * (it.second - 1));
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};