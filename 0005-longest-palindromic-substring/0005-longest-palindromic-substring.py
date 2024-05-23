class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # def pal(s):
        #     if(s==s[::-1]):
        #         return True
        #     return False
        # res=''
        # for i in range(len(s)):
        #     for j in range(i,len(s)):
        #         sub=s[i:j+1]
        #         if(pal(sub)):
        #             if(len(sub)>len(res)):
        #                 res=sub
        # return res
        if(len(s)==0):
            return ''
        def expand(s,left,right):
            while(left>=0 and right<len(s) and s[left]==s[right]):
                left=left-1
                right=right+1
            return s[left+1:right]
        longest=''
        for i in range(len(s)):
            odd=expand(s,i,i)
            if(len(odd)>len(longest)):
                longest=odd
            even=expand(s,i,i+1)
            if(len(even)>len(longest)):
                longest=even
        return longest
            