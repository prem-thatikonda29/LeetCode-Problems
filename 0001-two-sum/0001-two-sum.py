class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        m = {}

        for i in range(len(nums)):
            complement = target - nums[i]

            if complement in m:
                return [i, m[complement]]
            
            m[nums[i]] = i
    
        return [-1, -1]