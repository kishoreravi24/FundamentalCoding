class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        helper_map = {}
        n = len(nums)
        for i in range(n):
            res = target-nums[i]
            if res in helper_map:
                return [helper_map[res],i]
            else:
                helper_map[nums[i]]=i
        return []

