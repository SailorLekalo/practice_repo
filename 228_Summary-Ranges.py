class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """

        # sort nums when given unsorted

        result = []
        nums_len = len(nums)
        # 0 <= nums.length <= 20
        if nums_len == 0:
            return result

        num1 = nums[0]
        for idx in range(1, nums_len):
            # break range [num1, prev elem]
            if nums[idx] != nums[idx-1] + 1:
                prev = nums[idx-1]
                elem = str(num1)
                if num1 == prev:
                    result.append(elem)
                else:
                    result.append(elem + "->" + str(prev))

                num1 = nums[idx]

        # handle last range [num1, last elem]
        elem = str(num1)
        if num1 == nums[-1]:
            result.append(elem)
        else:
            result.append(elem + "->" + str(nums[-1]))

        return result

"""
[0,2,3,4,6,8,9]
0 2->4 6 8->9
"""

# Runtime: O(N)
# Memory: O(1) / O(N) if counting result list
