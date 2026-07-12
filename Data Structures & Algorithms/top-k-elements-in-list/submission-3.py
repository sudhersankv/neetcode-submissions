class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        output = []
        bucket = []
        for i in range(len(nums)):
            if nums[i] in freq:
                freq[nums[i]] +=1
            else:
                freq[nums[i]] = 1
        for _ in (range(len(nums)+1)):
            bucket.append([])

        for num, count in freq.items():
            bucket[count].append(num)

        for i in range(len(bucket)-1, -1, -1):
            for num in bucket[i]:
                output.append(num)


                if len(output) == k:
                    return output
        