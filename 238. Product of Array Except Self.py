class Solution(object):
    def productExceptSelf(self, nums):
        ln = len(nums)
        prefix_list = [nums[0]]
        suffix_list = [nums[ln-1]]
        for i in range(1,ln):
            print(nums[ln-i-1],suffix_list[0])
            prefix_list.append(nums[i]*prefix_list[i-1])
            suffix_list.insert(0,nums[ln-i-1]*suffix_list[0])
        out = [suffix_list[1]]
        for i in range(1,len(nums)-1):
            out.append(prefix_list[i-1]*suffix_list[i+1])
        out.append(prefix_list[len(prefix_list)-2])
        return(out)
        
