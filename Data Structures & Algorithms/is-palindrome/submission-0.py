class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleanedstring = "".join(filter(str.isalnum, s)).lower()
        l, r = 0, len(cleanedstring)-1
        while l < r:
            if cleanedstring[l] != cleanedstring[r]:
                return False
            l+=1
            r-=1
        return True
