import collections

class RecentCounter(object):

    def __init__(self):
        self.recent_calls = collections.deque()


    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.recent_calls.append(t)
        # forget calls came more than 3000 seconds ago
        while t - self.recent_calls[0] > 3000:
            self.recent_calls.popleft()
        return len(self.recent_calls)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)

# Runtime: O(1)
# Memory: O(N)

