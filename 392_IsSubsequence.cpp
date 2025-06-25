class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_p = 0, t_p = 0;
        while (t_p < t.length()) {
            // end of string s -- all letters consecutively found
            if (s_p == s.length()) {
                return true;
            }

            // letter occurrence found -- now search for the next letter
            if (s[s_p] == t[t_p]) {
                ++s_p;
            }
            ++t_p;
        }

        if (s_p == s.length()) {
            return true;
        }
        return false;
    }
};

// Runtime: O(n)
// Memory: O(1)
