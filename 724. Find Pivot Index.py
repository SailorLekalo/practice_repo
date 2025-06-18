class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        all_sum = sum(nums)
        a = 0
        b = all_sum
        for i in range(0,len(nums)):
            if i-1>=0:
                a += nums[i-1]
            b -= nums[i]
            print(a,b)
            if a == b:
                return(i)

        return (-1)

        
