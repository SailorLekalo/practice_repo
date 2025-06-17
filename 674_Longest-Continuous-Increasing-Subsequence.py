class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max_count = 1
        count = 1

        for i in range(len(nums) - 1):
            # break sequence
            if nums[i] >= nums[i+1]:
                max_count = max(max_count, count)
                count = 1
            else:
                count += 1

        return max(max_count, count)

# Runtime: O(N)
# Memory: O(1)

# Adapting for monotonous subsequence
class SolutionMonotonous(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max_count_inc = 1
        count_inc = 1

        max_count_dec = 1
        count_dec = 1

        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                count_dec += 1
            else:
                max_count_dec = max(max_count_dec, count_dec)
                count_dec = 1

            if nums[i] < nums[i+1]:
                count_inc += 1
            else:
                max_count_inc = max(max_count_inc, count_inc)
                count_inc = 1

        return max(max_count_inc, count_inc, max_count_dec, count_dec)
