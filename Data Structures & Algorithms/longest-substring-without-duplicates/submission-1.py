class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        x = 0
        longest = 0
        myset = set()

        for i in range(len(s)):
            while s[i] in myset:
                myset.remove(s[x])
                x+=1
            myset.add(s[i])
            longest = max(longest, i-x+1)
        return longest

