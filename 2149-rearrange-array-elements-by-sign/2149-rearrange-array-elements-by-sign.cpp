class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos[n/2];
        int neg[n/2];
        int j=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                pos[j]=nums[i];
                j++;
            }
            else
            {
                neg[k]=nums[i];
                k=k+1;
            }
        }
        int l=0;
        for(int i=0;i<n/2;i++)
        {
            nums[l]=pos[i];
            l=l+1;
            nums[l]=neg[i];
            l=l+1;
        }
        return nums;
        
    }
};