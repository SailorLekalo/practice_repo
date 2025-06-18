class Solution(object):
    def maxVowels(self, s, k):
        vowels = list("aeiou")
        temp = s[0:k]
        counter = sum([temp.count(j) for j in vowels])
        king = counter
        for i in range(0,len(s)-k):
            if s[0+i] in vowels:
                counter-=1
            if s[k+i] in vowels:
                counter+=1
            king = max(king,counter)
        return king
        
