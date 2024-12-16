class Solution {
public:
    int getmin(vector<int> & nums)
    {
        int mini = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<nums[mini])
                mini = i;
        }

        return mini;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k)
        {
            int index = getmin(nums);

            nums[index] *= multiplier;

            k--;
        }

        return nums;
    }
};