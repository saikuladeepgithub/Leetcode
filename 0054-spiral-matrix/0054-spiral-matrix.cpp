class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=m-1;
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top=top+1;
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right=right-1;
            if(top<=bottom)
            {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
                bottom=bottom-1;
            }
            if(left<=right)
            {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left=left+1;
            }
        }
        return ans;
    }
};