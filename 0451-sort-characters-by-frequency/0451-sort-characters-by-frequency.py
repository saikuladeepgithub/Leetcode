class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        b=list(set(s))
        v=[]
        for i in b:
            v.append((s.count(i),i))
        v.sort(reverse=True)
        res=''
        for i in v:
            sam=i[1]*i[0]
            res=res+sam
            sam=''
        return res