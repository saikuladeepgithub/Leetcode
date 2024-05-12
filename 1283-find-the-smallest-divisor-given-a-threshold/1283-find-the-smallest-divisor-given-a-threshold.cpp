class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=maxi)
            {
                maxi=nums[i];
            }
        }
        int low=1;
        int high=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum=sum+ceil((double)nums[i]/(double)mid);
            }
            if(sum<=threshold)
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