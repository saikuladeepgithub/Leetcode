class Solution {
public:
    int minimumLength(string s) {
        unordered_map <char,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]+=1;
        }
        int l=0;
        for(auto it=mpp.begin();it!=mpp.end();it++)
        {
            int count=it->second;
            if(count>2 && count%2==0) l+=2;
            else if(count>2 && count%2==1) l+=1;
            else l+=count;
        }
        return l;
    }
};