class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n = nums.size();

        int pos = 0;
        int zeros = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>0)
                pos++;
            else if(nums[i] == 0)
                zeros++;
            else 
                break;
        }

        return max(pos, n-pos-zeros);
    }
};