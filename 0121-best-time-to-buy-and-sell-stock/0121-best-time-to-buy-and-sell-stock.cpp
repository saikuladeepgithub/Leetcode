#include <bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         int predif=0;
//         int diff=0;
//         int res=0;
//         for(int i=0;i<prices.size();i++)
//         {
//             diff=0;
//             for(int j=i;j<prices.size();j++)
//             {
//                 diff=prices[j]-prices[i];
//                 if(predif<diff)
//                 {
//                     predif=diff;
//                     res=prices[j];
                    
//                 }
//             }
//         }
//         return predif;
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int cost=prices[i]-mini;
            profit=max(cost,profit);
            mini=min(prices[i],mini);
        }
        return profit;
    }
};