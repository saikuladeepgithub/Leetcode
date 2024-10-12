class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start,ends;
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(ends.begin(),ends.end());
        for(auto it : start) cout << it << " ";
        cout << endl;
        for(auto it : ends) cout << it << " ";
        cout << endl;
        int count = 0;
        int i = 0;
        int j = 0;
        int ans = 1;
        while(i<n && j<n)
        {
            if(start[i]<=ends[j])
            {
                count=count+1;
                i++;
            }
            else
            {
                j++;
                count = count - 1;
            }
            ans = max(ans,count);
            
        }

        return ans;
    }
};