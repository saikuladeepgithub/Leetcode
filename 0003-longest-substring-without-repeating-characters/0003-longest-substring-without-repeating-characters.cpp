class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int res = 1;
        int mini = 0;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.count(s[i])==0)
            {
                st.insert(s[i]);
                res = max(res,i-mini+1);
            }
            else
            {
                while(st.count(s[i]))
                {
                    st.erase(s[mini]);
                    mini = mini + 1;
                }
                st.insert(s[i]);
            }

        }
        return res;

        return res;
    }
};