class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int cnt = 0;
        int prefixsum = 0;

        map<int,int> mpp;
        
        mpp[0] = 1;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            prefixsum += nums[i];

            int remove = prefixsum - goal;
            cnt += mpp[remove];

            mpp[prefixsum]++;
        }

        return cnt;
    }
};