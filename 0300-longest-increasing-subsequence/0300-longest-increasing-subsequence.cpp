class Solution {
public:

    int f(int ind,int prev,vector<int>&nums,vector<vector<int>> &dp)
    {
        if(ind>nums.size()) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int len = 0 + f(ind+1,prev,nums,dp);
     
        if(prev==0 || nums[ind-1]>nums[prev-1])
        {
            len = max(len,1 + f(ind+1,ind,nums,dp));
        }

        return dp[ind][prev]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,0,nums,dp);

        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // // base case are already 0

        // for(int ind = n-1;ind>=1;ind--)
        // {
        //     for(int prev = ind-1;prev>=1;prev--)
        //     {
        //         int len = 0 + f(ind+1,prev,nums,dp);
        // if(dp[ind][prev]!=-1) return dp[ind][prev];
        // if(prev==0 || nums[ind-1]>nums[prev-1])
        // {
        //     len = max(len,1 + f(ind+1,ind,nums,dp));
        // }

        // return dp[ind][prev]=len;
        //     }
        // }
    }
};