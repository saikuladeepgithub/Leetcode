class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int p=1;
        // int n=nums.size();
        // if(n==1) return 0;
        // while(p<n-1)
        // {
        //     if(nums[p]>nums[p-1] && nums[p]>nums[p+1])
        //     {
        //         return p;
        //     }
        //     p=p+1;
        // }
        // if(nums[0]>nums[1]) return 0;
        // if(nums[n-1]>nums[n-2]) return n-1;
        // return -1;
        // Binary search solution
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low=1;
        int high=n-2;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            {
                return mid;
            }
            else if(nums[mid]>nums[mid+1])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
};