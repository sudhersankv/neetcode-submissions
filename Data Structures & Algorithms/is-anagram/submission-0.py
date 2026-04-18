from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
            dict1 = defaultdict(int)
            dict2 = defaultdict(int)
            for i in s:
                dict1[i] += 1
            for j in t:
                dict2[j] += 1
            # print(dict1)
            # print(dict2)
            if dict1 == dict2:
                return True
            return False
                

