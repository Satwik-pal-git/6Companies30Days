#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < profits.size(); i++)
        {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end(), cmp);
        // for(auto it:v)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int ans = w;
        // prof, cap
        priority_queue<pair<int, int>> pq;
        int ind = 0;
        while (ind < profits.size())
        {
            bool flg = 0;
            while (v[ind].first <= w && ind < profits.size())
            {
                flg = 1;
                pq.push({v[ind].second, v[ind].first});
                // cout<<v[ind].second<<" "<<v[ind].first<<endl;
                ind++;
            }
            if (pq.empty() == 0 && k > 0 && pq.top().second <= w)
            {
                w += pq.top().first;
                pq.pop();
                k--;
                ans = max(ans, w);
            }
            if (flg == 0)
                break;
        }
        while (!pq.empty() && k > 0)
        {
            if (pq.top().second <= w)
            {
                w += pq.top().first;
                pq.pop();
                k--;
                ans = max(ans, w);
            }
        }
        return ans;
    }
};