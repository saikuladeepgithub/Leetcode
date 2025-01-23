class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();
        map<int,int> row;
        map<int,int> col;
        for(int i=0;i<m;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                cnt += grid[i][j];
                col[j] += grid[i][j];
            }

            row[i] = cnt;
        }
        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if(row[i]>1 || col[j]>1)
                        res++;
                }
            }
        }

        return res;
    }
};