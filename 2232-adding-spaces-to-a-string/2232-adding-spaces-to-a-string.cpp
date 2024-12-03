class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
     
        

        // int spsize = spaces.size();
        // int n = s.size();
        // string res(n+spsize,' ');
        // int l = 0;
        // for(int i=0;i<spsize;i++)
        // {
        //     int pos = spaces[i];
        //     while(l!=pos)
        //         res[l+i] = s[l++];
        // }
        // while(l<n)
        //     res[l+spsize] = s[l++];
        // return res;

        int n = s.size();

        int m = spaces.size();
        int j = 0;
        string res(n+m,' ');
        for(int i=0;i<n;i++)
        {
            if(j<m && spaces[j]==i)
            {
                res[i+j] = ' ';
                j+=1;
            }
            res [i+j] = s[i];
        }
        return res;

    }
};