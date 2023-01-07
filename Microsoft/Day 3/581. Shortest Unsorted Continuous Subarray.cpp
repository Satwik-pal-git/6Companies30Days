#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        int s = temp.size(), e = -1;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] != nums[i])
            {
                s = min(s, i);
                e = max(e, i);
            }
        }
        if (s <= e)
            return (e - s + 1);
        return 0;
    }
};