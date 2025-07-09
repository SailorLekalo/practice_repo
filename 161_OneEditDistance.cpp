#include <algorithm>
#include <string>

class Solution {
public:
    bool isOneEditDistance(std::string s, std::string p) {
        int n = s.length();
        int m = p.length();

        if (std::abs(n - m) > 1) {
            return false;
        }

        // just for convenience, make s always not bigger than p
        if (n > m) {
            return isOneEditDistance(p, s);
        }

        for (int i = 0; i <= n; i++) {
            if (s[i] != p[i]) {
                if (n == m) {
                    // check that this was the only replacement
                    return s.substr(i + 1) == p.substr(i + 1);
                }
                // or deletion
                return s.substr(i) == p.substr(i + 1);
            }
        }

        return n != m;
    }
};

// Runtime: O(min string length)
// Memory: O(1) without substr (use two pointers), o.w. O(N)
