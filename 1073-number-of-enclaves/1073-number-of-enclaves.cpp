class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> & grid, vector<vector<int>> & vis)
    {
        vis[i][j] = 1;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        int m = grid.size();
        int n = grid[0].size();
        for(int k = 0; k<4; k++)
        {
            int nr = i + delrow[k];
            int nc = j + delcol[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1)
            {
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(!vis[0][i] && grid[0][i]==1)
            {
                dfs(0,i,grid,vis);
            }
            if(!vis[m-1][i] && grid[m-1][i]==1)
                dfs(m-1,i,grid,vis);
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,grid,vis);
            if(!vis[i][n-1] && grid[i][n-1]==1)
                dfs(i,n-1,grid,vis);
        }

        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                    cnt++;
            }
        }

        return cnt;
        
    }
};