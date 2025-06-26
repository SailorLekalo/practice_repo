class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto& elem : nums) {
            // XOR is associative, x XOR x = 0, x XOR 0 = x
            result = result ^ elem;
        }
        return result;
    }
};

/*
[2,2,1]
(2 | 2) | 1
*/

// Runtime: O(n)
// Memory: O(1)
