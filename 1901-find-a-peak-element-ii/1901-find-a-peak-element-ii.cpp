class Solution {
public:
    int findmaxi(vector<vector<int>> &mat,int mid)
    {
        int n=mat.size();
        int maxi=mat[0][mid];
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][mid]>=maxi)
            {
                maxi=mat[i][mid];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int ind=findmaxi(mat,mid);
            int left=mid-1>=0?mat[ind][mid-1]:-1;
            int right=mid+1<m?mat[ind][mid+1]:-1;
            int el=mat[ind][mid];
            if(el>=left && el>=right)
            {
                return {ind,mid};
            }
            else if(el<left)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};