class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        k = 0
        for i in range(len(s)):
            a = t[k:].find(s[i])
            if a != -1:
                k += a+1
            else:
                return(False)
        return(True)
