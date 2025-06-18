class Solution(object):
    def reverseVowels(self, s):
        vowels = set("aeiouAEIOU")
        t = []
        for i in s:
            if i in vowels:
                t.append(i)
        print(t)
        t.reverse()
        ct = 0
        out = ""
        for a in s:
            if a in vowels:
                out+=t[ct]
                ct+=1
            else:
                out+=a
        return(out)


        
