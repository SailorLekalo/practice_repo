class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // store indices of revealed elems to access if they give target difference
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (map.count(diff)) {
                // not to sum element with itself
                if (map[diff] != i) {
                    return {map[diff], i};
                }
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

/*
[2,7,11,2,4] 15

2   3
7   1
11  2
4   4
*/

// Runtime: O(n)
// Memory: O(n)
