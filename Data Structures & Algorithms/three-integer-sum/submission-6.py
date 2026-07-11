class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sollist = []
        nums = sorted(nums)
        i, l, r = 0, 1, len(nums) - 1
        for i in range(len(nums)):
            if i!=0 and nums[i] == nums[i-1]:
                continue
            l=i+1
            r= len(nums) - 1

            while l<r:
                sumof= nums[i]+ nums[l] + nums[r]

                if sumof == 0:
                    sollist.append([nums[i],nums[l],nums[r]])
                    l+=1
                    r-=1

                    while l < r and nums[l] == nums[l-1]:
                        l+=1

                    while l < r and nums[r] == nums[r+1]:
                        r-=1

                elif sumof < 0:
                    l+=1

                elif sumof > 0:
                    r-=1
        return sollist
