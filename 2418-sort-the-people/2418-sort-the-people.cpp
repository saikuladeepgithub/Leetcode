class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        res=[(heights[i],names[i]) for i in range(len(names))]
        res.sort(reverse=True)
        names=[]
        for i in res:
            names.append(i[1])
        return names