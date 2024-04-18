class Solution {
public:
    int bs(vector<int> &nums,int low,int high,int target)
    {
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) return bs(nums,mid+1,high,target);
        return bs(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        // int n=nums.size();
        // int low=0;
        // int high=n-1;
        // while(low<=high)
        // {
        //     int mid=(low+high)/2;
        //     if(nums[mid]==target) return mid;
        //     else if(target<nums[mid]) high=mid-1;
        //     else low=mid+1;
        // }
        // return -1;
        return bs(nums,0,nums.size()-1,target);
    }
};