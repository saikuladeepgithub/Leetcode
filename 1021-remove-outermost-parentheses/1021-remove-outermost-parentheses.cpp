class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
            if(count==1 && s[i]=='(') continue;
            if(count==0) continue;
            res=res+s[i];
            
        }
        return res;
    }
};