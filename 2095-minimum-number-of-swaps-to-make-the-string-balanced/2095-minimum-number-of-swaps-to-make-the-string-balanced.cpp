class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int buddy = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                buddy += 1;
            }
            else if(buddy>0)
            {
                buddy -= 1;
            }
        }

        return (buddy+1)/2;
    }
};