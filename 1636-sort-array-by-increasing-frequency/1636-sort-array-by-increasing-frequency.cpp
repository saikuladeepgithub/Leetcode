class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]+=1;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b)
             {
                 if(mpp[a]==mpp[b])
                 {
                     return a>b;
                 }
                 return mpp[a]<mpp[b];
             });
        return nums;
    }
};