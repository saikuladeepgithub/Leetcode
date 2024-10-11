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
        
        
        // int n = nums.size();
        // // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // // return f(1,0,nums,dp);

        // vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        // // base case are already 0

        // for(int ind = n;ind>=1;ind--)
        // {
        //     for(int prev=ind-1;prev>=0;prev--)
        //     {
        //         int len = 0 + dp[ind+1][prev];
        //         if(prev==0 || nums[ind-1]>nums[prev-1])
        //         {
        //             len = max(len,1 + dp[ind+1][ind]);
        //         }

        //         dp[ind][prev]=len;
        //     }
        // }

        // return dp[1][0];








        // MY APPROAH\CH
        int n = nums.size();


        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            int buddy = 1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i] && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j] +1;
                }
            }
        }

        int buddy =0;
        for(int i=0;i<n;i++)
        {
            buddy = max(buddy,dp[i]);
        }

        return buddy;
    }
};