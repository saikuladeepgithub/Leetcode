class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        

        long long topsum = 0;
        long long bottomsum = 0;

        for(int i=0;i<grid[0].size();i++)
        {
            topsum+=grid[0][i];
        }
        long long res = LLONG_MAX;
        for(int i=0;i<grid[0].size();i++)
        {
            topsum -= grid[0][i];
            res = min(res,max(topsum,bottomsum));
            bottomsum += grid[1][i];
        }

        return res;
    }
};