class Solution {
public:
    int minimumDeletions(string s) {
        int res=0;
        int count=0;
        int n=s.size();
        for(auto c : s)
        {
            if(c=='b') count+=1;
            else if(count!=0)
            {
                res+=1;
                count-=1;
            }
        }
        return res;
    }
};