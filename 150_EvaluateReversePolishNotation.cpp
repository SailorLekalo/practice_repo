#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        // num -> push to stack, operator -> apply to last two nums
        std::stack<long long> s;
        for (const std::string& t : tokens) {
            // check for all possible operands first
            if (t == "+") {
                long long o2 = s.top();
                s.pop();
                long long o1 = s.top();
                s.pop();
                // put result to stack
                s.push(o1 + o2);
            } else if (t == "-") {
                // order of operands matters
                long long o2 = s.top();
                s.pop();
                long long o1 = s.top();
                s.pop();
                s.push(o1 - o2);
            } else if (t == "*") {
                long long o2 = s.top();
                s.pop();
                long long o1 = s.top();
                s.pop();
                s.push(o1 * o2);
            } else if (t == "/") {
                long long o2 = s.top();
                s.pop();
                long long o1 = s.top();
                s.pop();
                s.push(o1 / o2);
            } else {
                // token is num
                s.push(std::stoll(t));
            }
        }

        return s.top();
    }
};

// Runtime: O(n)
// Memory: O(n)
