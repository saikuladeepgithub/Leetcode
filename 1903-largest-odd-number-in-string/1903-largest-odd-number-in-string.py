class Solution(object):
    def largestOddNumber(self, num):
        """
        :type num: str
        :rtype: str
        """
        num=int(num)
        if(num%2==1):
            return str(num)
        else:
            temp=num
            while(temp!=0):
                temp=temp//10
                if(temp%2==1):
                    return str(temp)
        return ""
        