class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l = searchWord.size();
        int n = sentence.size();
        string str = "";
        int count = 1;
        for(int i=0;i<n;i++)
        {
            if(sentence[i]!=' ') str+=sentence[i];
            else
            {
                if(str.size()>=l && str.substr(0,l)==searchWord) return count;
                else count+=1;
                str = "";
            }
        }
        if(str.size()>=l && str.substr(0,l)==searchWord) return count;
        return -1;
    }
};