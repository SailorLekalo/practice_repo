#include <string>
#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int read = 0;
        // position to put letter / num of occurrences in-place
        int write = 0;
        int n = chars.size();

        while (read < n) {
            char curr = chars[read];
            int count = 0;

            while (read < n && chars[read] == curr) {
                ++read;
                ++count;
            }

            chars[write++] = curr;
            if (count > 1) {
                // handle parsing two-more digit number of occurences to add as chars
                std::string count_str = std::to_string(count);
                for (char c : count_str) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};

// Runtime: O(N)
// Memory: O(1)
