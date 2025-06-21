class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        open_brackets = "([{"
        closed_to_open = {
            ")": "(",
            "]": "[",
            "}": "{",
        }

        curr = []
        for br in s:
            if br in open_brackets:
                curr.append(br)
            elif not curr or curr.pop() != closed_to_open[br]:
                return False

        return not curr


"""
()[]{}
([])   
([})   
"""

# Runtime: O(N)
# Memory: O(N)
