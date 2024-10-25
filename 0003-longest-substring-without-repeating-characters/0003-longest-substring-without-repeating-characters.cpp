class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.length();
        // int maxLength = 0;
        // unordered_set<char> charSet;
        // int left = 0;
        
        // for (int right = 0; right < n; right++) {
        //     if (charSet.count(s[right]) == 0) {
        //         charSet.insert(s[right]);
        //         maxLength = max(maxLength, right - left + 1);
        //     } else {
        //         while (charSet.count(s[right])) {
        //             charSet.erase(s[left]);
        //             left++;
        //         }
        //         charSet.insert(s[right]);
        //     }
        // }
        
        // return maxLength;

        int n = s.size();

        int maxi = 0;
        set<char> st;
        int left = 0;
        for(int i=0;i<n;i++)
        {
            if(st.count(s[i])==0)
            {
                st.insert(s[i]);
                maxi = max(maxi,i-left+1);
            }
            else
            {
                while(st.count(s[i]))
                {
                    st.erase(s[left]);
                    left = left + 1;
                }
                st.insert(s[i]);
            }       
        }

        return maxi;
    }
};