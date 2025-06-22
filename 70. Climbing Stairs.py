class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: return(1)

        dp = [0]*(n+1)
        dp[0]=1
        for i in range(1,len(dp)):
            for step in range(1,3):
                dp[i] += dp[i-step]
        return (dp[-1])
