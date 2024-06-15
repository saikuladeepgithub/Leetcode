class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans=''
        for i in range(len(s)):
            for j in range(i,len(s)):
                if(s[i:j+1]==s[i:j+1][::-1]):
                    if(len(s[i:j+1])>len(ans)):
                        ans=s[i:j+1]
        return ans