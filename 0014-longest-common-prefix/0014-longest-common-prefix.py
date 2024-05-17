class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort()
        n=len(strs[0])
        count=0
        for i in range(n):
            left=strs[0][i]
            right=strs[len(strs)-1][i]
            if(left==right):
                count=count+1
            else:
                break
        if(count==0):
            return ""
        return strs[0][:count]