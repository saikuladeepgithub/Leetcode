class Solution {
public:
    bool compare(string & s1,string & s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int i = 0;
        int j = 0;
        while(i<s1.size())
        {
            if(j<s2.size() && s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int> dp(n+1,1);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]) && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j] + 1;
                }
            }

            maxi = max(maxi,dp[i]);
        }

        return maxi;
    }
};