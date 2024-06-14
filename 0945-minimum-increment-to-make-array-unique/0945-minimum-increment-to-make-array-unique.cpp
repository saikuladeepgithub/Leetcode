class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
                // set <int> mpp;
        // int n=nums.size();
        // int sam=0;
        // for(int i=0;i<n;i++)
        // {
        //     int key=nums[i];
        //     while(mpp.contains(key))
        //     {
        //         sam=sam+1;
        //         key=key+1;
        //     }
        //     mpp.insert(key);
        // }
        // return sam;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sam=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                nums[i]=nums[i]+1;
                sam=sam+1;
            }
            else if(nums[i]<nums[i-1])
            {
                sam=sam+nums[i-1]-nums[i]+1;
                nums[i]=nums[i]+(nums[i-1]-nums[i])+1;
            }
        }
        return sam;
    }
};