class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_pdt = []
        suffix_pdt = []
        solution = []
        pdt = 1
        for i in range(len(nums)):
            if i !=0:
                pdt = pdt* nums[i-1]
            prefix_pdt.append(pdt)

        reverse = nums[::-1]

        pdt = 1
        for i in range(len(reverse)):
            if i !=0:
                pdt = pdt*reverse[i-1]
            suffix_pdt.append(pdt)
        suffix_pdt = suffix_pdt[::-1]

        for i in range(len(prefix_pdt)):
            pdt = prefix_pdt[i]*suffix_pdt[i]
            solution.append(pdt)

        return solution
