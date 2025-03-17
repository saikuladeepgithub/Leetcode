class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);
        
        // Convert 1-based indexing to 0-based indexing
        for (const auto& time : times) {
            int u = time[0] - 1;
            int v = time[1] - 1;
            int w = time[2];
            adj[u].emplace_back(v, w);
        }

        // Min-heap (priority queue) for Dijkstra’s algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        // Distance array, initialized with infinity
        vector<int> visitedTime(n, INT_MAX);
        visitedTime[k - 1] = 0;  // Convert `k` to 0-based indexing
        pq.emplace(0, k - 1);

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Relaxation step
            for (const auto& [adjNode, edgeTime] : adj[node]) {
                if (time + edgeTime < visitedTime[adjNode]) {
                    visitedTime[adjNode] = time + edgeTime;
                    pq.emplace(visitedTime[adjNode], adjNode);
                }
            }
        }

        // Find the maximum time taken to reach any node
        int maxTime = *max_element(visitedTime.begin(), visitedTime.end());
        return (maxTime == INT_MAX) ? -1 : maxTime;
    }
};
