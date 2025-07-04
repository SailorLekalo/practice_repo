#include <vector>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        // hash tables for number of occurences of each letter
        std::vector<int> s1_map(26);
        std::vector<int> curr_window(26);

        for (int i = 0; i < 26; ++i) {
            s1_map[i] = 0;
            curr_window[i] = 0;
        }
        // number of letters for which occurences amounts match exactly
        int matches = 26;

        for (int i = 0; i < s1.length(); ++i) {
            if (++s1_map[s1[i] - 'a'] == 1)
                // mismatch only when the letter is added to s1 hash for the first time
                --matches;
        }

        for (int i = 0; i < s1.length(); ++i) {
            ++curr_window[s2[i] - 'a'];
            if (s1_map[s2[i] - 'a'] == curr_window[s2[i] - 'a']) {
                ++matches;
            } else if (curr_window[s2[i] - 'a'] - 1 == s1_map[s2[i] - 'a']) {
                // mismatch only if this was a match previously
                --matches;
            }
        }

        // to handle equal lengths of s1 and s2
        if (matches == 26) {
            return true;
        }

        int l_p = 0;
        // r_p reads new letters - end of window, l_p forgets old letters - start of window
        for (int r_p = s1.length(); r_p < s2.length(); ++r_p, ++l_p) {
            ++curr_window[s2[r_p] - 'a'];
            if (s1_map[s2[r_p] - 'a'] == curr_window[s2[r_p] - 'a']) {
                ++matches;
            } else if (curr_window[s2[r_p] - 'a'] - 1 == s1_map[s2[r_p] - 'a']) {
                // mismatch only if this was a match previously
                --matches;
            }

            --curr_window[s2[l_p] - 'a'];
            if (s1_map[s2[l_p] - 'a'] == curr_window[s2[l_p] - 'a']) {
                ++matches;
            } else if (curr_window[s2[l_p] - 'a'] + 1 == s1_map[s2[l_p] - 'a']) {
                --matches;
            }

            // window is made from all s1 letters occuring the exact needed time
            if (matches == 26) {
                return true;
            }
        }

        return false;
    }
};

/*

ab

      l
eidbaooo
       r

a   1
b   1
... 0

a   1
b   1
d   0
e   0
i   0

match   22

*/

// Runtime: O(s2.length())
// Memory: O(1)

