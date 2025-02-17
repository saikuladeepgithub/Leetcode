class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int center = -1;
        int cnt = 0;
        while(l<r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
                continue;
            }

            int k;
            for(k=l+1;k<r;k++)
            {
                if(s[k] == s[r])
                {
                    break;
                }
            }

            if(k == r)
            {
                center = k;
                r--;
                continue;
            }

            for(int i=k;i>l;i--)
            {
                swap(s[i],s[i-1]);
                cnt++;
            }

            l++;
            r--;
        }

        if(center!=-1)
        {
            cnt += (center - s.size() / 2);
        }

        return cnt;
    }
};