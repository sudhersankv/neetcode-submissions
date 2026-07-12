class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        output = []
        for i in range(len(nums)):
            if nums[i] in freq:
                freq[nums[i]] +=1
            else:
                freq[nums[i]] = 1
        for i in range(k):
            num = max(freq, key=freq.get)
            output.append(num)
            freq.pop(num)

        return output