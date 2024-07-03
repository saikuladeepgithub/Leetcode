#include <bits/stdc++.h>
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<4) return 0;
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        for(int i=0;i<4;i++)
        {
            res=min(res,nums[n+i-3-1]-nums[i]);
        }
        return res;
    }
};