class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxlen = 0;

        int l=0,r=0;
        map<int,int> mpp;
        int maxf = 0;
        while(r<s.size())
        {
            mpp[s[r]]++;
            maxf = max(maxf,mpp[s[r]]);

            while((r-l+1)-maxf>k)
            {
                mpp[s[l]]--;
                l++;
            }

            maxlen = max(maxlen , r-l+1);
            r++;
        }

        return maxlen;
    }
};