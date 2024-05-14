class Solution {
public:
    int func(vector<int>&nums,int mid)
    {
        int n=nums.size();
        int count=0;
        int p=0;
        for(int i=0;i<n;i++)
        {
            count=count+nums[i];
            if(count==mid)
            {
                p=p+1;
                count=0;
            }
            else if(count>mid)
            {
                p=p+1;
                count=nums[i];
            }
        }
        if(count!=0) p=p+1;
        return p;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=nums[0];
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(nums[i]>=maxi) maxi=nums[i];
        }
        int low=maxi;
        int high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int p=func(nums,mid);
            if(p<=k)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};