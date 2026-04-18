from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        dict1 = defaultdict(int)

        for i in s:
            dict1[i]+=1
        for i in t:
            dict1[i]-=1

        if all(v == 0 for v in dict1.values()):
            return True
        return False

            