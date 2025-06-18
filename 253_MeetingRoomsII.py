#Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    def minMeetingRooms(self, intervals: list[Interval]) -> int:
        starts = sorted([i.start for i in intervals])
        ends = sorted([i.end for i in intervals])

        max_rooms = 0
        curr = 0
        p1 = 0
        p2 = 0

        while p1 < len(starts) and p2 < len(ends):
            if starts[p1] < ends[p2]:
                curr += 1
                max_rooms = max(curr, max_rooms)
                p1 += 1

            elif starts[p1] > ends[p2]:
                curr -= 1
                p2 += 1

            else:
                p1 += 1
                p2 += 1

        return max_rooms


"""
[(0,40),(5,10),(15,20)]
0----------------------40
   5----10
        10---20
0 5 10
10 20 40
2
"""

# Runtime: O(N logN) (for sorting)
# Memory: O(N)
