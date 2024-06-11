class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        sam=[]
        arr1=sorted(arr1)
        for i in arr2:
            for j in arr1:
                if(i==j):
                    sam.append(j)
        for i in arr1:
            if(i not in sam):
                for j in range(arr1.count(i)):
                    sam.append(i)
        return sam