class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0) return 201;
        int up=grid[i][j]+func(i-1,j,grid);
        int left=grid[i][j]+func(i,j-1,grid);

        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //return func(m-1,n-1,grid);

        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else
                {
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up=INT_MAX;
                    if(j>0) left+=dp[i][j-1];
                    else left=INT_MAX;

                    dp[i][j] = min(left,up);
                }
            }
        }

        return dp[m-1][n-1];
    }
};