class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int n = s.size();

        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size())
                {
                    st.pop();
                }
                else
                {
                    count+=1;
                }
            }
        }

        return count+st.size();
    }
};