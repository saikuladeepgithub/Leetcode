class Solution {
public:

    bool func(int i,vector<int> & nums,int sum,vector<vector<int>> & dp)
    {
        if(sum==0) return true;
        if(i==0) return nums[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=false;
        if(sum-nums[i]>=0) take=func(i-1,nums,sum-nums[i],dp);

        int nottake = func(i-1,nums,sum,dp);

        dp[i][sum]=(take|nottake);
        return take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }

        if(sum%2!=0)  return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return func(n-1,nums,sum/2,dp);
    }
};