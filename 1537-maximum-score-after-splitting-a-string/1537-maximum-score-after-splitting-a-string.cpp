class Solution {
public:
    int maxScore(string s) {
        
        map<int,int> left;
        map<int,int> right;
        if(s=="01") return 2;
        int n = s.size();
        int count0 = 0;
        int count1 = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1') count1++;
            right[i] = count1;
        }

        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') count0++;
            left[i] = count0;
        }
        int res = 0;
        for(int i=1;i<n-1;i++)
        {
            cout << left[i] << right[i] << " " ;
            res = max(res,left[i]+right[i]);
            cout << res << " ";
        }
        if(count1==n || count0==n ) return n-1;
        return res;
    }
};