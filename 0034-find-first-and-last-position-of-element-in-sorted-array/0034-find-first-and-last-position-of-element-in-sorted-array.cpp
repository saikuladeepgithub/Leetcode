class Solution {
public:
    int lb(vector<int>& nums, int target,int n)
    {
        int high=n-1;
        int low=0;
        int mid;
        int ans=n;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int ub(vector<int>& nums, int target,int n)
    {
        int low=0;
        int high=n-1;
        int mid;
        int ans=n;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lower_bound=lb(nums,target,n);
        if(lower_bound==n || nums[lower_bound]!=target) return{-1,-1};
        int upper_bound=ub(nums,target,n);
        return {lower_bound,upper_bound-1};
    }
};