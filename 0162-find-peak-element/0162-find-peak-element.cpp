class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int p=1;
        int n=nums.size();
        if(n==1) return 0;
        while(p<n-1)
        {
            if(nums[p]>nums[p-1] && nums[p]>nums[p+1])
            {
                return p;
            }
            p=p+1;
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        return -1;
    }
};