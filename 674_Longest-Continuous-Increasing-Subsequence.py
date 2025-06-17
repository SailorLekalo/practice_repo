class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max_count = 1
        count = 1

        for i in range(len(nums) - 1):
            if nums[i] >= nums[i+1]:
                max_count = max(max_count, count)
                count = 1
            else:
                count += 1

        return max(max_count, count)

# Runtime: O(N)
# Memory: O(1)
