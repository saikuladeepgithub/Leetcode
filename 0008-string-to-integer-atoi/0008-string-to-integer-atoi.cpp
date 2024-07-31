class Solution {
public:
    int myAtoi(string s) {
        int p=0;
        bool minus=false;
        int maxi=INT_MAX;
        int mini=INT_MIN;
        int n=s.size();
        while(p<n && s[p]==' ')
        {
            p+=1;
        }
        if(p<n && s[p]=='+' || s[p]=='-')
        {
            minus=(s[p]=='-');
            p+=1;
        }
        int res=0;
        while(p<n && isdigit(s[p]))
        {
            int digit=s[p]-'0';
            if(res>((maxi-digit)/10))
            {
                if(minus) return mini;
                return maxi;
            }
             res=res*10+digit;
            p+=1;
        }
        if(minus) res=res*-1;
        if(res<=mini) return mini;
        return res;
    }
};