#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int totsum=0, initsum=0;
        for(int i=0;i<nums.size();i++)
        {
            totsum+=nums[i];
            initsum+=(i*nums[i]);
        }
        int ans=initsum;
        int j=nums.size()-1;
        while(j>=0)
        {
            initsum+=totsum-nums[j]*nums.size();
            // initsum+=t;
            ans=max(ans, initsum);
            j--;
        }
        return ans;
    }
};