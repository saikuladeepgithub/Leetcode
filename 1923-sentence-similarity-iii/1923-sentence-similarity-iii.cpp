class Solution {
public:
    vector<string> func(string sentence)
    {
        vector<string>words;
        string word = "";
        for(char c : sentence)
        {
            if(c==' ')
            {
                if(!word.empty())
                {
                    words.push_back(word);
                    word="";
                }
                
            }
            else
            {
                word+=c;
            }

        }
        if(!word.empty()) words.push_back(word);
        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()<sentence2.size())
        {
            return areSentencesSimilar(sentence2,sentence1);
        }
        vector<string> l1 = func(sentence1);
        vector<string> l2 = func(sentence2);

        int start2 = 0;
        int end2 = l2.size()-1;
        int end1 = l1.size()-1;
        // prefix

        while(start2<=end2 && l1[start2]==l2[start2])
        {
            start2=start2+1;
        }

        // suffix
        while(start2<=end2 && l1[end1]==l2[end2])
        {
            end1--;
            end2--;
        }

        return start2>end2;
    }
};