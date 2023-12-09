class Solution:
    def duplicates(self,arr,n):
        freq = {}
        result = []
        for item in arr:
            if item in freq:
                freq[num]+=1
            else:
                freq[num]=1
        for key,value in freq.items():
            if value > 1:
                result.append(key)
        if len(result)==0:
            result.append(-1)
        return sorted(result)

