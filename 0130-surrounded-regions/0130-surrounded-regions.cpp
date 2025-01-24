class Solution {
public:

    void dfs(int i, int j, vector<vector<char>> & board,vector<vector<int>> & vis)
    {
        vis[i][j] = 1;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        int m = board.size();
        int n = board[0].size();
        for(int k=0;k<4;k++)
        {
            int nr = i + delrow[k];
            int nc = j + delcol[k];

            if(nr>=0  && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O')
            {
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(board[0][i] == 'O' && !vis[0][i])
                dfs(0,i,board,vis);
        }

        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && !vis[i][0]) 
                dfs(i,0,board,vis);
        }

        for(int i=0;i<n;i++)
        {
            if(board[m-1][i]=='O' && !vis[m-1][i])
                dfs(m-1,i,board,vis);
        }

        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O' && !vis[i][n-1])
                dfs(i,n-1,board,vis);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }

    }
};