# --- 1

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        curr = 0

        for i in range(len(nums)):
            # swap to bring zeros to end
            if nums[i] != 0:
                nums[i], nums[curr] = nums[curr], nums[i]
                curr += 1


"""
[0,1,0,3,12]
[1,3,12,0,0]
"""

# Runtime: O(N)
# Memory: O(N)

# --- 2

nums = list(map(int,input().split()))
#1 8 0 0 0 9 0 8
zero_index = 999999999999
for i in range(len(nums)):
    if nums[i]==0 and i<zero_index:
        zero_index = i
    elif nums[i]!=0 and i>zero_index:
        nums[i],nums[zero_index] = nums[zero_index],nums[i]
        zero_index+=1
print(nums)

# Runtime: O(N)
# Memory: O(N)

# --- 3

class Solution3:
    def moveZeroes(self, nums: list[int]) -> None:
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

# Runtime: O(N^2) because of pop operation
# Memory: O(N)
