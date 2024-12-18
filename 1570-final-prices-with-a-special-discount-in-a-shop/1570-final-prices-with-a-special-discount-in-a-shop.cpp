class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size());

        for(int i=0;i<prices.size();i++)
        {
            int flag = 1;
            for(int j = i+1;j<prices.size();j++)
            {
                if(prices[j]<=prices[i])
                {
                    res[i] = prices[i] - prices[j];
                    flag = 0;
                    break;
                }
            }
            if(flag) res[i] = prices[i];
        }

        return res;
    }
};