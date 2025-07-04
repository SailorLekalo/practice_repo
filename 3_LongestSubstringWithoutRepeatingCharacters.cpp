#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = 0;
        int l_p = 0;

        // store indices of last occurrences of each letter
        std::unordered_map<char, int> char_index;
        for (int r_p = 0; r_p < s.size(); ++r_p) {
            char curr = s[r_p];

            if (char_index.count(curr) && char_index[curr] >= l_p) {
                // the letter already exists within the current window
                length = std::max(r_p - l_p, length);
                l_p = char_index[curr] + 1;
            }

            char_index[curr] = r_p;
        }

        // consider the last valid window
        return std::max((int)s.size() - l_p, length);
    }
};

/*

   r
abcabcbb
l

*/

// Runtime: O(n)
// Memory: O(1)
