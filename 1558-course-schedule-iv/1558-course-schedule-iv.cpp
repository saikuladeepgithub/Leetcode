class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        for(int i=0; i< prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        map<int,set<int>> mpp;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
        

            for(auto it : adj[node])
            {
                mpp[it].insert(node);
                for(auto pre : mpp[node])
                    mpp[it].insert(pre);
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        vector<bool> answer(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            if(mpp[queries[i][1]].count(queries[i][0])>0)
                answer[i] = true;
            else
                answer[i] = false;
        }
        return answer;
    }
};