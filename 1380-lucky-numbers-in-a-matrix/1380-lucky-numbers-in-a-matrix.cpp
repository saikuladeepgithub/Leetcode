class Solution {
public:
    int check(vector<vector<int>>& matrix,int m,int n,int mini,int row)
    {
        for(int i=0;i<m;i++)
        {
            if(matrix[i][mini]>matrix[row][mini])
            {
                return 0;
            }
        }
        return 1;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> buddy;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int mini=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<matrix[i][mini])
                {
                    mini=j;
                }
            }
            int b=check(matrix,m,n,mini,i);
            if(b)
            {
                buddy.push_back(matrix[i][mini]);
            }
        }
        return buddy;
    }
};