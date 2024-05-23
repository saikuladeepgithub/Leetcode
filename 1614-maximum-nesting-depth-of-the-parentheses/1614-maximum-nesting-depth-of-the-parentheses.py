class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        res=0
        count=0
        for i in s:
            if(i=='('):
                count=count+1
            elif(i==')'):
                count=count-1
            if(count>res):
                res=count
        return res
        