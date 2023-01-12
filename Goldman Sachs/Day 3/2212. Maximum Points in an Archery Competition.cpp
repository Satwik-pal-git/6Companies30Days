#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans;
    int tot = 0;
    void f(vector<int> alicearrows, int ind, int arrow, vector<int> &v, int sum)
    {
        if (ind == -1 || arrow <= 0)
        {
            if (sum > tot)
            {
                tot = sum;
                if (arrow > 0)
                    v[0] += arrow;
                ans = v;
            }
            return;
        }
        int req = alicearrows[ind] + 1;
        if (req <= arrow)
        {
            v[ind] = req;
            f(alicearrows, ind - 1, arrow - req, v, sum + ind);
            v[ind] = 0;
        }
        f(alicearrows, ind - 1, arrow, v, sum);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        vector<int> v(12);
        f(aliceArrows, 11, numArrows, v, 0);
        return ans;
    }
};