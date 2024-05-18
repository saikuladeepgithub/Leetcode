class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s)==sorted(t)
        sd={}
        td={}
        for i in s:
            sd[i]=sd[i]+1
        for i in t:
            td[i]=td[i]+1
        for i in s:
            if(sd[i]!=td[i]):
                return False
        return True