class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                el=nums[i];
            }
            if(el==nums[i])
            {
                count=count+1;
            }
            else
            {
                count=count-1;
            }
        }
        return el;
        // int c=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==el)
        //     {
        //         c=c+1;
        //     }
        // }
        // if(c>nums.size()/2)
        // {
        //     return el;
        // }
        // return -1;
    }
};