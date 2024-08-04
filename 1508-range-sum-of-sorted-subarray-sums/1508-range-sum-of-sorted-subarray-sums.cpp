class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector <int> sum;
        for(int i=0;i<n;i++)
        {
            int s=nums[i];
            sum.push_back(s);
            for(int j=i+1;j<n;j++)
            {
                s+=nums[j];
                sum.push_back(s);
            }
        }
        sort(sum.begin(),sum.end());
        int res=0;
        int mod=1000000007;
        for(int i=left-1;i<right;i++)
        {
            res=(res+sum[i])%mod;
        }
        return res;
    }
};