class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        solution = []
        pdt = 1
        for i in range(len(nums)):
            if i != 0:
                pdt = pdt*nums[i-1]
            solution.append(pdt)
        reverse = nums[::-1]
        solution = solution[::-1]
        pdt = 1
        for i in range(len(nums)):
            if i != 0:
                pdt = pdt*reverse[i-1]
            solution[i] *= pdt
        return solution[::-1]
