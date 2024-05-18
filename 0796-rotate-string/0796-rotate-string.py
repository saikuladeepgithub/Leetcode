class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        if(len(goal)!=len(s)):
            return False
        s=s+s
        if(goal in s):
            return True
        return False