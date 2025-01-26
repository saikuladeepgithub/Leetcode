class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid, vector<vector<int>> &vis)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            vis[r][c] = 1;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]=='1')
                {
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};