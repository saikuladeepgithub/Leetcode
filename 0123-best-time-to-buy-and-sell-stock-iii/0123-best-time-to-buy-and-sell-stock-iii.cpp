class Solution {
public:

    int func(int ind,int buy,int cap,vector<int>&prices,int n)
    {
        if(ind==n || cap==0)
        {
            return 0;
        }

        int profit = 0;

        if(buy)
        {
            profit = max(-prices[ind]+func(ind+1,0,cap,prices,n),
                            0 + func(ind+1,1,cap,prices,n));
        }
        else
        {
            profit = max(prices[ind]+func(ind+1,1,cap-1,prices,n),
                           0+func(ind+1,0,cap,prices,n));
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // return func(0,1,2,prices,n);



        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        // base cases are already 0

        // base cases

        /* 
                the base cases are ind==n || cap==0
                ind==n means buy,cap can be anything dp[n][buy][cap] =0;

                cap==0 means ind,buy can be anything dp[ind][buy][0] = 0;

        */


        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                     int profit = 0;

                    if(buy)
                    {
                        profit = max(-prices[ind]+dp[ind+1][0][cap],
                                        0 + dp[ind+1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind]+dp[ind+1][1][cap-1],
                                    0+dp[ind+1][0][cap]);
                    }

                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];

    }
};