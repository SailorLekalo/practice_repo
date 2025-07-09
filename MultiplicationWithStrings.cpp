/*

Дано число в виде строки num_str и целое число-множитель n.
Нужно вернуть строку, представляющую результат умножения num_str * n.

Пример: num_str = "123", n = 9
Ответ: "1107"

 */

#include <algorithm>
#include <string>

std::string solve(std::string num, int n) {
    if (n == 0 || num == "0") {
        return "0";
    }

    std::string s = "";
    int carry = 0;

    // go from last to first digit
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        int product = digit * n + carry;

        // new digit for result
        s += std::to_string(product % 10);
        carry = product / 10;
    }

    // add all carries left one-by-one (because of reverse)
    while (carry > 0) {
        s += std::to_string(carry % 10);
        carry /= 10;
    }

    std::reverse(s.begin(), s.end());
    return s;
}

// Runtime: O(num.length())
// Memory: O(num.length())
