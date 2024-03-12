class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        s=0
        for i in digits:
            s=s*10+i
        s=s+1
        s=str(s)
        res=[]
        for i in s:
            res.append(int(i))
        return res
        