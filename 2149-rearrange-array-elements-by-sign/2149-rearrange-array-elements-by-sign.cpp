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
        for(int i=0;i<n/2;i++)
        {
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        return nums;
        
    }
};