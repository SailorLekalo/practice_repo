class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        output = 0
        for left_pointer in range(0,len(word)):
            cumulative = 0
            while left_pointer+len(word)<=len(sequence):
                if sequence[left_pointer:left_pointer+len(word)]==word:
                    cumulative+=1
                    left_pointer+=len(word)
                else: 
                    output = max(output,cumulative)
                    cumulative = 0
                    left_pointer+=len(word)
            output = max(output,cumulative)
        return output
