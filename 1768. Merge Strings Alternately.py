class Solution(object):
    def mergeAlternately(self, word1, word2):
        outstr = ""
        for i in range(min(len(word1),len(word2))):
            outstr+=word1[i]+word2[i]
        if len(word2)>len(word1):
            outstr+=word2[len(word1):]
        else:
            outstr+=word1[len(word2):]
        return(outstr)
