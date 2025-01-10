class Solution {
public:
    vector<int> getcount(string str)
    {
        vector<int> freq(26,0);

        for(int i=0;i<str.size();i++)
        {
            freq[str[i]-'a']++;
        }

        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> freq(26,0);
        for(int i=0;i<words2.size();i++)
        {
            vector<int> curfreq = getcount(words2[i]);
            for(int i=0;i<26;i++)
            {
                freq[i] = max(freq[i],curfreq[i]);
            }
        }
        vector<string> res;
        for(int i=0;i<words1.size();i++)
        {
            vector<int> cur = getcount(words1[i]);

            int flag = 1;
            for(int i=0;i<26;i++)
            {
                if(freq[i]> cur[i])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag)
                res.push_back(words1[i]);
        }

        return res;
    }
};