class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int zeros = 0;
        while(r<n)
        {
            if(nums[r]==0) zeros++;
            if(zeros<=k)
            {
                maxlen = max(r-l+1,maxlen);
                r++;
            }
            else
            {
                while(zeros>k)
                {
                    if(nums[l]==0) zeros--;
                    l++;
                }
                r++;
            }
        }

        return maxlen;
    }
};