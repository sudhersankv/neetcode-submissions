from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        freq1 = defaultdict(int)
        freq2 = defaultdict(int)

        for x in s:
            freq1[x] += 1
        for x in t:
            freq2[x] += 1

        if(freq1 == freq2):
            return True

        return False

        