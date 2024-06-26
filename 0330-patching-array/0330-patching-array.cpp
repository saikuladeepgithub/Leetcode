class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss=1;
        int patches=0;
        int i=0;
        while(miss<=n)
        {
            if(i<nums.size() && nums[i]<=miss)
            {
                miss=miss+nums[i];
                i=i+1;
            }
            else
            {
                miss=miss+miss;
                patches=patches+1;
            }
        }
        return patches;
        
    }
};