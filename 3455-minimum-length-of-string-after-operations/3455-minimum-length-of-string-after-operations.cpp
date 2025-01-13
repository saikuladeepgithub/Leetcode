class Solution {
public:
    int minimumLength(string s) {
        
        // int cnt = s.size();
        // int n = s.size();
        // vector<int> vis(n,0);

        // for(int i=0;i<n;i++)
        // {
        //     if(vis[i])
        //         continue;
        //     int left = -1;
        //     int right = -1;
        //     for(int j=0;j<i;j++)
        //     {
        //         if(s[j] == s[i])
        //             left = j;
        //     }
        //     if(left==-1)
        //          continue;
        //     for(int j = i+1;j<n;j++)
        //     {
        //         if(s[j] == s[i])
        //         {
        //             right = j;
        //             break;
        //         }
        //     }
        //     if(right == -1)
        //         continue;
        //     vis[left] = vis[right] = 1;
        //     cnt-=2;

        // }

        // return cnt;



        int minlength = 0;

        // if the char count is even, then 2 chars will reamain after performing operations
        // if the char count is odd, then 1 char will remain after performing operations

        map<char,int> mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]+=1;

        }

        for(auto & it : mpp)
        {
            int cnt = it.second;
            if(cnt>2 && cnt%2)
                minlength+=1;
            else if(cnt>2 && !(cnt%2))
                minlength+=2;
            else
                minlength+=cnt;
        }

        return minlength;

    }
};