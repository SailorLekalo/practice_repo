class Solution(object):
    def maxOperations(self, nums, k):
        nums.sort()
        pL = 0
        pR = len(nums)-1
        counter = 0
        while pL<pR:
            if nums[pL]+nums[pR] == k:
                counter+=1
                nums.pop(pR)
                nums.pop(pL)
                pR -=2
            elif nums[pL]+nums[pR] < k:
                pL+=1
            elif nums[pL]+nums[pR] > k:
                pR-=1
        return counter
