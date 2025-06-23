class Solution:
    def longestPalindrome(self, s: str) -> str:
        center = 0
        s = " ".join(list(s))
        longest = s[0]
        while center<len(s):
            i = 0
            while center-i-1>=0 and center+i+1<len(s) and s[center-i-1] == s[center+i+1]:
                i+=1
            if len(longest)<len(s[center-i:center+i+1].strip()):
                longest = s[center-i:center+i+1].strip()
            center+=1
        return ''.join(longest.split())
