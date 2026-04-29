class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict1 = {}
        for i in range(len(strs)):
            key = "".join(sorted(strs[i]))
            if key in dict1:
                dict1[key].append(strs[i])
            else:
                dict1[key] = [strs[i]]
        return list(dict1.values())