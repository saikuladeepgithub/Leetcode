class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n,-1);
        for(int i=0;i<n;i++)
        {
            int j = (i+1)%n;
            while(j!=i)
            {
                if(nums[j]>nums[i])
                {
                    res[i] = nums[j];
                    break;
                }
                j = (j+1)%n;
            }
        }

        return res;
    }
};