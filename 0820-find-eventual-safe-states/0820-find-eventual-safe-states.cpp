class Solution {
public:
    bool dfs(int node, vector<vector<int>> & graph , map<int,int> & mpp)
    {
        if(mpp[node]!=0)
            return mpp[node]==1;
        mpp[node] = -1;
        for(auto adjnode : graph[node])
        {
            if(!dfs(adjnode,graph,mpp))
                return false;
        }

        mpp[node] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        map<int,int> mpp;
        int n = graph.size();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(dfs(i,graph,mpp))
                res.push_back(i);
        }
        return res;
    }
};