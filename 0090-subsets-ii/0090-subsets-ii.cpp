class Solution {
public:
    // set <vector<int>> res;
    // void func(int i,vector<int> & nums,vector<int> &ds)
    // {
    //     if(i==nums.size())
    //     {
    //         res.insert(ds);
    //         return;
    //     }
    //     ds.push_back(nums[i]);
    //     func(i+1,nums,ds);
    //     ds.pop_back();
    //     func(i+1,nums,ds);
    // }
    
    vector<vector<int>> res;
    void func(int i, vector<int>&nums,vector<int> &ds)
    {
        res.push_back(ds);
        if(i<nums.size()){
            ds.push_back(nums[i]);
            func(i+1,nums,ds);
            ds.pop_back();
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==nums[j-1]) continue;
                ds.push_back(nums[j]);
                func(j+1,nums,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(),nums.end());
        func(0,nums,ds);
        // vector< vector<int>> result(res.begin(),res.end());
        return res;
    }
};