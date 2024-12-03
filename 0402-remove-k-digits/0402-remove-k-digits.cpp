class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        stack<char> st;
        int n = num.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
           while(!st.empty() && st.top()-'0'>num[i]-'0' && k>0)
           {
            st.pop();
            k--;
           }
           st.push(num[i]);
        }
        while(k>0) st.pop(),k--;
        string res = "";
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        while(!res.empty() && res.back()=='0') res.pop_back();
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};