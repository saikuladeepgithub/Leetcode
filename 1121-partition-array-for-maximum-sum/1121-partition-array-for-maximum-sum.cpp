#include <bits/stdc++.h>
class Solution {
public:
    int f(int ind,vector<int> & arr,int k,vector<int> & dp)
    {
        if(ind == arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j=ind;j<ind+k;j++)
        {
           if(j<arr.size())
           {
                len +=1;
                maxi = max(maxi,arr[j]);
                int sum = (len * maxi) + f(j+1,arr,k,dp);
                maxAns = max(maxAns,sum);
           }
        }

        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int> dp(n,-1);
        // return f(0,arr,k,dp);

        vector<int> dp(n+1,0);
        dp[n] = 0;

        for(int ind = n-1;ind>=0;ind--)
        {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            for(int j=ind;j<ind+k;j++)
            {
                if(j<arr.size())
                {
                        len +=1;
                        maxi = max(maxi,arr[j]);
                        int sum = (len * maxi) + dp[j+1];
                        maxAns = max(maxAns,sum);
                }
            }

            dp[ind] = maxAns;
        }

        return dp[0];
    }
};