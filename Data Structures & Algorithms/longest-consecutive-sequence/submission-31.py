class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numbers = set(nums)
        longest = 0
        
        for i in numbers:
            if i-1 not in numbers:
                count = 1
                while i+1 in numbers:
                    count+=1
                    i = i+1

                longest = max(count, longest)
            
                
        return longest