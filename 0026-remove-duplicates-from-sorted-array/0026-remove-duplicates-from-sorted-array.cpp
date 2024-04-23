class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int left=0;
        int right=1;
        while(right<n)
        {
            if(nums[left]==nums[right])
            {
                right=right+1;
            }
            else
            {
                left=left+1;
                nums[left]=nums[right];
                right=right+1;
            }
        }
        return left+1;
    }
};