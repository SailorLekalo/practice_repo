#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size());

        int prefix = 1;
        result[0] = 1;
        // fill result with all current-exclusive prefix products
        for (int i = 1; i < nums.size(); ++i) {
            prefix *= nums[i - 1];
            result[i] = prefix;
        }

        int postfix = 1;
        // at each num, multiply by current-exclusive postfix product
        for (int i = nums.size() - 2; i >= 0; --i) {
            postfix *= nums[i + 1];
            result[i] *= postfix;
        }

        return result;
    }
};

/*
        i
1 2 3 1 0 -3 3

0   -9

1 1 2 6 -54 0 0

*/

// Runtime: O(n)
// Memory: O(1) without result
