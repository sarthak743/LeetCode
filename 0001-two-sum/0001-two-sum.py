class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in seen:
                return i, seen[comp]
            seen[nums[i]] = i
        
        return -1, -1