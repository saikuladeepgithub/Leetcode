class Solution {
public:
    int func(int ind,int buy,vector<int> & prices,vector<vector<int>> &dp)
    {
        if(ind==prices.size()) return 0;
        int profit = 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            profit = max(func(ind+1,0,prices,dp)-prices[ind],
                            0 + func(ind+1,1,prices,dp));
        }
        else 
        {
            profit = max(prices[ind]+func(ind+1,1,prices,dp),
                        0+func(ind+1,0,prices,dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,1,prices,dp);
    }
};