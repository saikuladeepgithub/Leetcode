class Solution {
public:
    int func(int i,vector<int> & coins,int amount,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(amount%coins[0]==0) return amount/coins[0];
            else return  1e9;
        }       
        
        if(dp[i][amount]!=-1) return dp[i][amount];

        int nottake = func(i-1,coins,amount,dp);

        int take = 1e9;

        if(coins[i]<=amount)
        {
            take = 1 + func(i,coins,amount-coins[i],dp);
        }
        dp[i][amount] = min(take,nottake);
        return min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res = func(n-1,coins,amount,dp);
        if(res==1e9) return -1;
        return res;
    }
};