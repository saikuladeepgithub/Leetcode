class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map <int,string> mpp;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            mpp[heights[i]]=names[i];
        }
        sort(heights.rbegin(),heights.rend());
        for(int i=0;i<n;i++)
        {
            names[i]=mpp[heights[i]];
        }
        return names;
    }
};