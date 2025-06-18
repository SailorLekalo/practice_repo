class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        a = max(candies)
        out = []
        for i in candies:
            if i+extraCandies >= a:
                out.append(True)
            else:
                out.append(False)
        return(out)
        
