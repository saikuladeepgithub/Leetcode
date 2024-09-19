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
        // vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        // return func(n-1,nums,sum/2,dp);


        // Tabulation part
       
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

        
        for(int i=0;i<n;i++)
        {
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;
        sum=sum/2;
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool take=false;

                if(target-nums[i]>=0) take = dp[i-1][target-nums[i]];

                bool nottake = dp[i-1][target];

                dp[i][target] = (take | nottake);
            }
        }
        return dp[n-1][sum];

    }
};