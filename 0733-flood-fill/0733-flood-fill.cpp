class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        int m = image.size();
        int n = image[0].size();

        
        if(color == image[sr][sc])
            return image;
        int initialcolor = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==initialcolor)
                {
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};