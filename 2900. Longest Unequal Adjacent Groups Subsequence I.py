class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        nex = groups[0]
        indexes = [0]
        for i in range(len(groups)):
            if groups[i] == 1-nex:
                nex = 1-nex
                indexes.append(i)
        output_array = []
        for i in indexes:
            output_array.append(words[i])
        return output_array
