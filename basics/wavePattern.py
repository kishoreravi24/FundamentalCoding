class Solution:
    def wavePattern(self,n:int,a:List[int]):
        for i in range(0,n-1,2):
            a[i],a[i+1]=a[i+1],a[i]
        return a

