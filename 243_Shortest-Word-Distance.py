class Solution(object):
    def distance_between_words(self, words: list[str], word1: str, word2: str) -> int:
        min_dist = len(words)
        # last current occurrence positions
        word1_idx = -1
        word2_idx = -1

        for idx, word in enumerate(words):
            # same word case
            if word == word1 == word2:
                if word1_idx != -1:
                    min_dist = min(min_dist, idx - word1_idx)
                word1_idx = idx
            elif word == word1:
                # update if we've already seen the other word
                if word2_idx != -1:
                    min_dist = min(min_dist, idx - word2_idx)
                word1_idx = idx
            elif word == word2:
                # update if we've already seen the other word
                if word1_idx != -1:
                    min_dist = min(min_dist, idx - word1_idx)
                word2_idx = idx

        return min_dist

# Runtime: O(N)
# Memory: O(1)
