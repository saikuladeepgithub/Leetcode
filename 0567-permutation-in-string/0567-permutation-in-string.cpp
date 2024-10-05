class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);
        vector<int>count2(26,0);
        int l1 = s1.length();
        int l2 = s2.length();

        if(l1>l2) return false;
        for(int i=0;i<s1.length();i++)
        {
            count1[s1[i]-'a']+=1;
            count2[s2[i]-'a']+=1;
        }

        for(int i=0;i<l2-l1;i++)
        {
            if(count1==count2) return true;

            count2[s2[i]-'a'] -= 1;
            count2[s2[i+l1]-'a'] +=1;
        }

        return count1==count2;
    }
};