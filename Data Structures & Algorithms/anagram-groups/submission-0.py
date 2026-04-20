class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorteddict = {}
        for i in range(len(strs)):
           key = "".join(sorted(strs[i]))
           if key in sorteddict:
            sorteddict[key].append(strs[i])
           else:
            sorteddict[key] = [strs[i]]
        return list(sorteddict.values())
   
