class Solution {
public:
    int func(vector<int>&nums,int k)
    {
        if(k<0) return 0;

        int l = 0, r = 0;
        int cnt = 0;
        int n = nums.size();
        int sum = 0;
        while(r<n)
        {
            sum += nums[r]%2;
            while(sum>k && l<=r)
            {
                sum -= nums[l]%2;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return func(nums,k) - func(nums,k-1);
    }
};