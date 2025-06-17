class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        p1 = 0
        p2 = len(s) - 1

        # two pointers
        while p1 < p2:
            while not s[p1].isalnum():
                p1 += 1
                # to handle no alphanum symbol
                if p1 == len(s) - 1 == p2:
                    return True
            while not s[p2].isalnum():
                p2 -= 1

            # guaranteed alphanums
            if not (s[p1].lower() == s[p2].lower()):
                return False
            p1 += 1
            p2 -= 1

        return True

# Runtime: O(N)
# Memory: O(1)
