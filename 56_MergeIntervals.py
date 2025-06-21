class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """

        # sort by start interval element
        intervals.sort(key = lambda i : i[0])
        read_p = 1
        write_p = 0

        while read_p < len(intervals):
            if intervals[read_p][0] <= intervals[write_p][1]:
                # consider max end point to within one interval
                intervals[write_p][1] = max(intervals[write_p][1], intervals[read_p][1])
            else:
                write_p += 1
                intervals[write_p] = intervals[read_p]

            read_p += 1

        # get rid of "waste" after merging
        for i in range(read_p - write_p - 1):
            intervals.pop()

        return intervals


"""
[1,3],[2,6],[20,24],[24,25],[8,10],[15,18]

                              r
[1,6],[20,25],[20,24],[24,25]
       w

                                      r
[1,6],[8,10],[15,18],[20,25],[20,24],[24,25]
                      w
"""

# Runtime: O(N)
# Memory: O(1)
