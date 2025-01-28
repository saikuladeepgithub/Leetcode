class Solution {
public:
    int dfs(int row, int col,vector<vector<int>> & grid, vector<vector<int>> & vis)
    {
        vis[row][col] = 1;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        int m = grid.size();
        int n = grid[0].size();
        int res = grid[row][col];
        for(int i=0;i<4;i++)
        {
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0  && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc])
            {
                res += dfs(nr,nc,grid,vis);
            }
        }

        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int maxi = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] && !vis[i][j])
                    maxi = max(maxi,dfs(i,j,grid,vis));
            }
        }
        return maxi;
    }
};