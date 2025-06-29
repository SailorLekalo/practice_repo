class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        This solution is not optimal by time, but it is optimal for space
        """
        
        n = 0
        i = 0
        # n is counter for number of replacements
        while n < len(nums):
            temp = nums[i]
            j = (i - k) % len(nums)
            while j != i:
                nums[(j + k) % len(nums)] = nums[j]
                j = (j - k) % len(nums)
                n += 1
            nums[(i + k) % len(nums)] = temp
            n += 1
            i += 1
