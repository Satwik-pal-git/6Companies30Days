#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        map<int, int> mp;
        vector<vector<int>> v;
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                int d = (((v[i][0] - v[j][0]) * (v[i][0] - v[j][0]))) + (((v[i][1] - v[j][1]) * (v[i][1] - v[j][1])));
                mp[d]++;
            }
        }
        bool flg = 0;
        if (mp.size() != 2)
            return 0;
        for (auto it : mp)
        {
            if (it.second == 4)
            {
                flg = 1;
                break;
            }
        }
        if (flg == 0)
            return 0;
        mp.clear();
        for (int i = 0; i < 4; i++)
        {
            map<double, int> mpa;
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                    continue;
                if ((v[i][0] - v[j][0]) == 0)
                {
                    mpa[90]++;
                    // cout<<"here is the angel too\n";
                }
                else
                {
                    double m = (double)(v[i][1] - v[j][1]) / (v[i][0] - v[j][0]);
                    double angel = atan(m) * (180 / 3.14);
                    mpa[angel]++;
                    // cout<<angel<<" <- angel"<<m<<" <- slope \n";
                }
            }
            // for(auto it:mpa)
            // {
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            if (mpa.size() < 3)
                return 0;
            auto it = mpa.begin();
            double a = it->first;
            it++;
            double b = it->first;
            it++;
            double c = it->first;
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if ((int)(a + b) == 90 || (int)(b + c) == 90 || (int)(c + a) == 90 || (int)(abs(a - b)) == 90 || (int)(abs(c - b)) == 90 || (int)(abs(a - c)) == 90)
            {
                return 1;
            }
        }
        return 0;
    }
};