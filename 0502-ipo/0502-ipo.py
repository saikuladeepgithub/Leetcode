class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # d={}
        # for i in range(len(profits)):
        #     d[capital[i]]=profits[i]
        # capital=w
        # count=0
        # for i in d:
        #     if(w>=i and count<k):
        #         count=count+1
        #         capital=capital+d[i]
        #         w=w+capital
        # return capital
        
        projects=[(c,p) for c,p in zip(capital,profits)]
        i=0
        projects.sort()
        l=[]
        for j in range(k):
            while(i<len(projects) and projects[i][0]<=w):
                heapq.heappush(l,-projects[i][1])
                i=i+1
            if(len(l)==0):
                break
            w=w+(-heapq.heappop(l))
        return w