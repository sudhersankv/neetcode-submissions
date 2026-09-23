from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        map = defaultdict(int)

        for i in range(len(nums)):
            complement = target - nums[i]

            if complement in map:
                return [map[complement], i]

            map[nums[i]] = i

        return {}
        