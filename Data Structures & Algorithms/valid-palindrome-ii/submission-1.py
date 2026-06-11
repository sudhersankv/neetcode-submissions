class Solution:
    def validPalindrome(self, s: str) -> bool:
        def check_delete(l,r):
            while l<r:
                if s[l] != s[r]:
                    return False
                l+=1
                r-=1
            return True
        s = s.lower()
        l,r = 0, len(s) - 1
        while l<r:
            if s[l] != s[r]:
                return check_delete(l+1,r) or check_delete(l,r-1)
            l+=1
            r-=1
        return True