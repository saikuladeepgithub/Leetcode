class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue <pair<int,char>, vector<pair<int,char>>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string res = "";
        while(!pq.empty())
        {
            int n = res.size();
            auto cur = pq.top();
            pq.pop();
            if(n>=2 && res[n-1]==cur.second && res[n-2]==cur.second)
            {
                if(pq.empty()) break;
                auto next = pq.top();
                pq.pop();
                res.push_back(next.second);
                next.first--;
                if(next.first>0) pq.push(next);
                pq.push(cur);
            }
            else
            {
                res.push_back(cur.second);
                cur.first--;
                if(cur.first>0) pq.push(cur);
            }
        }

        return res;
    }
};