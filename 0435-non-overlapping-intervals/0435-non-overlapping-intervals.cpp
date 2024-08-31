class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int>b)
             {
                 return a[1]<b[1];
             });
        int prevend=intervals[0][1];
        int n=intervals.size();
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=prevend)
            {
                count+=1;
                prevend=intervals[i][1];
            }
        }
        return n-count;
    }
};