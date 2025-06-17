class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """

        max_dist = 0
        last_person_idx = -1

        for i, seat in enumerate(seats):
            if seat == 1:
                # handle empty seats in the beginning
                if last_person_idx == -1:
                    max_dist = i
                else:
                    # always placing in the middle
                    max_dist = max(max_dist, (i - last_person_idx) // 2)

                last_person_idx = i

        # handle empty seats in the end
        return max(max_dist, len(seats) - last_person_idx - 1)

# Runtime: O(N)
# Memory: O(1)
