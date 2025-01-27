class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it: adj[i])
                indegree[it]++;
        }

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }

        return topo.size() == numCourses;
    }
};