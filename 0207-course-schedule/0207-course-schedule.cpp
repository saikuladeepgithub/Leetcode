class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> topo;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int ele = q.front();
            q.pop();
            topo.push_back(ele);

            for(auto it : adj[ele])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }


        return topo.size() == numCourses;

    }
};