#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs_bob(int node, int par, vector<int> &temp, int unit, vector<vector<int>> &v)
    {
        temp[node] = unit;
        if (node == 0)
        {
            return 1;
        }
        for (auto it : v[node])
        {
            if (it != par)
            {
                if (dfs_bob(it, node, temp, unit + 1, v))
                {
                    return 1;
                }
            }
        }
        temp[node] = -1;
        return 0;
    }
    // int dfs(vector<vector<int>>& v,vector<int>& amount, int par, int node, int unit, vector<int> temp)
    // {
    //     int ans=INT_MIN;
    //     for(auto it:v[node])
    //     {
    //         if(it!=par)
    //         {
    //             ans=max(ans, dfs(v, amount, node, it, unit+1, temp));
    //         }
    //     }
    //     if(ans==INT_MIN) ans=0;
    //     if(temp[node]==unit)
    //     {
    //         ans+=amount[node]/2;
    //     }else if(temp[node]==-1 || temp[node]>unit){
    //         ans+=(amount[node]);
    //     }
    //     return ans;
    // }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {

        vector<vector<int>> v(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            v[edges[i][1]].push_back(edges[i][0]);
            v[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> temp(edges.size() + 1, -1); // -1 -> not visisted through that node

        dfs_bob(bob, -1, temp, 0, v);

        vector<int> vis(edges.size() + 1, 0);
        queue<vector<int>> q;
        q.push({0, 0, 0});
        int ans = INT_MIN;
        while (!q.empty())
        {
            vector<int> t = q.front();
            q.pop();
            vis[t[0]] = 1;
            if (temp[t[0]] == t[1])
            {
                t[2] += amount[t[0]] / 2;
            }
            else if (temp[t[0]] == -1 || temp[t[0]] > t[1])
            {
                t[2] += (amount[t[0]]);
            }
            for (auto it : v[t[0]])
            {
                if (vis[it] == 0)
                {
                    q.push({it, t[1] + 1, t[2]});
                }
            }
            if (v[t[0]].size() == 1 && t[0] != 0)
            {
                ans = max(ans, t[2]);
            }
        }
        return ans;
    }
};