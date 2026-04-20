from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = defaultdict(int)
        for i in s:
            dict1[i] +=1
        for i in t:
            dict1[i] -=1
            if dict1[i] < 0:
                return False
        return all(v==0 for v in dict1.values())
            