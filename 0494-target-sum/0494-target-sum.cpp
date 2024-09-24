class Solution {
public:
    int func(vector<int> & nums,int sum,int i)
    {
        if(i<0 && sum==0) return 1;
        if(i<0) return 0;
        int plus = 0;
        plus = func(nums,sum-nums[i],i-1);
        int minus = func(nums,sum+nums[i],i-1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums,target,nums.size()-1);
    }
};