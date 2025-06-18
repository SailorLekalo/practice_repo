class Solution:
    def findMaxAverage(self, nums: List[int], k: int):
        avg = sum(nums[0:k])
        clic = avg 
        for i in range(k,len(nums)):
            clic = clic+ nums[i]-nums[i-k]
            if clic>avg:
                avg = clic
        return(avg/k)
