class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = []
        # count entries of each number over smaller list
        entries = {}
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)

        for num in nums1:
            entries[num] = entries.get(num, 0) + 1
        for num in nums2:
            # add num to result if there is one count for it from the first list
            if entries.get(num, 0) > 0:
                res.append(num)
                entries[num] -= 1
        return res

# Runtime: O(n+m)
# Memory: O(min(n,m))

"""
1 2 2 1
2 2

1: 2
2: 2 1 0

2 2
"""
