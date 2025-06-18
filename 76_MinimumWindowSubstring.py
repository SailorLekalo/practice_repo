class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """

        if len(t) == 0:
            return ""

        # goes first, finds valid substring - right border
        r_p = 0
        # follows until substring is no longer valid - left border
        l_p = 0

        start_window = 0
        min_window = len(s) + 1
        have_needed = 0

        # number of occurrences per letter needed
        need = {}
        # actual occurrences of needed letters currently
        curr = {}

        for c in t:
            if c in need:
                need[c] += 1
            else:
                need[c] = 1
                curr[c] = 0

        # right pointer finds letters
        while r_p < len(s):
            if s[r_p] in need:
                curr[s[r_p]] += 1

                # particular letter is present in amount needed
                if curr[s[r_p]] == need[s[r_p]]:
                    have_needed += 1

                while have_needed == len(need):
                    if s[l_p] in need:
                        # we're just breaking the valid substring
                        if curr[s[l_p]] == need[s[l_p]]:
                            curr[s[l_p]] -= 1
                            have_needed -= 1

                            # it was valid with left pointer letter
                            if r_p - l_p + 1 < min_window:
                                min_window = r_p - l_p + 1
                                start_window = l_p
                        else:
                            curr[s[l_p]] -= 1
                    l_p += 1

            r_p += 1

        # handle no valid substring was found
        if min_window == len(s) + 1:
            return ""

        return s[start_window : start_window+min_window]


"""
             r
ADOBECODEBANC | ABC
          l

2

3

curr
A: 1
B: 0
C: 1

need
A: 1
B: 1
C: 1
"""

# Runtime: O(N)
# Memory: O(|t|)
