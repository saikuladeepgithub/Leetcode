class Solution {
public:
    int func(vector<int> & nums,int goal)
    {
        if(goal<0) return 0;

        int l = 0, r = 0;
        int cnt = 0;
        int sum = 0;
        int n = nums.size();
        while(r<n)
        {
            sum += nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        // int cnt = 0;
        // int prefixsum = 0;

        // map<int,int> mpp;
        
        // mpp[0] = 1;
        // int n = nums.size();

        // for(int i=0;i<n;i++)
        // {
        //     prefixsum += nums[i];

        //     int remove = prefixsum - goal;
        //     cnt += mpp[remove];

        //     mpp[prefixsum]++;
        // }

        // return cnt;

        return func(nums,goal) - func(nums,goal-1);
    }
};