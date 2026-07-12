class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = sorted(nums)
        counts = []
        count = 1
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return 1
        for i in range(len(nums)):
            if i+1 == len(nums) or nums[i] == nums[i+1]:
                continue
            if nums[i+1]-nums[i] == 1:
                count += 1
            else:
                counts.append(count)
                count = 1
        counts.append(count)
        return max(counts)