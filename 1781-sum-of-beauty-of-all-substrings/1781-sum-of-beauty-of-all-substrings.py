class Solution(object):
    def beautySum(self, s):
        """
        :type s: str
        :rtype: int
        """     
        # if(len(s)<3):
        #     return 0
        # def beauty(string):
        #     maxi=0
        #     mini=len(s)
        #     for i in string:
        #         c=string.count(i)
        #         if(c>maxi):
        #             maxi=c
        #         if(c<mini):
        #             mini=c
        #     return maxi-mini
        # sub=0
        # for i in range(len(s)):
        #     for j in range(i,len(s)):
        #         b=beauty(s[i:j+1])
        #         sub=sub+b
        # # res=0
        # # for i in sub:
        # #     res=res+beauty(i)
        # return sub
        ans=0
        for i in range(len(s)):
            freq=[0]*26
            for j in range(i,len(s)):
                freq[ord(s[j])-ord('a')]=freq[ord(s[j])-ord('a')]+1
                ans=ans+(max(freq)-min(x for x in freq if x))
        return ans
                         