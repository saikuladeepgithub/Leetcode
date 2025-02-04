class Solution {
public:
    // recursive approach 
    // int func(vector<int>&nums,int jumps,int i)
    // {
    //     if(i>=nums.size()-1) 
    //     {
    //         return jumps;
    //     }
    //     int mini=INT_MAX;
    //     for(int j=1;j<=nums[i];j++)
    //     {
    //         mini=min(mini,func(nums,jumps+1,i+j)); // possible steps we can move from 1step to nums[i] steps
    //     }
    //     return mini;
    // }
    int jump(vector<int>& nums) {
        // return func(nums,0,0);      
        
        // iterative approach
         
        int n=nums.size();
        int l=0;
        int r=0;
        int jumps=0;
        while(r<n-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]);
            }
             l=r+1;
            r=farthest;
            jumps=jumps+1;
        }
        return jumps;
       
    }
   
};