class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        vector<vector<int>> res;
        
        int i=0;
        int n=intervals.size();
        
        // adding left portion of result arraay that is not overlapping the new interval
        
        while(i<n && intervals[i][1]<newinterval[0])
        {
            res.push_back(intervals[i]);
            i=i+1;
        }
        while(i<n && intervals[i][0]<=newinterval[1])
        {
            newinterval[0]=min(newinterval[0],intervals[i][0]);
            newinterval[1]=max(newinterval[1],intervals[i][1]);
            i=i+1;
        }
        res.push_back(newinterval);
        
        // adding right portion of new interval which is non overlapping as it is in the question
        while(i<n)
        {
            res.push_back(intervals[i]);
            i=i+1;
        }
        
        return res;
    }
};