class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int sum = nums[0];
        int res = INT_MAX;
        int n = nums.size();
        while(i<n  && j<n)
        {
            if(sum < target)
            {
                j++;
                if(j<n) sum += nums[j];
            }
            else
            {
                res = min(res, j - i + 1);
                
                sum -= nums[i];
                i++;
            }
        
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};