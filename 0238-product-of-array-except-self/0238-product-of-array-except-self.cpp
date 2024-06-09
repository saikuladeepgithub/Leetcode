class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int leftp[n];
        int rightp[n];
        int left=1;
        int right=1;
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            leftp[i]=left;
            left=left*nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            rightp[i]=right;
            right=right*nums[i];
        }
        for(int i=0;i<n;i++)
        {
            res[i]=leftp[i]*rightp[i];
        }
        return res;
    }
};