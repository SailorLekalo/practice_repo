class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i = 0
        zeros = nums.count(0)
        while i < len(nums):
            if i == len(nums)-zeros:
                break
            elif nums[i] == 0:
                nums.pop(i)
                nums.append(0)
            else:
                i +=1
        
