#include <string>
#include <vector>

class Solution {
    std::vector<std::string> result;

public:
    // each step, decide if '('/')' can be added
    void backtrack(std::string& curr_string, int open_cnt, int close_cnt, int n) {
        if (curr_string.length() == n * 2) {
            result.push_back(curr_string);
            return;
        }

        if (open_cnt < n) {
            // can add '('
            curr_string.push_back('(');
            backtrack(curr_string, open_cnt + 1, close_cnt, n);
            // delete added char to be able to try another way
            curr_string.pop_back();
        }

        if (close_cnt < open_cnt) {
            // can add ')'
            curr_string.push_back(')');
            backtrack(curr_string, open_cnt, close_cnt + 1, n);
            curr_string.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::string current_string = "";
        backtrack(current_string, 0, 0, n);
        return result;
    }
};

// Runtime: O(4^n)
// Memory: O(n)
