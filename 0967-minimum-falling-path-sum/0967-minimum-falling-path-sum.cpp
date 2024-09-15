class Solution {
public:
    int func(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int n = matrix.size();
        if(j<0 || j>=n) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ld=matrix[i][j] + func(i-1,j-1,matrix,dp);
        int s= matrix[i][j] + func(i-1,j,matrix,dp);
        int rg= matrix[i][j] + func(i-1,j+1,matrix,dp);
        dp[i][j] = min(ld,min(s,rg));
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int res=INT_MAX;
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++)
        // {
        //     res=min(res,func(n-1,i,matrix,dp));
        // }
        // return res;



        // Tabulation part

        int n = matrix.size();
        //vector<vector<int>> dp(n,vector<int>(n,0));

        vector<int> prev(n,0) ,cur(n,0); // space optimisation buddy
        for(int i=0 ; i<n ; i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(i==0) cur[j]=matrix[i][j];
                else
                {
                    int s=matrix[i][j]+prev[j];
                    int lg=matrix[i][j];
                    if(j-1>=0)lg=lg+prev[j-1];
                    else lg=INT_MAX;
                    int rg=matrix[i][j];
                    if(j+1<n) rg=rg+prev[j+1];
                    else rg=INT_MAX;
                    cur[j]=min(s,min(lg,rg));
                }
            }
            prev=cur;
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            res=min(res,prev[i]);
        }
        return res;
    }
};