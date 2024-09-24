class Solution {
public:
    int difference(int i,int sum,vector<int>&nums)
    {
        if(i==0)
        {
            if(sum==0 && nums[0]==0) return 2;
            if(sum-nums[0]==0 || sum==0) return 1;
            return 0;
        }
        int notpick = difference(i-1,sum,nums);

        int pick = 0;

        if(nums[i]<=sum)
        {
            pick = difference(i-1,sum-nums[i],nums);
        }

        return pick+notpick;
    }
    // int func(vector<int> & nums,int sum,int i)
    // {
    //     if(i<0 && sum==0) return 1;
    //     if(i<0) return 0;
    //     int plus = 0;
    //     plus = func(nums,sum-nums[i],i-1);
    //     int minus = func(nums,sum+nums[i],i-1);
    //     return plus+minus;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return func(nums,target,nums.size()-1);

        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }

        if((sum-target)%2!=0) return 0;
        int s2 = (sum-target)/2;
        return difference(n-1,s2,nums);

    }
};