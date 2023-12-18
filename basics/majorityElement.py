class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq={}
        for i in range(len(nums)):
            if nums[i] in freq:
                freq[nums[i]]+=1
            else:
                freq[nums[i]]=1
        
        for key,value in freq.items():
            if value > len(nums)/2:
                return key
                
## optimize code
class Soltution:
    def majorityElement(self,nums):
        nums.sort()
        n = len(nums)
        return nums[n//2]

