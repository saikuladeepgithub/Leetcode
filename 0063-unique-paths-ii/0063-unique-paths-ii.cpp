class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector <vector<int>> dp(m,vector<int>(n,0));
        
        vector<int> prev(n);
        for(int i = 0; i<m ; i++)
        {
            vector<int> cur(n);
            for(int j = 0 ; j<n ; j++)
            {
                if(i==0 && j==0 && obstacleGrid[i][j]!=1) cur[j]=1;
                else if(obstacleGrid[i][j]==1)  cur[j]=0;
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j] = up+left;
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};