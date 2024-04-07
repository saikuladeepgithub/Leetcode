class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        // vector<vector<int>> res(m, vector<int>(m, 0));
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         res[j][m-i-1]=matrix[i][j];
        //     }
        // }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         matrix[i][j]=res[i][j];
        //     }
        // }
        for(int i=0;i<m-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};