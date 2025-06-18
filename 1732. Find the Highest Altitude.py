class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        king = 0
        dot = 0
        for i in gain:
            dot+=i
            if dot>king:
                king = dot
        return(king)
        
