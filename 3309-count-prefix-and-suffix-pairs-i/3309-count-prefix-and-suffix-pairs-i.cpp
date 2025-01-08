class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        return str2.starts_with(str1) && str2.ends_with(str1);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        

        int cnt = 0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isPrefixAndSuffix(words[i],words[j])) cnt++;
            }
        }

        return cnt;
    }
};