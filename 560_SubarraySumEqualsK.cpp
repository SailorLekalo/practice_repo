#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int result = 0;
        long long sum = 0;
        // num of occurrences of each prefix sum
        std::unordered_map<int, long long> occur;

        occur[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (occur.find(sum - k) != occur.end()) {
                // found prefix sum difference giving exactly the range of the needed sum
                result += occur[sum - k];
            }

            ++occur[sum];
        } 

        return result;
    }
};

/*

1 2 1 0 2 3 6
      l

3

4

res 3

0   1
1   1
3   1
4   2

*/

// Runtime: O(n)
// Memory: O(n)
