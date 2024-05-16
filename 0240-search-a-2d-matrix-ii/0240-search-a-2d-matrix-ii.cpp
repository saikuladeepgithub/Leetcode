class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=n-1;
        int col=0;
        while(col<m && row>=0)
        {
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                row=row-1;
            }
            else
            {
                col=col+1;
            }
        }
        return false;
    }
};