class Solution(object):
    def gcdOfStrings(self, str1, str2):
        for i in range(min(len(str1), len(str2)), 0, -1):
            if len(str1)%i==0 and len(str2)%i==0:
                t1=len(str1)/i
                t2=len(str2)/i 
                if (str1[:i]*t1==str1) and (str1[:i]*t2==str2):
                    return str2[:i]
        return ''
                
        return(out)
