class Solution {
public:
    vector<vector<int>> result;
    void func(int i,int req,vector<int>&candidates,vector<int> ds)
    {
        if(i>=candidates.size()) return;
        if(req<0) return;
        if(req==0) 
        {
            result.push_back(ds);
            return;
        }
        ds.push_back(candidates[i]);
        func(i,req-candidates[i],candidates,ds);
        ds.pop_back();
        func(i+1,req,candidates,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        func(0,target,candidates,ds);
        return result;
    }
};