class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        li=[i for i in range(1,n+1)]
        if(k==1):
            return n
        i=0
        while(len(li)!=1):
            i=(i+k-1)%len(li)
            li.pop(i)
        return li[0]