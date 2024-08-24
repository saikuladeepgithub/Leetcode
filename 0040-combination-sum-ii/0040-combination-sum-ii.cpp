class Solution {
public:
    vector<vector<int>> result;
    void func(int i,int req,vector<int> & candidates,vector<int>& ds)
    {
        if(req==0) 
        {
            for(int j=0;j<result.size();j++)
            {
                if(result[j]==ds) return;
            }
            result.push_back(ds);
            return;
        }
        if(i==candidates.size()) 
        {
            if(req==0) 
            {
                for(int j=0;j<result.size();j++)
                {
                    if(result[j]==ds) return;
                }
                result.push_back(ds);
                return;
            }
            return;
        }
        if(candidates[i]<=req)
        {
            ds.push_back(candidates[i]);
            func(i+1,req-candidates[i],candidates,ds);
            ds.pop_back();
            for(int j=i+1;j<candidates.size();j++)
            {
                if(candidates[j]>req) return;
                if(candidates[j]==candidates[j-1]) continue;
                ds.push_back(candidates[j]);
                func(j+1,req-candidates[j],candidates,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        func(0,target,candidates,ds);
        return result;
    }
};