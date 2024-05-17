class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s=s.strip()
        s=s.split()
        res=''
        for i in range(len(s)-1,-1,-1):
            res=res+s[i]+' '
        return res.strip()
        