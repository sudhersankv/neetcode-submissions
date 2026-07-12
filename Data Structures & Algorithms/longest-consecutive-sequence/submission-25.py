class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numbers = set(nums)
        count = 1
        counts = [1]
        
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return 1

        for i in numbers:
            count = 1
            if i-1 not in numbers:
                while i+1 in numbers:
                    count+=1
                    i = i+1
                    counts.append(count)
            
                
        return max(counts)