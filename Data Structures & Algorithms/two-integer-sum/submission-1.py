class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict1 = {}
        for i in range (len(nums)):
            n = nums[i]
            complement = target - n
            if complement in dict1:
                return [dict1[complement], i]
            dict1[n] = i