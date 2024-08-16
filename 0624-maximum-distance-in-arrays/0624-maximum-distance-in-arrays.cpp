class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int,int> mpp;
        int n=arrays.size();
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int res=INT_MIN;
        for(int i=1;i<n;i++)
        {
            int lmini=arrays[i][0];
            int lmaxi=arrays[i].back();
            res=max(res,max(lmaxi-mini,maxi-lmini));
            mini=min(mini,lmini);
            maxi=max(maxi,lmaxi);
        }
        return abs(res);
    }
};