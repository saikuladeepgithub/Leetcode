class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s=s.strip()
        if(len(s)==0):
            return 0
        res=0
        i=0
        neg=False
        if(s[i]=='-' or s[i]=='+'):
            neg=(s[i]=='-')
            i=i+1
        while(i<len(s) and s[i].isdigit()):
            res=res*10+int(s[i])
            i=i+1
        if(neg):
            res=res*-1
        maxi=2**31-1
        mini=-(2**31)
        if(res>=maxi):
            return maxi
        elif(res<=mini):
            return mini
        else:
            return res