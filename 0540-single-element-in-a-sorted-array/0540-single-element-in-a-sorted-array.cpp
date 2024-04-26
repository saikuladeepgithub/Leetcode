class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int n=nums.size();
        int left=0;
        int right=1;
        int ans;
        while(right<n)
        {
            if(nums[left]==nums[right])
            {
                left=left+2;
                right=right+2;
            }
            else
            { 
                ans=nums[left];
                break;
            }
        }
        if(right>=n)
        {
            return nums[n-1]; 
        }
        return ans;
    }
};