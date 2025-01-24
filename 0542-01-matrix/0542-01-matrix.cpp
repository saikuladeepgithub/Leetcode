class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> res(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            res[r][c] = d;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])
                {
                    q.push({{nr,nc},d+1});
                    vis[nr][nc] = 1;
                }
            }
        }

        return res;


    }
};