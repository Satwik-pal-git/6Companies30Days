#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 1;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> m;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }

                double num = (double)(points[i][0] - points[j][0]) / (points[i][1] - points[j][1]);
                double val = atan(num);

                m[val]++;
                ans = max(ans, m[val] + 1);
            }
        }
        return ans;
    }
};