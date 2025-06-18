class Solution(object):
    def reverseWords(self, s):
        s = filter(None,s.split(' '))
        return(' '.join(reversed(s)))
        
