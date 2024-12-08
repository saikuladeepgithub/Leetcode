class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        int prev = 0;
        int res = 0;
        sort(events.begin(),events.end());
        for(auto event : events)
        {
            while(!pq.empty() && pq.top().first<event[0])
            {
                prev = max(prev,pq.top().second);
                pq.pop();
            }
            res = max(res,event[2]+prev);
            pq.push({event[1],event[2]});
        }

        return res;
        
    }
};