from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        freq = {}
        for i in range(len(nums)):
            if nums[i] in freq:
                freq[nums[i]] += 1
            else:
                freq[nums[i]] = 1
        
        nums.clear()
        for key, value in freq.items():
            if value >= 2:
                nums.extend([key, key])
            elif value == 1:
                nums.append(key)
        
        return len(nums)

