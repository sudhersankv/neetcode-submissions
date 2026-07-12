class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0

        for i in range(len(s)):
            count = 0
            myset = set()

            while i != len(s) and s[i] not in myset:
                count+=1
                myset.add(s[i])
                i+=1

            longest = max(longest,count)

                

        return longest

