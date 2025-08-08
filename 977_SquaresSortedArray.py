class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # write result from end
        res = [0] * len(nums)
        wr = len(nums) - 1
        l = 0
        r = len(nums) - 1

        while l != r:
            # compare edge values to find current max
            if abs(nums[l]) > abs(nums[r]):
                res[wr] = nums[l] ** 2
                l += 1
            else:
                res[wr] = nums[r] ** 2
                r -= 1
            wr -= 1
        # last min elem
        res[wr] = nums[l] ** 2
        return res

# Runtime: O(n)
# Memory: O(n) res
