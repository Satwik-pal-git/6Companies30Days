#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> vis(numCourses, 0);

        while (!q.empty())
        {
            int N = q.front();
            q.pop();
            vis[N] = 1;
            for (int x = 0; x < adj[N].size(); x++)
            {
                inDegree[adj[N][x]]--;
                if (inDegree[adj[N][x]] == 0)
                {
                    q.push(adj[N][x]);
                }
            }
        }
        for (auto it : vis)
        {
            if (it == 0)
            {
                return false;
            }
        }
        return true;
    }
};