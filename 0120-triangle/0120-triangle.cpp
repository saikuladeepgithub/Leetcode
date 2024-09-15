class Solution {
public:
    int func(int i,int j, vector<vector<int>> & triangle,vector<vector<int>> & dp)
    {
        int n=triangle.size();
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int one=triangle[i][j]+func(i+1,j,triangle,dp);
        int two=triangle[i][j]+func(i+1,j+1,triangle,dp);
        dp[i][j]=min(one,two);
        return min(one,two);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,0,triangle,dp);
    }
};