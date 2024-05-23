class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        d={'I':1,'V':5,'X':10,'L':50,"C":100,'D':500,'M':1000}
        sum=0
        flag=1
        i=0
        n=len(s)
        while(i<n-1):
            if(d[s[i]]<d[s[i+1]]):
                sum=sum+(d[s[i+1]]-d[s[i]])
                if(i==len(s)-2):
                    flag=0
                i=i+2
            else:
                sum=sum+d[s[i]]
                i=i+1
        if(flag==1):
            sum=sum+d[s[len(s)-1]]
        return sum
            