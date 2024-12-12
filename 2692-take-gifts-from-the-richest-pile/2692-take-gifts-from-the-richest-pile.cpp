class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> pq;

        int n = gifts.size();

        for(int i=0;i<n;i++)
        {
            pq.push(gifts[i]);
        }

        long long res = 0;

        while(k)
        {
            long long temp = pq.top();

            pq.pop();

            pq.push(sqrt(temp));
            k--;
        }

        while(!pq.empty())
        {
            res = res + pq.top();
            pq.pop();
        }

        return res;
    }
};