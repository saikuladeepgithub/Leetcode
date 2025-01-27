class Solution {
public:
    int helper(vector<int> & nums,int k,int val)
    {
        int cursum = 0;
        int maxsum = 0;
        for(auto &num : nums)
        {
            if(num == k)
                cursum--;
            else if(num == val)
                cursum++;
            if(cursum<0)
                cursum = 0;
            maxsum = max(maxsum,cursum);
        }

        return maxsum;
    }
    int maxFrequency(vector<int>& nums, int k) {
        
        int res = 0;
        unordered_map<int,int> mpp;
        for(auto &num : nums)
        {
            mpp[num]++;
        }

        for(auto it : mpp)
        {
            res = max(res,helper(nums,k,it.first));
        }

        return mpp[k] + res;
        
    }
};