class Solution:
    def nonRepeating(self,string):
        freq={}
        for item in string:
            if item in freq:
                freq[item]+=1
            else:
                freq[item]=1
        for key,value in freq.items():
            if value==1:
                return key
        return "-1"

obj = Solution()
res = obj.nonRepeating("abcdaf")
print(res)

