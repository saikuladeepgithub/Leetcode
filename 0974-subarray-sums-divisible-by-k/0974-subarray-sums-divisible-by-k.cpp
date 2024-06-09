class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int count=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     int sum=0;
        //     for(int j=i;j<n;j++)
        //     {
        //         sum=sum+nums[j];
        //         if(sum%k==0)
        //         {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        // optimal solution
        
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int current=0;
        for(int i=0;i<n;i++)
        {
            current=current+nums[i];
            int rem=current%k;
            if(rem<0) rem=rem+k;
            count=count+mpp[rem];
            mpp[rem]++;
        }
        return count;
        
    }
};