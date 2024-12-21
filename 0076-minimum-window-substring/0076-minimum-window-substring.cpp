class Solution {
public:
    string minWindow(string s, string t) {
        
        int l = 0;
        int r = 0;
        int n = s.size();
        int m = t.size();
        map<char,int> mpp;
        for(int i=0;i<m;i++)
        {
            mpp[t[i]]++;
        }
        int cnt = 0;
        int minlen = 100000000000;
        int ind = -1;
        while(r<n)
        {
            if(mpp[s[r]]>0) cnt+=1;
            mpp[s[r]]--;
            while(cnt==m)
            {
                if(r-l+1<minlen)
                {
                    minlen = r-l+1;
                    ind = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt = cnt - 1;
                l++;
            }
            r++;
        }

        return ind==-1 ? "" : s.substr(ind,minlen);

    }
};