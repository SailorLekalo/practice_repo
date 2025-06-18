class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        profit = 0

        # just add profit for each increasing interval
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]

        return profit

"""
[7,1,5,3,6,4]
[1, 5] = 4
[3, 6] = 3

[1,2,3,4,5]
[1, 5] = 4
1-2 = 1
2-3 = 1
3-4 = 1
4-5 = 1
"""

# Runtime: O(N)
# Memory: O(1)
