class Solution {
public:
    int func(int ind,int target,vector<int> & coins,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            return target%coins[0]==0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];

        int nottake = func(ind-1,target,coins,dp);

        int take = 0;

        if(coins[ind]<=target) take = func(ind,target-coins[ind],coins,dp);

        dp[ind][target] = take + nottake;
        return take + nottake;
    }
    int change(int amount, vector<int>& coins) {
       
        int n = coins.size();

        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        // return func(n-1,amount,coins,dp);


        // Tabulation part

        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));

        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0) dp[0][t]=1;
            else dp[0][t]=0;
        }

        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                long long nottake = dp[i-1][t];

                long long take = 0;
                if(coins[i]<=t)
                    take=dp[i][t-coins[i]];

                dp[i][t] = (int)(take+nottake) ;
            }
        }
        return (int)dp[n-1][amount];
    }
};